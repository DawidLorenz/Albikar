/**
 * ************************************************************************
 * @copyright Copyright (c) 2024 Dawid Lorenz Development
 * ************************************************************************
 */
#pragma once

namespace albikar::core::version {
auto VersionLogFullVersion() -> void;
auto VersionProgramName() -> const char*;
auto VersionString() -> const char*;
auto VersionMajor() -> unsigned int;
auto VersionMinor() -> unsigned int;
auto VersionPatch() -> unsigned int;
auto VersionFlag() -> const char*;
auto VersionDistance() -> unsigned int;
auto VersionShorthash() -> const char*;
auto VersionFullhash() -> const char*;
auto VersionIsdirty() -> bool;
auto VersionBranch() -> const char*;
}  // namespace albikar::core::version