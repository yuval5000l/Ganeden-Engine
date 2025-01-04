#pragma once


#ifdef GANEDEN_API

extern Ganeden::Application* Ganeden::CreateApplication();

int main(int argc, char** argv)
{
	Ganeden::Log::Init();
	GE_CORE_FATAL("Not enough memory to render Yuvals massive cock 8==================================...");
	int Yuval_every_day = 69;
	GE_INFO("Awwwwww YEAHHHHHHHH = {0}", Yuval_every_day);

	auto app = Ganeden::CreateApplication();
	app->Run();
	delete app;
	return 0;
}

#endif // GE_PLATFORM_WINDOWS
