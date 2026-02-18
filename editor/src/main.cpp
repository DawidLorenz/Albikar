#include "albikar/Engine.hpp"
#include "albikar/editor/EditorApplication.hpp"

#include <iostream>

int main() {
    const albikar::Engine engine;

#if defined(ALBIKAR_EDITOR_HAS_GUI)
    albikar::editor::EditorApplication app(engine);
    return app.run();
#else
    std::cout << "Albikar Editor bootstrap (console fallback)\n";
    std::cout << "Rendering backend: " << engine.backend_name() << '\n';
    std::cout << "GUI dependencies missing. Install vcpkg deps to run editor UI.\n";
    return 0;
#endif
}
