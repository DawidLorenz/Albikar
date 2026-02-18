#include "albikar/Engine.hpp"

#include <gtest/gtest.h>

namespace {

TEST(EngineTests, EngineNameIsStable) {
    EXPECT_EQ(albikar::Engine::engine_name(), "AlbikarEngine");
}

TEST(EngineTests, BackendNameMatchesVulkanFlag) {
    const albikar::Engine engine;
#ifdef ALBIKAR_HAS_VULKAN
    EXPECT_EQ(engine.backend_name(), "Vulkan");
#else
    EXPECT_EQ(engine.backend_name(), "Stub (Vulkan SDK not found)");
#endif
}

TEST(EngineTests, StubFlagMatchesBackendAvailability) {
    const albikar::Engine engine;
    EXPECT_EQ(engine.is_stub_backend(), !engine.has_vulkan_backend());
}

} // namespace
