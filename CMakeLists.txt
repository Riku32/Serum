cmake_minimum_required(VERSION 3.17)
project(serum)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)
set(VENDOR_DIR ${CMAKE_SOURCE_DIR}/vendor)

# Get files
file(GLOB_RECURSE ENGINE_SRC
        "${SOURCE_DIR}/*.h"
        "${SOURCE_DIR}/*.cpp"
        )

add_executable(serum ${ENGINE_SRC})

file(COPY assets DESTINATION .)

# -- SET VARIABLES --

# Get the current working branch
execute_process(
        COMMAND git rev-parse --abbrev-ref HEAD
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        OUTPUT_VARIABLE GIT_BRANCH
        OUTPUT_STRIP_TRAILING_WHITESPACE
)

# Get the latest abbreviated commit hash of the working branch
execute_process(
        COMMAND git log -1 --format=%h
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        OUTPUT_VARIABLE GIT_COMMIT_HASH
        OUTPUT_STRIP_TRAILING_WHITESPACE
)

# Set variables
add_definitions("-DGIT_COMMIT_HASH=${GIT_COMMIT_HASH}")
add_definitions("-DGIT_BRANCH=${GIT_BRANCH}")

# Compile version file
configure_file(
        ${SOURCE_DIR}/version.h.in
        ${CMAKE_BINARY_DIR}/generated/version.h
)

include_directories(${CMAKE_BINARY_DIR}/generated)

# -- INITIALIZE LIBRARIES --

# glfw : window library
add_subdirectory(${VENDOR_DIR}/glfw)
target_link_libraries(serum PUBLIC glfw)
target_include_directories(serum PUBLIC ${VENDOR_DIR}/glfw/include/GLFW)

# imgui : immidiate mode gui
set(IMGUI_DIR ${VENDOR_DIR}/imgui)

file(GLOB IMGUI_SOURCES ${IMGUI_DIR}/*.cpp)
file(GLOB IMGUI_HEADERS ${IMGUI_DIR}/*.h)

add_library(imgui STATIC ${IMGUI_SOURCES} ${IMGUI_HEADERS})
add_definitions(-DIMGUI_IMPL_OPENGL_LOADER_GLAD)

target_link_libraries(serum PUBLIC imgui)
target_include_directories(serum PUBLIC ${IMGUI_DIR})

# spdlog : logging library
add_subdirectory(${VENDOR_DIR}/spdlog)
target_link_libraries(serum PUBLIC spdlog::spdlog)

# glad : gl library
set(GLAD_DIR ${VENDOR_DIR}/Glad)
add_library(glad ${GLAD_DIR}/src/glad.c)
target_include_directories(glad PUBLIC ${GLAD_DIR}/include)
target_include_directories(serum PUBLIC ${GLAD_DIR}/include)
target_link_libraries(serum PUBLIC glad ${CMAKE_DL_LIBS})

# stb : single-file public domain libraries for C/C++
target_include_directories(serum PUBLIC ${VENDOR_DIR}/stb)