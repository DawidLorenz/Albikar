/**
 * ************************************************************************
 * @copyright Copyright (c) 2024 Dawid Lorenz Development
 * ************************************************************************
 */

#include <Logger.h>
#include <Profiler.h>
#include <Application.h>

auto main(int argc, char* argv[]) -> int {
  try {
    ALB_PROFILE_BEGIN_SESSION("AlbikarApplication", "AlbikarApplication.json");
    LOG_NOTICE("Opening Albikar Editor");
    albikar::core::Application::CreateApp(argc, argv).Start();
  } catch (const std::exception& e) {
    LOG_CRIT("{}", e.what());
    albikar::core::Application::Get().Stop();
    ALB_PROFILE_END_SESSION();
    return static_cast<int>(false);
  }

  albikar::core::Application::Get().Stop();
  ALB_PROFILE_END_SESSION();
  LOG_NOTICE("Closing Albikar Editor");
  return static_cast<int>(true);
}