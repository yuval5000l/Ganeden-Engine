#pragma once
#include "Core.h"

namespace Ganeden {
	class GANEDEN_API Application
	{
		public:
			Application();
			virtual ~Application();

			void Run();
	};
	Application* CreateApplication();
}

