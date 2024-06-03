#include <all.h>

namespace dfsmn{

    Paraformer::Paraformer()
    :env_(ORT_LOGGING_LEVEL_ERROR, "paraformer"),session_options_{} {  
    }

    void Paraformer::Init(const char *path, int thread_num){

        session_options_.SetIntraOpNumThreads(thread_num);
        m_session_ = std::make_unique<Ort::Session>(env_, path, session_options_);

	std::cout<< "Querying Input...\n" << std::endl;
        std::cout<< "Input count: " << m_session_->GetInputCount() << std::endl;

    }
}
