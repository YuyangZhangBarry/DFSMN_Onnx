cmake_minimum_required(VERSION 3.16)

project(DFSMNOnnx)


# set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_STANDARD 14 CACHE STRING "The C++ version to be used.")
#set(CMAKE_POSITION_INDEPENDENT_CODE ON)
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


# for onnxruntime
link_directories(${ONNXRUNTIME_DIR}/lib)
#link_directories(${FFMPEG_DIR}/lib)

# 添加头文件目录
include_directories(${PROJECT_SOURCE_DIR}/include)

add_subdirectory(src)
add_subdirectory(bin)

