#include <Ganeden.h>

class Sandbox : public Ganeden::Application
{
public:
	Sandbox()
	{
	
	}
	~Sandbox()
	{

	}
};
Ganeden::Application* Ganeden::CreateApplication()
{
	return new Sandbox();
}