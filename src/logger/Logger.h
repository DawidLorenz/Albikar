/**
 * ************************************************************************
 * @copyright Copyright (c) 2024 Dawid Lorenz Development
 * ************************************************************************
 */
#pragma once

#include <ConsoleLogger.h>

#include <fmt/core.h>
#include <fmt/format.h>
#include <fmt/ostream.h>

#include <mutex>
#include <memory>

#define LOG_EMERG(fmt, ...)                                                  \
  albikar::Logger::Log(albikar::logger::ILogger::LOG_LEVEL::EMERG, __FILE__, \
                       __LINE__, __FUNCTION__, fmt, ##__VA_ARGS__)
#define LOG_ALERT(fmt, ...)                                                  \
  albikar::Logger::Log(albikar::logger::ILogger::LOG_LEVEL::ALERT, __FILE__, \
                       __LINE__, __FUNCTION__, fmt, ##__VA_ARGS__)
#define LOG_CRIT(fmt, ...)                                                  \
  albikar::Logger::Log(albikar::logger::ILogger::LOG_LEVEL::CRIT, __FILE__, \
                       __LINE__, __FUNCTION__, fmt, ##__VA_ARGS__)
#define LOG_ERR(fmt, ...)                                                  \
  albikar::Logger::Log(albikar::logger::ILogger::LOG_LEVEL::ERR, __FILE__, \
                       __LINE__, __FUNCTION__, fmt, ##__VA_ARGS__)
#define LOG_WARNING(fmt, ...)                                                  \
  albikar::Logger::Log(albikar::logger::ILogger::LOG_LEVEL::WARNING, __FILE__, \
                       __LINE__, __FUNCTION__, fmt, ##__VA_ARGS__)
#define LOG_NOTICE(fmt, ...)                                                  \
  albikar::Logger::Log(albikar::logger::ILogger::LOG_LEVEL::NOTICE, __FILE__, \
                       __LINE__, __FUNCTION__, fmt, ##__VA_ARGS__)
#define LOG_INFO(fmt, ...)                                                  \
  albikar::Logger::Log(albikar::logger::ILogger::LOG_LEVEL::INFO, __FILE__, \
                       __LINE__, __FUNCTION__, fmt, ##__VA_ARGS__)
#define LOG_DEBUG(fmt, ...)                                                  \
  albikar::Logger::Log(albikar::logger::ILogger::LOG_LEVEL::DEBUG, __FILE__, \
                       __LINE__, __FUNCTION__, fmt, ##__VA_ARGS__)

namespace albikar {
class Logger {
 public:
  static auto SetLogger(std::unique_ptr<logger::ILogger> logger) -> void {
    logger_ = std::move(logger);
  }

  template <typename... Args>
  static auto Log(logger::ILogger::LOG_LEVEL level,
                  const std::string& file_name, const int line,
                  const std::string& function, fmt::format_string<Args...> s,
                  Args&&... args) -> void {
    std::string formatted_msg = fmt::format(s, std::forward<Args>(args)...);
    logger_->Log(level, logger_->GetThreadId(), file_name, line, function,
                 formatted_msg);
  };

 private:
  static std::mutex mutex_;
  static std::unique_ptr<logger::ILogger> logger_;
};
}  // namespace albikar
