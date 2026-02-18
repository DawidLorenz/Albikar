# Albikar

Starter template for a **C++23**, cross-platform (**Linux + Windows**) game technology stack.

## Binary targets

- `AlbikarEngine` - **shared library** (`.dll` on Windows, `.so` on Linux).
- `AlbikarEditor` - **executable** (`.exe` on Windows).

## Tooling baseline

- Package manager: **vcpkg** (manifest mode via `vcpkg.json`).
- Compilers: **clang** (Linux) and **clang-cl** (Windows).
- Formatting: **clang-format** with **Microsoft** style (`.clang-format`).
- Static analysis: **clang-tidy** (`.clang-tidy`, auto-enabled when installed).
- Testing: **GTest + CTest**.
- CI: **GitHub Actions** matrix build for Linux + Windows.

## Dependencies managed by vcpkg

- `glfw3`
- `imgui` (features: `glfw-binding`, `opengl3-binding`)
- `glm`
- `fmt`
- `gtest`

## Quick start

### 0) Install vcpkg and set environment

Linux/macOS:

```bash
export VCPKG_ROOT=$HOME/vcpkg
```

Windows (PowerShell):

```powershell
$env:VCPKG_ROOT = "C:\vcpkg"
```

### Linux (clang)

```bash
cmake --preset linux-clang-debug
cmake --build --preset build-linux-debug
ctest --preset test-linux-debug
./build/linux-clang-debug/AlbikarEditor
```

### Windows (clang-cl)

```powershell
cmake --preset windows-clangcl-debug
cmake --build --preset build-windows-debug
ctest --preset test-windows-debug
.\build\windows-clangcl-debug\AlbikarEditor.exe
```

## Editor GUI

When GUI dependencies are installed (GLFW + ImGui + OpenGL), `AlbikarEditor` starts a dockable editor UI with:

- top menu (`File`, `Window`)
- `Hierarchy`, `Inspector`, `Content Browser`, `Console` panels
- central `Viewport` panel prepared for game-engine preview rendering

If dependencies are unavailable, editor runs in console fallback mode.

GUI architecture uses separate classes and patterns:

- `EditorApplication` as application-level orchestration (Facade)
- `IGuiPanel` as panel interface (Strategy/Polymorphism)
- dedicated panel classes (`HierarchyPanel`, `InspectorPanel`, `ContentBrowserPanel`, `ConsolePanel`, `ViewportPanel`)
- `EditorMenuBar` to isolate command/menu behavior

## Folder layout (separated engine/editor)

```text
.
├── engine/
│   ├── include/albikar/     # public engine API
│   └── src/                 # engine implementation
├── editor/
│   └── src/                 # editor executable source
├── tests/                   # unit tests (GTest)
├── cmake/                   # warnings, toolchains
├── .github/workflows/       # CI pipeline
├── vcpkg.json               # dependencies manifest
└── docs/
```

## Product targets and architecture

- Product directions: `docs/product-directions.md`
- Engineering principles (SOLID + modern C++23): `docs/engineering-principles.md`

Key policy:
- each newly added **public engine function** must have matching/updated GTest coverage.
- maintain class-based architecture with modern design patterns (Facade, Strategy, Command, Observer) and C++23 features.
