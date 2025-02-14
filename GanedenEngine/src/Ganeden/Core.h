#pragma once

#ifdef GE_PLATFORM_WINDOWS
	#ifdef GE_BUILD_DLL	
		#define GANEDEN_API __declspec(dllexport)
	#else 
		#define GANEDEN_API __declspec(dllimport)
	#endif
#elif defined(__APPLE__)
	#ifdef GE_BUILD_DLL
		#define GANEDEN_API __attribute__((visibility("default")))
	#else
		#define GANEDEN_API 
	#endif
#else
	#error Ganeden only supports Windows and macOS!
#endif

#define BIT(x) (1 << x)