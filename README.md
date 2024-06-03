# DFSMN_Onnx
An implementation of DFSMN onnx model using C++

# Environment
Ubuntu Linux 22.04

# Build the project
`mkdir build && cd build`

`// cmake .. -DONNXRUNTIME_DIR=/home/onnx-test/onnx/onnxruntime-linux-x64-1.14.0`

`cmake .. -DONNXRUNTIME_DIR=/path/to/onnxruntime`

`make`

# Project Structure is as follows:(under active development)
Onnx

|___ bin

&nbsp;&nbsp;&nbsp;&nbsp;|___ inference.cpp

|___ src


&nbsp;&nbsp;&nbsp;&nbsp;|___ model.cpp

&nbsp;&nbsp;&nbsp;&nbsp;|___ paraformer.cpp

|___ include

&nbsp;&nbsp;&nbsp;&nbsp;|___ inference.h

&nbsp;&nbsp;&nbsp;&nbsp;|___ model.h

&nbsp;&nbsp;&nbsp;&nbsp;|___ paraformer.h

&nbsp;&nbsp;&nbsp;&nbsp;|___ all.h

I use inference.cpp as the main entrance, accessing other fucntions(currently initialize & query).

Updates:
1. 2024/6/3  Add **paraformer** module, a subclass of **Model**, where the initialization of the Ort session takes place. The constructed Onnx model is wrapped within class **Model**. The query of input takes place after initialization.
