/**
 * ************************************************************************
 * @copyright Copyright (c) 2024 Dawid Lorenz Development
 * ************************************************************************
 */
#pragma once

#include <string>

namespace albikar::logger {
class ILogger {
 public:
  enum class LOG_LEVEL {
    EMERG,
    ALERT,
    CRIT,
    ERR,
    WARNING,
    NOTICE,
    INFO,
    DEBUG
  };

  virtual auto Log(LOG_LEVEL level, uint64_t thread_id,
                   const std::string& file_name, const int line,
                   const std::string& function_name, std::string& message)
      -> void const = 0;
  virtual auto GetThreadId() -> uint64_t const = 0;
};
}  // namespace albikar::logger
