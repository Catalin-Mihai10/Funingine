#pragma once

#include "CoreMacros.h"
#include "spdlog/spdlog.h"

namespace Funingine {

	class FE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_EngineLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ApplicationLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_EngineLogger;
		static std::shared_ptr<spdlog::logger> s_ApplicationLogger;
	};

}

#define FE_ENGINE_ERROR(...)		::Funngine::Log::GetCoreLogger()->error(__VA__ARGS__)
#define FE_ENGINE_WARN(...)		::Funngine::Log::GetCoreLogger()->warn(__VA__ARGS__)
#define FE_ENGINE_INFO(...)		::Funngine::Log::GetCoreLogger()->info(__VA__ARGS__)
#define FE_ENGINE_TRACE(...)		::Funngine::Log::GetCoreLogger()->trace(__VA__ARGS__)
#define FE_ENGINE_FATAL(...)		::Funngine::Log::GetCoreLogger()->fatal(__VA__ARGS__)

#define FE_APPLICATION_ERROR(...)	::Funngine::Log::GetClientLogger()->error(__VA__ARGS__)
#define FE_APPLICATION_WARN(...)		::Funngine::Log::GetClientLogger()->warn(__VA__ARGS__)
#define FE_APPLICATION_INFO(...)		::Funngine::Log::GetClientLogger()->info(__VA__ARGS__)
#define FE_APPLICATION_TRACE(...)	::Funngine::Log::GetClientLogger()->trace(__VA__ARGS__)
#define FE_APPLICATION_FATAL(...)	::Funngine::Log::GetClientLogger()->fatal(__VA__ARGS__) 