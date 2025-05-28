import re
from pathlib import Path
from collections import defaultdict

HEADER_PATH = Path("dependencies/M5GFX/src/lgfx/v1/LGFXBase.hpp")

# 过滤规则：跳过模板、宏、某些函数
SKIP_PATTERNS = [
    r'template\s*<',                 # 忽略模板
    r'drawPixel\s*<',               # 忽略 drawPixel<T>
    r'drawSmoothLine\s*<',
    r'drawFastVLine\s*<',
    r'drawFastHLine\s*<',
]


def should_skip(line):
    return any(re.search(pat, line) for pat in SKIP_PATTERNS)


def extract_class_body(content, class_name="LGFXBase"):
    start = re.search(rf'class\s+{class_name}\b', content)
    if not start:
        return ""

    pos = start.end()
    brace_level = 0
    body = []
    inside = False

    while pos < len(content):
        c = content[pos]
        if c == '{':
            brace_level += 1
            inside = True
        elif c == '}':
            brace_level -= 1
            if brace_level == 0 and inside:
                break
        if inside:
            body.append(c)
        pos += 1

    return ''.join(body)


def extract_functions(class_body):
    # 匹配成员函数：返回值 函数名(参数列表) const?;
    func_pattern = re.compile(r'''
        (?:[\w:<>&*\s]+)       # 返回类型
        \s+(\w+)               # 函数名
        \s*\(([^)]*)\)         # 参数列表
        \s*(const)?\s*[;{]     # 可选 const、分号或开始花括号
    ''', re.VERBOSE)

    return func_pattern.findall(class_body)


def is_color_template(arg: str) -> bool:
    return 'T' in arg and 'color' in arg


def get_cpp_signature(name, args_str, const):
    args = [a.strip() for a in args_str.split(',')] if args_str.strip() else []
    args_fmt = ', '.join(args)
    if const:
        return f'void (LGFX::*)({args_fmt}) const'
    else:
        return f'void (LGFX::*)({args_fmt})'


def generate_def_lines(functions):
    grouped = defaultdict(list)
    for name, args, const in functions:
        grouped[name].append((args, const))

    def_lines = []
    for name, overloads in grouped.items():
        for i, (args, const) in enumerate(overloads):
            arg_list = [a.strip()
                        for a in args.split(',')] if args.strip() else []
            arg_names = [f'arg{i}' for i in range(len(arg_list))]

            # 检查是否是颜色模板函数
            if any(is_color_template(arg) for arg in arg_list):
                def extract_type(arg: str) -> str:
                    # 去掉变量名，只保留类型
                    # 例如 "int32_t x" -> "int32_t"
                    return ' '.join(arg.split()[:-1]) if len(arg.split()) > 1 else arg

                param_list = ", ".join(
                    f"{'uint32_t' if is_color_template(arg) else extract_type(arg)} {name}"
                    for arg, name in zip(arg_list, arg_names)
                )

                arg_pass = ", ".join(arg_names)
                def_lines.append(
                    f'    .def("{name}", [](LGFX& self, {param_list}) {{ self.{name}({arg_pass}); }})'
                )
            else:
                # 正常函数绑定
                if len(overloads) == 1:
                    def_lines.append(f'    .def("{name}", &LGFX::{name})')
                else:
                    cpp_sig = get_cpp_signature(name, args, const)
                    def_lines.append(
                        f'    .def("{name}", static_cast<{cpp_sig}>(&LGFX::{name}))'
                    )

    return def_lines


def main():
    content = HEADER_PATH.read_text(encoding='utf-8')
    class_body = extract_class_body(content)
    # print(class_body)

    lines = class_body.splitlines()

    # 预过滤：剔除注释行、空行、模板行
    function_lines = [line.strip()
                      for line in lines if line.strip() and not should_skip(line)]

    class_body_filtered = "\n".join(function_lines)
    funcs = extract_functions(class_body_filtered)

    print('py::class_<LGFX>(m, "M5GFX")')
    for line in generate_def_lines(funcs):
        print(line)
    print("    ;")


if __name__ == "__main__":
    main()
