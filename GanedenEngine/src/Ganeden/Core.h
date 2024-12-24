#pragma once

#ifdef GE_PLATFORM_WINDOWS
	#ifdef GE_BUILD_DLL	
		#define GANEDEN_API __declspec(dllexport)
	#else 
		#define GANEDEN_API __declspec(dllexport)
	#endif
#else
	#error GE only support Windows!
#endif