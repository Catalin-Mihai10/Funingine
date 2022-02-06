#include <Funingine.h>

class Sandbox : public Funingine::MainApplication 
{
public:
	Sandbox() {}
	~Sandbox() {}
};


Funingine::MainApplication* Funingine::CreateMainApplication() 
{
	return new Sandbox();
}
