/**
 * ************************************************************************
 * @copyright Copyright (c) 2024 Dawid Lorenz Development
 * ************************************************************************
 */
#include "Logger.h"

namespace albikar {

std::mutex Logger::mutex_;
std::unique_ptr<logger::ILogger> Logger::logger_ =
    std::make_unique<logger::ConsoleLogger>();

}  // namespace albikar
