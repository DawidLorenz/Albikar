#include "albikar/editor/EditorApplication.hpp"
#include "albikar/editor/EditorPanels.hpp"

#if defined(ALBIKAR_EDITOR_HAS_GUI)
    #if defined(_WIN32)
        #include <Windows.h>
    #endif
    #include <GLFW/glfw3.h>
    #include <backends/imgui_impl_glfw.h>
    #include <backends/imgui_impl_opengl3.h>
    #include <imgui.h>

    #include <cstdlib>
    #include <iostream>
#endif

namespace albikar::editor {

EditorApplication::EditorApplication(const albikar::Engine &engine_ref)
    : engine(engine_ref) {
}

int EditorApplication::run() {
#if defined(ALBIKAR_EDITOR_HAS_GUI)
    if (glfwInit() == GLFW_FALSE) {
        std::cerr << "Failed to initialize GLFW.\n";
        return EXIT_FAILURE;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *window = glfwCreateWindow(1600, 900, "AlbikarEditor", nullptr, nullptr);
    if (window == nullptr) {
        std::cerr << "Failed to create GLFW window.\n";
        glfwTerminate();
        return EXIT_FAILURE;
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330");

    bool show_demo_window = false;
    bool show_hierarchy = true;
    bool show_inspector = true;
    bool show_content_browser = true;
    bool show_console = true;

    HierarchyPanel hierarchy_panel;
    InspectorPanel inspector_panel;
    ContentBrowserPanel content_browser_panel;
    ConsolePanel console_panel(engine);
    ViewportPanel viewport_panel;
    EditorMenuBar menu_bar;

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        const ImGuiViewport *main_viewport = ImGui::GetMainViewport();
        ImGui::SetNextWindowPos(main_viewport->WorkPos);
        ImGui::SetNextWindowSize(main_viewport->WorkSize);
        ImGui::SetNextWindowViewport(main_viewport->ID);

        ImGuiWindowFlags host_flags = ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse |
                                      ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove |
                                      ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus |
                                      ImGuiWindowFlags_MenuBar;

        ImGui::Begin("AlbikarEditorHost", nullptr, host_flags);
        if (menu_bar.draw(show_hierarchy, show_inspector, show_content_browser, show_console, show_demo_window)) {
            glfwSetWindowShouldClose(window, GLFW_TRUE);
        }
        ImGuiID dockspace_id = ImGui::GetID("MainDockSpace");
        ImGui::DockSpace(dockspace_id, ImVec2(0.0F, 0.0F), ImGuiDockNodeFlags_None);
        ImGui::End();

        if (show_hierarchy) {
            hierarchy_panel.draw();
        }
        if (show_inspector) {
            inspector_panel.draw();
        }
        if (show_content_browser) {
            content_browser_panel.draw();
        }
        if (show_console) {
            console_panel.draw();
        }
        viewport_panel.draw();

        if (show_demo_window) {
            ImGui::ShowDemoWindow(&show_demo_window);
        }

        ImGui::Render();
        int display_w = 0;
        int display_h = 0;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(0.08F, 0.08F, 0.10F, 1.0F);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        if ((io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable) != 0) {
            GLFWwindow *backup_current_context = glfwGetCurrentContext();
            ImGui::UpdatePlatformWindows();
            ImGui::RenderPlatformWindowsDefault();
            glfwMakeContextCurrent(backup_current_context);
        }

        glfwSwapBuffers(window);
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwDestroyWindow(window);
    glfwTerminate();

    return EXIT_SUCCESS;
#else
    (void)engine;
    return 0;
#endif
}

} // namespace albikar::editor
