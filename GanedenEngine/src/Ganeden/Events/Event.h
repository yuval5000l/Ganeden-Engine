#pragma once
#include "../Core.h"
#include <sstream>
#include <string>
namespace Ganeden
{
	// Enum event type
	// Enum event category

	// Define macros for virutal events
	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased, KeyTyped,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCategory
	{
		None = 0,
		EventCategoryApplication = BIT(0),
		EventCategoryInput = BIT(1),
		EventCategoryKeyboard = BIT(2),
		EventCategoryMouse = BIT(3),
		EventCategoryMouseButton = BIT(4)
	};

	#define EVENT_CLASS_TYPE(type) static EventType getStaticType() { return EventType::type; }\
								virtual EventType getEventType() const override { return getStaticType(); }\
								virtual const char* getName() const override { return #type; }

	#define EVENT_CLASS_CATEGORY(category) virtual int getCategoryFlags() const override { return category; }
	#define ENUM_TO_STRING(val) case val: return #val;


	struct GANEDEN_API Event
	{
		virtual EventType getEventType() const = 0;
		virtual const char* getName() const = 0;
		virtual int getCategoryFlags() const = 0;

		std::string virtual toString() const { return getName(); };
		bool isInCategory(EventCategory category)
		{
			return getCategoryFlags() & category;
		}

		bool _handled = false;

	};
	inline std::ostream& operator<<(std::ostream& os, Event& e)
	{
		return os << e.toString();
	}
	class GANEDEN_API DispatchEvent
	{
	public:
		DispatchEvent(Event& event) : _event(event) {}


		// F will be deduced by the compiler
		template<typename T, typename F>
		bool Dispatch(const F& func) // TODO feels not optimized, should check later
		{
			if (_event.getEventType() == T::getStaticType())
			{
				_event._handled |= func(static_cast<T&>(_event));
				return true;
			}
			return false;
		}
	private:
		Event& _event;


	};
};