#pragma once

namespace albikar::editor {

class IGuiPanel {
public:
    virtual ~IGuiPanel() = default;
    virtual void draw() = 0;
};

} // namespace albikar::editor
