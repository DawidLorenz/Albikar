# Albikar - roadmap (starter)

## Stage 1
- [x] C++23 cross-platform CMake bootstrap
- [x] clang + clang-cl presets
- [x] Engine (DLL/SO) + Editor (EXE) split
- [x] Separated folders: `engine/` and `editor/`
- [x] GitHub Actions CI build+test matrix
- [x] GTest added for engine API
- [x] Product directions documented
- [x] SOLID + modern C++23 engineering principles documented

## Stage 2 (recommended)
- [x] Editor UI scaffold (docking + common game-editor panels)
- [x] GUI refactor to separate classes and panel interface patterns
- [ ] Real engine render target in center viewport
- [ ] Vulkan instance/device bootstrap
- [ ] Render graph skeleton
- [ ] Asset database (JSON + binary blobs)

## Stage 3
- [ ] ECS / scene graph
- [ ] Hot-reload shaders
- [ ] Play mode / simulation controls
