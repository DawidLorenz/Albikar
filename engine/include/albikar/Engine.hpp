#pragma once

#include "albikar/Export.hpp"

#include <string>
#include <string_view>

namespace albikar {

class ALBIKAR_ENGINE_API Engine {
public:
    [[nodiscard]] std::string backend_name() const;
    [[nodiscard]] bool has_vulkan_backend() const;
    [[nodiscard]] static std::string_view engine_name();
    [[nodiscard]] bool is_stub_backend() const;
};

} // namespace albikar
