#pragma once

#include "Event.h"
namespace Ganeden
{

    class MouseMovedEvent : public Event
    {
    public:
        MouseMovedEvent(const float x, const float y) : _x(x), _y(y) {};
        float getX() const { return _x; }
        float getY() const { return _y; }

        std::string toString() const override
        {
            std::stringstream ss;
            ss << "MouseMovedEvent: " << _x << ", " << _y;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseMoved)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
    private:
        float _x;
        float _y;
    };

    class MouseScrolledEvent : public Event
    {
    public:
        MouseScrolledEvent(const float x, const float y) : _x(x), _y(y) {};
        float getX() const { return _x; }
        float getY() const { return _y; }

        std::string toString() const override
        {
            std::stringstream ss;
            ss << "MouseScrolledEvent: " << _x << ", " << _y;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseScrolled)
            EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
    private:
        float _x;
        float _y;
    };


    enum class MouseButton
    {
        Left = 0,
        Right,
        Middle
    };
    std::string buttonToString(MouseButton btn) {
        switch (btn) {
            ENUM_TO_STRING(MouseButton::Left)
            ENUM_TO_STRING(MouseButton::Right)
            ENUM_TO_STRING(MouseButton::Middle)
        default: return "UNKNOWN_BUTTON";
        }
    }
    class MouseButtonEvent : public Event
    {
    public:
        MouseButton getMouseButton() const { return _button; }

        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput | EventCategoryMouseButton)

    protected:
        MouseButtonEvent(const MouseButton button) : _button(button){};
        MouseButton _button = MouseButton::Left;
    };

    class MouseButtonPressedEvent : public MouseButtonEvent
    {
    public:
        MouseButtonPressedEvent(const MouseButton button) : MouseButtonEvent(button) {};

        std::string toString() const override
        {
            std::stringstream ss;
            ss << "MouseButtonPressedEvent: " << buttonToString(_button);
            return ss.str();
        }
        EVENT_CLASS_TYPE(MouseButtonPressed)
    }; 
    class MouseButtonReleasedEvent : public MouseButtonEvent
    {
    public:
        MouseButtonReleasedEvent(const MouseButton button) : MouseButtonEvent(button) {};

        std::string toString() const override
        {
            std::stringstream ss;
            ss << "MouseButtonReleasedEvent: " << buttonToString(_button);
            return ss.str();
        }
        EVENT_CLASS_TYPE(MouseButtonPressed)
    };
}