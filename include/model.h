#include <all.h>

namespace dfsmn{

  class Model{
    public:
        virtual ~Model(){};
	virtual void Init(const char * path, int thread_num){};
        //std::shared_ptr<Ort::Session> session;
        //Ort::Env env;
        //Ort::SessionOptions session_options;
  };

  Model *CreateModel(const char* model_path_, int thread_num_);


} //namespace dfsmn

