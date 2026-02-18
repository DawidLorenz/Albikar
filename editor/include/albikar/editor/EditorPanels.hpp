#pragma once

#include "albikar/Engine.hpp"
#include "albikar/editor/IGuiPanel.hpp"

#include <string>

namespace albikar::editor {

class HierarchyPanel final : public IGuiPanel {
public:
    void draw() override;
};

class InspectorPanel final : public IGuiPanel {
public:
    void draw() override;
};

class ContentBrowserPanel final : public IGuiPanel {
public:
    void draw() override;
};

class ConsolePanel final : public IGuiPanel {
public:
    explicit ConsolePanel(const albikar::Engine &engine_ref);
    void draw() override;

private:
    [[maybe_unused]] const albikar::Engine &engine;
};

class ViewportPanel final : public IGuiPanel {
public:
    void draw() override;
};

class EditorMenuBar {
public:
    bool draw(bool &show_hierarchy,
              bool &show_inspector,
              bool &show_content_browser,
              bool &show_console,
              bool &show_demo_window) const;
};

} // namespace albikar::editor
