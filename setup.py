from skbuild import setup
from setuptools import find_packages

setup(
    name="m5gfx",
    version="0.1",
    packages=find_packages(),             # 自动发现 m5gfx 目录
    cmake_install_dir="m5gfx",            # <-- 安装 .so 文件到 m5gfx 包目录
    cmake_args=[
        "-DLGFX_SDL=ON"
    ],
    include_package_data=True,            # 确保 CMake 安装的东西被包含
)
