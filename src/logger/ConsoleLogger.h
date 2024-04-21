/**
 * ************************************************************************
 * @copyright Copyright (c) 2024 Dawid Lorenz Development
 * ************************************************************************
 */
#pragma once

#include <ILogger.h>

namespace albikar::logger {

class ConsoleLogger : public ILogger {
 public:
  auto Log(ILogger::LOG_LEVEL level, uint64_t thread_id,
           const std::string& file_name, const int line,
           const std::string& function_name, std::string& message)
      -> void const override;
  auto GetThreadId() -> uint64_t const override;

 private:
  auto LogLevelToString(ILogger::LOG_LEVEL level) -> std::string;
};

}  // namespace albikar::logger
