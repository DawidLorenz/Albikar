/**
 * ************************************************************************
 * @copyright Copyright (c) 2024 Dawid Lorenz Development
 * ************************************************************************
 */
#include "Time.h"

#include <chrono>
#include <sstream>
#include <ctime>
#include <iomanip>

namespace {
auto GetTmStructCurrentTime(bool local_time)
    -> std::pair<struct tm, std::chrono::milliseconds> {

  auto now = std::chrono::system_clock::now();
  auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(
                now.time_since_epoch()) %
            1000;
  auto time_now = std::chrono::system_clock::to_time_t(now);

  struct tm tstruct {};
  struct tm result {};
  if (local_time) {
    tstruct = *localtime_r(&time_now, &result);
  } else {
    tstruct = *gmtime_r(&time_now, &result);
  }
  return std::make_pair(result, ms);
}
}  // namespace

namespace albikar::utils {

auto Time::CurrentTime(bool local_time) -> std::string {
  auto [tm, ms] = GetTmStructCurrentTime(local_time);
  std::ostringstream ss;
  ss << std::put_time(&tm, "%Y-%m-%dT%H:%M:%S") << '.' << std::setw(3)
     << std::setfill('0') << ms.count();
  return ss.str();
}

}  // namespace albikar::utils
