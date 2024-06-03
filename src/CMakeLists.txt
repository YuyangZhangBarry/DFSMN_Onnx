file(GLOB files1 "*.cpp")
set(files ${files1})


add_library(dfsmn_onnx SHARED ${files})


include_directories(${ONNXRUNTIME_DIR}/include)

include_directories(${CMAKE_SOURCE_DIR}/include)


target_link_libraries(dfsmn_onnx PUBLIC onnxruntime)
