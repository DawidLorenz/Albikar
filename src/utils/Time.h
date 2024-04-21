/**
 * ************************************************************************
 * @copyright Copyright (c) 2024 Dawid Lorenz Development
 * ************************************************************************
 */
#pragma once

#include <string>

namespace albikar::utils {
class Time {
 public:
  static auto CurrentTime(bool local_time = false) -> std::string;
};
}  // namespace albikar::utils
