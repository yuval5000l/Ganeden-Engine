#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
namespace Ganeden {

	class GANEDEN_API Log
	{

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }


	};

}
#define GE_CORE_TRACE(...) ::Ganeden::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define GE_CORE_INFO(...) ::Ganeden::Log::GetCoreLogger()->info(__VA_ARGS__)
#define GE_CORE_WARN(...) ::Ganeden::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define GE_CORE_ERROR(...) ::Ganeden::Log::GetCoreLogger()->error(__VA_ARGS__)
#define GE_CORE_FATAL(...) ::Ganeden::Log::GetCoreLogger()->critical(__VA_ARGS__)

#define GE_TRACE(...) ::Ganeden::Log::GetClientLogger()->trace(__VA_ARGS__)
#define GE_INFO(...) ::Ganeden::Log::GetClientLogger()->info(__VA_ARGS__)
#define GE_WARN(...) ::Ganeden::Log::GetClientLogger()->warn(__VA_ARGS__)
#define GE_ERROR(...) ::Ganeden::Log::GetClientLogger()->error(__VA_ARGS__)
#define GE_FATAL(...) ::Ganeden::Log::GetClientLogger()->critical(__VA_ARGS__)



