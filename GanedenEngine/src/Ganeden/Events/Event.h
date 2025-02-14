#pragma once
#include "..\Core.h"
#include <string>
namespace Ganeden
{
	// Enum event type
	// Enum event category

	// Define macros for virutal events

	class GANEDEN_API Event
	{
		static Event GetStaticType(); // TODO
		virtual Event GetEventType() const = 0; // TODO
		virtual const char*  GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;

		std::string virtual ToString() const 
		{
			return GetName();
		};

	protected:
		bool E_Handled = false;
	};
}