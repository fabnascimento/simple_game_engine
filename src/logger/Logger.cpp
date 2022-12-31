#include "Logger.h"
#include <spdlog/spdlog.h>


void Logger::Log(const std::string& message) {
    spdlog::info(message);
}

void Logger::Error(const std::string& message) {
    spdlog::error(message);
}
