/**
 * ************************************************************************
 * @copyright Copyright (c) 2024 Dawid Lorenz Development
 * ************************************************************************
 */
#include "ConsoleLogger.h"

#include <Time.h>

#include <fmt/core.h>
#include <fmt/ostream.h>

#include <iostream>
#include <atomic>

namespace albikar::logger {

auto ConsoleLogger::Log(ILogger::LOG_LEVEL level, uint64_t thread_id,
                        const std::string& file_name, const int line,
                        const std::string& function_name, std::string& message)
    -> void const {
  auto out = fmt::memory_buffer();
  fmt::format_to(std::back_inserter(out), "[{}] [{}] [{}:{}] [{}] ",
                 utils::Time::CurrentTime(), thread_id, file_name, line,
                 LogLevelToString(level));

  fmt::format_to(std::back_inserter(out), "{}\n", message);
  std::cout << fmt::to_string(out);
}

auto ConsoleLogger::GetThreadId() -> uint64_t const {
  static std::atomic<uint64_t> thread_counter{1};
  thread_local uint64_t tid = thread_counter.fetch_add(1);
  return tid;
}

auto ConsoleLogger::LogLevelToString(ILogger::LOG_LEVEL level) -> std::string {
  switch (level) {
    case LOG_LEVEL::EMERG:
      return "EMERG";
    case LOG_LEVEL::ALERT:
      return "ALERT";
    case LOG_LEVEL::CRIT:
      return "CRIT";
    case LOG_LEVEL::ERR:
      return "ERR";
    case LOG_LEVEL::WARNING:
      return "WARNING";
    case LOG_LEVEL::NOTICE:
      return "NOTICE";
    case LOG_LEVEL::INFO:
      return "INFO";
    case LOG_LEVEL::DEBUG:
      return "DEBUG";
    default:
      return "Unknown";
  }
}
}  // namespace albikar::logger
