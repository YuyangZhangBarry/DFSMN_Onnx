#include <all.h>


namespace dfsmn{

    class Paraformer : public Model {

    public:
        Paraformer();
        //~Paraformer();
        void Init(const char *path, int thread_num);


        std::shared_ptr<Ort::Session> m_session_ = nullptr;
        Ort::Env env_;
        Ort::SessionOptions session_options_;

    };
}
