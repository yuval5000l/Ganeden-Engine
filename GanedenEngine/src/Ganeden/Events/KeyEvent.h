#pragma once

#include "Event.h"

typedef char KeyCode;

namespace Ganeden
{

    class KeyEvent : public Event {  

        protected:

        KeyCode _keyCode;

        KeyEvent(KeyCode keyCode): _keyCode{keyCode} {}


        public:

        KeyCode getKeyCode(){
            return _keyCode;
        }
  
        EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

    };

    
    class KeyPressed : public KeyEvent{
        private:
        bool _isRepeated;

        public:

        KeyPressed(const KeyCode kc, const bool isRepeated = false) : KeyEvent{kc}, _isRepeated{isRepeated} {};

        EVENT_CLASS_TYPE(KeyPressed)

        bool isRepeated() const{
            return _isRepeated;
        }

		std::string toString() const override
		{
            std::stringstream ss;
            ss << "KeyPressed: " << _keyCode << (_isRepeated ? " | Repeated" : "");
			return ss.str();
		};
        

    };

    class KeyReleased : public KeyEvent{

        public:
        
        KeyReleased(KeyCode kc): KeyEvent{kc} {}

        EVENT_CLASS_TYPE(KeyReleased)

        std::string toString() const override
		{
            std::stringstream ss;
            ss << "KeyReleased: " << _keyCode;
			return ss.str();
		};

    };

}