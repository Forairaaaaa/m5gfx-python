cmake_minimum_required(VERSION 3.15)
project(m5gfx_bind LANGUAGES C CXX)

# 设定 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 加入 pybind11（推荐用子模块或 pip 安装）
add_subdirectory(dependencies/pybind11)

add_definitions(-DLGFX_SDL)

# 包含 M5GFX 的源文件
file(GLOB Target_Files RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} CONFIGURE_DEPENDS 
    dependencies/M5GFX/src/lgfx/Fonts/efont/*.c
    dependencies/M5GFX/src/lgfx/Fonts/IPA/*.c
    dependencies/M5GFX/src/lgfx/utility/*.c
    dependencies/M5GFX/src/lgfx/v1/*.cpp
    dependencies/M5GFX/src/lgfx/v1/misc/*.cpp
    dependencies/M5GFX/src/lgfx/v1/panel/Panel_Device.cpp
    dependencies/M5GFX/src/lgfx/v1/panel/Panel_FrameBufferBase.cpp
    dependencies/M5GFX/src/lgfx/v1/platforms/sdl/*.cpp
)

# 创建 Python 模块
pybind11_add_module(m5gfx m5gfx_bind.cpp ${Target_Files})

# 加入 include 目录
target_include_directories(m5gfx PRIVATE dependencies/M5GFX/src/)

# 根据平台配置 SDL2
if (CMAKE_SYSTEM_NAME MATCHES "Linux")
    find_package(SDL2 REQUIRED)
    target_include_directories(m5gfx PRIVATE ${SDL2_INCLUDE_DIRS})
    target_link_libraries(m5gfx PRIVATE ${SDL2_LIBRARIES} pthread)
elseif (CMAKE_SYSTEM_NAME MATCHES "Windows")
    target_include_directories(m5gfx PRIVATE "C:/SDL2/include")
    target_link_libraries(m5gfx PRIVATE "C:/SDL2/lib/x64/SDL2.lib")
elseif (CMAKE_SYSTEM_NAME MATCHES "Darwin")
    find_package(SDL2 REQUIRED)
    target_link_libraries(m5gfx PRIVATE SDL2::SDL2)
endif()

# 安装 Python 模块（告诉 CMake 哪个是最终输出）
install(TARGETS m5gfx
        LIBRARY DESTINATION .)
