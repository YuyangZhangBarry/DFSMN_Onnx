#include <all.h>

using namespace dfsmn;

int main(int argc, char** argv)
{
	TCLAP::CmdLine cmd("dfsmn",' ',"1.0");
	TCLAP::ValueArg<std::string>  model_path("p","model-path","Right now the path to the model, change to dir containing the model and configuration file in the future",true,"","string");
	TCLAP::ValueArg<int>     thread_num("t","thread","number of threads",false,1,"int");

	cmd.add(model_path);
	cmd.add(thread_num);
	cmd.parse(argc,argv);
	
    std::string _model_path = model_path.getValue();
    int _thread_num = thread_num.getValue();

	std::cout << "Loading model from: " << _model_path.c_str() << std::endl;
	std::cout << "Thread number: " << _thread_num << std::endl;

	Model* m = CreateModel(_model_path.c_str(),_thread_num);

	std::cout << "Successfully Loaded Model from : " << _model_path << std::endl;
    std::cout << "Querying input and output... " << std::endl;

	QueryModelInfo(m);

    return 0;
}