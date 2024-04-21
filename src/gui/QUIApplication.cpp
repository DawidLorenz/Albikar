/**
 * ************************************************************************
 * @copyright Copyright (c) 2024 Dawid Lorenz Development
 * ************************************************************************
 */

#include "QUIApplication.h"

#include <Logger.h>

namespace albikar::gui {

auto QUIApplication::Get() -> QUIApplication& {
  static QUIApplication app;
  return app;
}

auto QUIApplication::CreateApp(int argc, char* argv[]) -> QUIApplication& {
  QUIApplication& app = QUIApplication::Get();
  LOG_INFO("Construct QUIApplication");
  return app;
}

auto QUIApplication::Start() -> void {
  LOG_INFO("Start QUIApplication");
}

auto QUIApplication::Stop() -> void {
  LOG_INFO("Stop QUIApplication");
}

QUIApplication::QUIApplication() {
  LOG_INFO("Create QUIApplication");
}

QUIApplication::~QUIApplication() {
  LOG_INFO("Destroy QUIApplication");
}

};  // namespace albikar::gui