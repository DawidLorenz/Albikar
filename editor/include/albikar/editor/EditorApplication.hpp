#pragma once

#include "albikar/Engine.hpp"

namespace albikar::editor {

class EditorApplication {
public:
    explicit EditorApplication(const albikar::Engine &engine_ref);
    int run();

private:
    const albikar::Engine &engine;
};

} // namespace albikar::editor
