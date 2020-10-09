#pragma once

#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace Serum {
    class Log {
    public:
        static void Init();

        inline static std::shared_ptr<spdlog::logger>& GetEngineLog() { return EngineLog; }
        inline static std::shared_ptr<spdlog::logger>& GetClientLog() { return ClientLog; }
    private:
        static std::shared_ptr<spdlog::logger> EngineLog;
        static std::shared_ptr<spdlog::logger> ClientLog;
    };
}


// Engine log
#define CORE_TRACE(...)   ::Serum::Log::GetEngineLog()->trace(__VA_ARGS__)
#define CORE_INFO(...)    ::Serum::Log::GetEngineLog()->info(__VA_ARGS__)
#define CORE_WARN(...)    ::Serum::Log::GetEngineLog()->warn(__VA_ARGS__)
#define CORE_ERROR(...)   ::Serum::Log::GetEngineLog()->error(__VA_ARGS__)
#define CORE_FATAL(...)   { ::Serum::Log::GetEngineLog()->critical(__VA_ARGS__); exit(1); }


// Client log
#define TRACE(...)        ::Serum::Log::GetClientLog()->trace(__VA_ARGS__)
#define INFO(...)         ::Serum::Log::GetClientLog()->info(__VA_ARGS__)
#define WARN(...)         ::Serum::Log::GetClientLog()->warn(__VA_ARGS__)
#define ERROR(...)        ::Serum::Log::GetClientLog()->error(__VA_ARGS__)
#define FATAL(...)        { ::Serum::Log::GetClientLog()->critical(__VA_ARGS__); exit(1); }