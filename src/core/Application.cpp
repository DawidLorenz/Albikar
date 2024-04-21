/**
 * ************************************************************************
 * @copyright Copyright (c) 2024 Dawid Lorenz Development
 * ************************************************************************
 */

#include "Application.h"

#include <Logger.h>
#include <Version.h>
#include <QUIApplication.h>

namespace albikar::core {

auto Application::Get() -> Application& {
  static Application app;
  return app;
}

auto Application::CreateApp(int argc, char* argv[]) -> Application& {
  Application& app = Application::Get();
  gui::QUIApplication::CreateApp(argc, argv);
  LOG_INFO("Construct Application");
  version::VersionLogFullVersion();
  return app;
}

auto Application::Start() -> void {
  LOG_INFO("Start Application");
  gui::QUIApplication::Get().Start();
}

auto Application::Stop() -> void {
  LOG_INFO("Stop Application");
}

Application::Application() {
  LOG_INFO("Create Application");
}

Application::~Application() {
  LOG_INFO("Destroy Application");
}

}  // namespace albikar::core