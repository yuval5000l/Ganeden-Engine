#pragma once
#include "Event.h"
#include <string> 
namespace Ganeden
{
	class WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(unsigned int width, unsigned int height)
			: _width(width), _height(height) {}

		unsigned int getWidth() const { return _width; }
		unsigned int getHeight() const { return _height; }

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "WindowResizeEvent: " << _width << ", " << _height;
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	private:
		unsigned int _width, _height;
	};

#define WINDOW_EVENTS(event_name) class event_name##Event : public Event\
	{\
	public:\
		event_name##Event() = default;\
		EVENT_CLASS_TYPE(event_name)\
		EVENT_CLASS_CATEGORY(EventCategoryApplication)\
	};	

	WINDOW_EVENTS(WindowClose)
	WINDOW_EVENTS(AppTick)
	WINDOW_EVENTS(AppUpdate)
	WINDOW_EVENTS(AppRender)

	// class WindowCloseEvent : public Event
	// {
	// public:
	// 	WindowCloseEvent() = default;

	// 	EVENT_CLASS_TYPE(WindowClose)
	// 	EVENT_CLASS_CATEGORY(EventCategoryApplication)
	// };

}