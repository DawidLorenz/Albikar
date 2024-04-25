/**
 * ************************************************************************
 * @copyright Copyright (c) 2024 Dawid Lorenz Development
 * ************************************************************************
 */

#include "Application.h"

#include <Logger.h>
#include <Version.h>

namespace albikar::core {

std::unique_ptr<gui::QUIApplication> Application::gui_app_;

auto Application::Get() -> Application& {
  static Application app;
  return app;
}

auto Application::CreateApp(int argc, char* argv[]) -> Application& {
  Application& app = Application::Get();
  gui_app_ = std::make_unique<gui::QUIApplication>(argc, argv);
  LOG_INFO("Construct Application");
  version::VersionLogFullVersion();
  return app;
}

auto Application::Start() -> void {
  LOG_INFO("Start Application");
  gui_app_->Start();
}

auto Application::Stop() -> void {
  LOG_INFO("Stop Application");
  if (gui_app_) {
    gui_app_.reset();
  }
}

Application::Application() {
  LOG_INFO("Create Application");
}

Application::~Application() {
  LOG_INFO("Destroy Application");
}

}  // namespace albikar::core