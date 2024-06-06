#include <all.h>

namespace dfsmn
{

  Model *CreateModel(const char* model_path, int thread_num){
        Model *mm;
        mm = new Paraformer();
        mm->Init(model_path, thread_num);
        return mm;
  }

  void QueryModelInfo(Model *m){
  	m->Query();
  
  }

  void QueryWithRandomInput(Model *m,int64_t batch_size, int64_t frame_num){
  
  	m->RandomInput(batch_size, frame_num);
  }


} //namespace dfsmn


