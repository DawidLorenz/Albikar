#include "albikar/editor/EditorPanels.hpp"

#if defined(ALBIKAR_EDITOR_HAS_GUI)
    #include <imgui.h>
#endif

namespace albikar::editor {

#if defined(ALBIKAR_EDITOR_HAS_GUI)

void HierarchyPanel::draw() {
    ImGui::Begin("Hierarchy");
    ImGui::BulletText("SceneRoot");
    ImGui::BulletText("DirectionalLight");
    ImGui::BulletText("MainCamera");
    ImGui::End();
}

void InspectorPanel::draw() {
    ImGui::Begin("Inspector");
    ImGui::Text("Selected: MainCamera");
    ImGui::Separator();
    ImGui::Text("Position: (0.0, 2.0, -8.0)");
    ImGui::Text("Rotation: (15.0, 0.0, 0.0)");
    ImGui::Text("FOV: 60.0");
    ImGui::End();
}

void ContentBrowserPanel::draw() {
    ImGui::Begin("Content Browser");
    ImGui::BulletText("Assets/");
    ImGui::BulletText("  Textures/");
    ImGui::BulletText("  Materials/");
    ImGui::BulletText("  Scenes/");
    ImGui::End();
}

ConsolePanel::ConsolePanel(const albikar::Engine &engine_ref)
    : engine(engine_ref) {
}

void ConsolePanel::draw() {
    ImGui::Begin("Console");
    ImGui::Text("[%s] Editor initialized", albikar::Engine::engine_name().data());
    ImGui::Text("Renderer backend: %s", engine.backend_name().c_str());
    ImGui::Text("Vulkan enabled: %s", engine.has_vulkan_backend() ? "yes" : "no");
    ImGui::End();
}

void ViewportPanel::draw() {
    ImGui::Begin("Viewport");
    ImVec2 content_size = ImGui::GetContentRegionAvail();
    ImGui::Text("Game Engine Preview");
    ImGui::Separator();
    ImGui::Text("This panel is the central preview surface.");
    ImGui::Text("Requested size: %.0fx%.0f", content_size.x, content_size.y);
    ImGui::Text("Next step: render engine output texture here.");
    ImGui::End();
}

bool EditorMenuBar::draw(bool &show_hierarchy,
                         bool &show_inspector,
                         bool &show_content_browser,
                         bool &show_console,
                         bool &show_demo_window) const {
    bool should_close = false;

    if (ImGui::BeginMenuBar()) {
        if (ImGui::BeginMenu("File")) {
            ImGui::MenuItem("New Scene", "Ctrl+N");
            ImGui::MenuItem("Open Scene", "Ctrl+O");
            ImGui::MenuItem("Save Scene", "Ctrl+S");
            ImGui::Separator();
            if (ImGui::MenuItem("Exit")) {
                should_close = true;
            }
            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("Window")) {
            ImGui::MenuItem("Hierarchy", nullptr, &show_hierarchy);
            ImGui::MenuItem("Inspector", nullptr, &show_inspector);
            ImGui::MenuItem("Content Browser", nullptr, &show_content_browser);
            ImGui::MenuItem("Console", nullptr, &show_console);
            ImGui::MenuItem("ImGui Demo", nullptr, &show_demo_window);
            ImGui::EndMenu();
        }

        ImGui::EndMenuBar();
    }

    return should_close;
}

#else

void HierarchyPanel::draw() {
}
void InspectorPanel::draw() {
}
void ContentBrowserPanel::draw() {
}
ConsolePanel::ConsolePanel(const albikar::Engine &engine_ref)
    : engine(engine_ref) {
}
void ConsolePanel::draw() {
}
void ViewportPanel::draw() {
}

bool EditorMenuBar::draw(bool &, bool &, bool &, bool &, bool &) const {
    return false;
}

#endif

} // namespace albikar::editor
