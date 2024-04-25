/**
 * ************************************************************************
 * @copyright Copyright (c) 2024 Dawid Lorenz Development
 * ************************************************************************
 */
#pragma once

#include <QObject>
#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <memory>

namespace albikar::gui {
class QUIApplication {
 public:
  explicit QUIApplication(int& argc, char** argv);
  ~QUIApplication();

 public:
  auto Start() -> void;
  auto Stop() -> void;

 private:
  std::unique_ptr<QGuiApplication> qt_qui_app_;
};
}  // namespace albikar::gui
