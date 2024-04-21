/**
 * ************************************************************************
 * @copyright Copyright (c) 2024 Dawid Lorenz Development
 * ************************************************************************
 */
#pragma once

namespace albikar::gui {
class QUIApplication {
 public:
  static auto Get() -> QUIApplication&;
  static auto CreateApp(int argc, char* argv[]) -> QUIApplication&;

 public:
  auto Start() -> void;
  auto Stop() -> void;

 private:
  explicit QUIApplication();
  ~QUIApplication();

 public:
  QUIApplication(const QUIApplication&) = delete;
  QUIApplication(QUIApplication&&) = delete;
  auto operator=(const QUIApplication&) -> QUIApplication& = delete;
  auto operator=(const QUIApplication&&) -> QUIApplication& = delete;
};
}  // namespace albikar::gui
