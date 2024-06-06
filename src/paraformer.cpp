#include <all.h>

namespace dfsmn{

    Paraformer::Paraformer()
    :env_(ORT_LOGGING_LEVEL_ERROR, "paraformer"),session_options_{} {
    }

    void Paraformer::Init(const char *path, int thread_num){

        session_options_.SetIntraOpNumThreads(thread_num);
        m_session_ = std::make_unique<Ort::Session>(env_, path, session_options_);

    }

    void Paraformer::Query(){

        Ort::AllocatorWithDefaultOptions allocator;
        auto input_num_ = m_session_->GetInputCount();
        std::vector<const char*> input_names_;
        for (size_t i = 0; i < input_num_; i++) {
            std::string input_name = m_session_->GetInputNameAllocated(i, allocator).get();
            input_names_.push_back(input_name.data());
            std::cout << "input name :" << input_name << std::endl;
            // dims
            Ort::TypeInfo type_info = m_session_->GetInputTypeInfo(i);
            auto tensor_info = type_info.GetTensorTypeAndShapeInfo();
            auto input_shape_ = tensor_info.GetShape();
            std::cout << "input dims: ";
            for (const auto& dim : input_shape_) {
                std::cout << dim << " ";
            }
            std::cout << std::endl;
            // dtype
            std::cout << "dtype: " << tensor_info.GetElementType() << std::endl;

        }

        // output tensor

        auto output_num_ = m_session_->GetOutputCount();
        std::vector<const char*> output_names_;
        for (size_t i = 0; i < output_num_; i++) {
            std::string output_name = m_session_->GetOutputNameAllocated(i, allocator).get();
            output_names_.push_back(output_name.data());
            std::cout << "output name :" << output_name << std::endl;
            // dims
            Ort::TypeInfo type_info = m_session_->GetOutputTypeInfo(i);
            auto tensor_info = type_info.GetTensorTypeAndShapeInfo();
            auto output_shape_ = tensor_info.GetShape();
            std::cout << "output dims: ";
            for (const auto& dim : output_shape_) {
                std::cout << dim << " ";
            }
            std::cout << std::endl;
            // dtype
            std::cout << "dtype: " << tensor_info.GetElementType() << std::endl;

        }

    }

    void Paraformer::RandomInput(int64_t batch_size, int64_t frame_num){
        // Get relative info 
        Ort::AllocatorWithDefaultOptions allocator;
        auto input_num = m_session_->GetInputCount();

        for (size_t i = 0; i < input_num; i++) {
            // dims
            Ort::TypeInfo input_type_info = m_session_->GetInputTypeInfo(i);
            auto input_tensor_info = input_type_info.GetTensorTypeAndShapeInfo();
            auto input_shape_ = input_tensor_info.GetShape();
            std::cout << "input dims: ";
            for (const auto& dim : input_shape_) {
                std::cout << dim << " ";
            }
            std::cout << std::endl;
        }

        // Create input 
        // DFSMN onnx model input shape: -1,-1,120   output shape: -1,-1,961
        std::cout << "Creating random input of size : [" << batch_size << ", " << frame_num << ", "<< "120]" << std::endl;

        // DFSMN model input & output names are: 
        std::vector<const char*> input_names = {"input"}; 
        std::vector<const char*> output_names = {"output"}; 

        std::vector<int64_t> input_shape = {batch_size, frame_num, 120};
        std::vector<float> input_data(std::accumulate(input_shape.begin(), input_shape.end(), 1, std::multiplies<int64_t>()));  
        std::fill(input_data.begin(), input_data.end(), 100.0f);  // This is where the magic happens
        Ort::MemoryInfo memory_info = Ort::MemoryInfo::CreateCpu(OrtArenaAllocator, OrtMemTypeDefault);  
        Ort::Value input_tensor = Ort::Value::CreateTensor<float>(memory_info, input_data.data(), input_data.size(), input_shape.data(), input_shape.size());   

        // run 
       std::vector<Ort::Value> outputs = m_session_->Run(Ort::RunOptions{nullptr}, 
                                        input_names.data(), 
                                        &input_tensor,
                                        1, 
                                        output_names.data(),
                                        1);

        // Query the output
        float* output = outputs[0].GetTensorMutableData<float>();
        auto output_tensor_info = outputs[0].GetTensorTypeAndShapeInfo();

        auto output_shape = output_tensor_info.GetShape();
        std::cout << "output shape: " ;
        for (const auto &dim : output_shape){
            std::cout << dim << " ";
        }
        std::cout << std::endl;

        std::cout << "output num element:  " << output_tensor_info.GetElementCount() << std::endl;
        /* print the output */
        //for (size_t i = 0; i < output_tensor_info.GetElementCount(); i++) {
        //std::cout << output[i] << " ";
        //}
        
    }
}


