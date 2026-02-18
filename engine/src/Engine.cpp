#include "albikar/Engine.hpp"

namespace albikar {

std::string Engine::backend_name() const {
#ifdef ALBIKAR_HAS_VULKAN
    return "Vulkan";
#else
    return "Stub (Vulkan SDK not found)";
#endif
}

bool Engine::has_vulkan_backend() const {
#ifdef ALBIKAR_HAS_VULKAN
    return true;
#else
    return false;
#endif
}

std::string_view Engine::engine_name() {
    return "AlbikarEngine";
}

bool Engine::is_stub_backend() const {
    return !has_vulkan_backend();
}

} // namespace albikar
