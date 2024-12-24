#pragma once
#ifdef GE_PLATFORM_WINDOWS

extern Ganeden::Application* Ganeden::CreateApplication();

	int main(int argc, char** argv)
	{
		printf("ACHSAF");
		auto app = Ganeden::CreateApplication();
		app->Run();
		delete app;
		return 0;
	}
#endif // GE_PLATFORM_WINDOWS
