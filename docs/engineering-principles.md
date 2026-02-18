# Albikar - Engineering Principles (SOLID + Modern C++23)

This project follows a modern architecture style with clear module boundaries, testability, and high-performance runtime paths.

## Core principles

- **SOLID** at module boundaries.
- **Data-oriented design** in performance-critical loops.
- **Composition over inheritance** whenever possible.
- **Dependency inversion** for backend integrations (rendering, filesystem, input).
- **Test-first evolution** for public APIs.

## Architectural layers

- `Core`: logging, assertions, timing, filesystem abstractions, platform utilities.
- `Foundation`: math, containers, reflection/serialization primitives.
- `Engine`: ECS/scene/assets/input/physics/audio/scripting.
- `Renderer`: RHI abstractions and Vulkan backend.
- `Tools`: Editor + asset pipeline + shader tooling.

## Required design patterns

- **Facade**: application-level orchestration (`EditorApplication`).
- **Strategy/Polymorphism**: panel abstractions and backend policies.
- **Command**: editor actions and undo/redo stack.
- **Observer/Event bus**: hot-reload and decoupled subsystem notifications.
- **Factory/Builder**: pipeline and resource construction.
- **State machine**: runtime/editor/game state transitions.

## Modern C++23 requirements

- Use `std::span`, `std::string_view`, `std::format` for APIs and diagnostics.
- Use RAII for all resource lifetimes.
- Use `std::jthread` + `stop_token` for controlled background tasks.
- Prefer `Result/Expected` style error propagation in engine/runtime code.
- Use `constexpr`/`consteval` where compile-time guarantees are beneficial.

## Testing policy

- Every new **public function** in engine modules must have tests added/updated.
- Unit tests are mandatory for core/foundation/engine logic.
- Integration/smoke tests are mandatory for runtime/editor startup.
- CI must execute configure + build + tests on Linux and Windows.

## Practical rule: SOLID vs performance

- Keep interfaces clean and testable at boundaries.
- In hot paths, prioritize data locality, cache efficiency, and low-overhead loops.
- Avoid unnecessary virtual dispatch in frame-critical systems.
