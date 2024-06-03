include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${ONNXRUNTIME_DIR}/include)

add_executable(inference "inference.cpp")
target_link_libraries(inference dfsmn_onnx)
