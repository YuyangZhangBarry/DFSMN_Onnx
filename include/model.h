#include <all.h>

namespace dfsmn{

  class Model{
    public:
        virtual ~Model(){};
	      virtual void Init(const char * path, int thread_num){};
	      virtual void Query(){};
	      virtual void RandomInput(int64_t batch_size, int64_t frame_num){};
        
  };

  Model *CreateModel(const char* model_path_, int thread_num_);
  void QueryModelInfo(Model *m);
  void QueryWithRandomInput(Model *m,int64_t batch_size, int64_t frame_num);

} //namespace dfsmn


