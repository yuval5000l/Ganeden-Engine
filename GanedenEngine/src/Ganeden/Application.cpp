#include "Application.h"
#include "Events/ApplicationEvent.h"
#include "Events/MouseEvent.h"
#include "Log.h"
#include <iostream>

namespace Ganeden {
	Application::Application() 
	{

	}
	Application::~Application()
	{

	}

	void Application::Run()
	{
		// Add windowResizeEvent
		WindowResizeEvent e(960, 820);
		WindowCloseEvent e2;
		MouseMovedEvent e3(12, 12);
		MouseScrolledEvent e4(20, 20);
		MouseButtonPressedEvent e5(MouseButton::Left);
		MouseButtonPressedEvent e6(MouseButton::Middle);
		std::cout << e << ", " << e2 << ", " <<  std::endl;
		//GE_TRACE(e);
		while (true);
	}
	
}