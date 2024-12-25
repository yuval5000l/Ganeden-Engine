#pragma once
#ifdef GANEDEN_API

extern Ganeden::Application* Ganeden::CreateApplication();

	int main(int argc, char** argv)
	{
		printf("YUVAL THE FUCKING KING");
		auto app = Ganeden::CreateApplication();
		app->Run();
		delete app;
		return 0;
	}
#endif // GE_PLATFORM_WINDOWS
