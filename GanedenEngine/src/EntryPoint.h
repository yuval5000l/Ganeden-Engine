#pragma once
#ifdef GANEDEN_API

extern Ganeden::Application* Ganeden::CreateApplication();

	int main(int argc, char** argv)
	{
		Ganeden::Log::Init();
		GE_CORE_WARN("Waaaaaa");
		int b = 1;
		GE_INFO("Awwwwww Var={0}", b);

		auto app = Ganeden::CreateApplication();
		app->Run();
		delete app;
		return 0;
	}
#endif // GE_PLATFORM_WINDOWS
