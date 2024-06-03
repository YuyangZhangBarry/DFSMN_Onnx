#include <all.h>

namespace dfsmn
{

  Model *CreateModel(const char* model_path, int thread_num){

        Model *mm;
        //std::cout << model->env << std::endl;
        //model->env(ORT_LOGGING_LEVEL_WARNING, "test");
        //std::cout << "Fuck!" << std::endl;
        //model->session_options.SetIntraOpNumThreads(thread_num);
        //std::cout << "Fuck!" << std::endl;
        //model->session = std::make_unique<Ort::Session>(model->env,model_path,model->session_options);
        //std::cout << "Fuck!" << std::endl;
        mm = new Paraformer();
        mm->Init(model_path, thread_num);
        return mm;
  }


} //namespace dfsmn

