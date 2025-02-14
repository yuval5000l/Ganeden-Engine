#include <Ganeden.h>
#include <iostream>
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
	
	// Flushes the buffer
	//std::cout << std::endl;
	return new Sandbox();
}