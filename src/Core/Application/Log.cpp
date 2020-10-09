#include "Log.h"

namespace Serum {
    std::shared_ptr<spdlog::logger> Log::EngineLog;
    std::shared_ptr<spdlog::logger> Log::ClientLog;

    void Log::Init() {
        spdlog::set_pattern("%^[%T] %n: %v%$");

        EngineLog = spdlog::stdout_color_mt("SERUM");
        EngineLog->set_level(spdlog::level::trace);

        ClientLog = spdlog::stdout_color_mt("GAME");
        ClientLog->set_level(spdlog::level::trace);
    }
}