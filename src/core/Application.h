/**
 * ************************************************************************
 * @copyright Copyright (c) 2024 Dawid Lorenz Development
 * ************************************************************************
 */
#pragma once

namespace albikar::core {

class Application {
 public:
  static auto Get() -> Application&;
  static auto CreateApp(int argc, char* argv[]) -> Application&;

 public:
  auto Start() -> void;
  auto Stop() -> void;

 private:
  explicit Application();
  ~Application();

 public:
  Application(const Application&) = delete;
  Application(Application&&) = delete;
  auto operator=(const Application&) -> Application& = delete;
  auto operator=(const Application&&) -> Application& = delete;
};

}  // namespace albikar::core