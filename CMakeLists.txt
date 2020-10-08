cmake_minimum_required(VERSION 3.17)
project(serum)

set(CMAKE_CXX_STANDARD 17)

# Get files
file(GLOB_RECURSE ENGINE_SRC
        "src/*.h"
        "src/*.cpp"
        )

add_executable(serum ${ENGINE_SRC})

# glfw : window and gl library
add_subdirectory(${CMAKE_SOURCE_DIR}/vendor/glfw)
target_link_libraries(serum PUBLIC glfw)

# imgui : immidiate mode gui
file(GLOB_RECURSE IMGUI_SRC
        "vendor/imgui/*.h"
        "vendor/imgui/*.cpp"
        )

target_include_directories(serum PUBLIC vendor/imgui vendor/imgui/examples)