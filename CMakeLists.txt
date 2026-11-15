cmake_minimum_required(VERSION 3.16)
project(CompetitiveProgramming LANGUAGES CXX)

# ---------------------------------------------------------------------------
# Global settings
# ---------------------------------------------------------------------------
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)   # lets VS Code / clangd find headers

if(POLICY CMP0135)
  cmake_policy(SET CMP0135 NEW)         # no timestamp warning for downloads
endif()

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

option(CP_SANITIZERS "Enable ASan + UBSan in Debug builds" ON)

# Number of stages (stage_0 ... stage_<CP_LAST_STAGE>). Raise it if you add
# a stage_8 for contests.
set(CP_LAST_STAGE 7 CACHE STRING "Index of the last stage directory")

# Put every executable in build/bin/...
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# ---------------------------------------------------------------------------
# Shared compile options (interface target, linked by everything)
# ---------------------------------------------------------------------------
add_library(cp_options INTERFACE)

# Lets you write  #include "stage_3/knapsack.hpp"  from any stage or test.
target_include_directories(cp_options INTERFACE ${CMAKE_SOURCE_DIR}/src/stages)

if(MSVC)
  target_compile_options(cp_options INTERFACE /W4)
else()
  target_compile_options(cp_options INTERFACE -Wall -Wextra -Wshadow)
  if(CP_SANITIZERS)
    target_compile_options(cp_options INTERFACE
      $<$<CONFIG:Debug>:-fsanitize=address,undefined -fno-omit-frame-pointer -g>)
    target_link_options(cp_options INTERFACE
      $<$<CONFIG:Debug>:-fsanitize=address,undefined>)
  endif()
  target_compile_options(cp_options INTERFACE $<$<CONFIG:Release>:-O2>)
endif()

# ---------------------------------------------------------------------------
# Solutions: every .cpp under src/stages/stage_N/ is its own executable.
#   src/stages/stage_3/coin_combinations.cpp
#     -> build/bin/stage_3/coin_combinations
# Each such file must contain its own main().
# Put reusable algorithms in .hpp headers (those are NOT compiled alone).
# ---------------------------------------------------------------------------
foreach(i RANGE 0 ${CP_LAST_STAGE})
  set(stage_dir ${CMAKE_SOURCE_DIR}/src/stages/stage_${i})
  if(NOT IS_DIRECTORY ${stage_dir})
    continue()
  endif()

  file(GLOB_RECURSE stage_sources CONFIGURE_DEPENDS ${stage_dir}/*.cpp)
  foreach(src IN LISTS stage_sources)
    get_filename_component(name ${src} NAME_WE)
    set(target stage_${i}_${name})
    add_executable(${target} ${src})
    target_link_libraries(${target} PRIVATE cp_options)
    set_target_properties(${target} PROPERTIES
      OUTPUT_NAME ${name}
      RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/stage_${i})
  endforeach()
endforeach()

# ---------------------------------------------------------------------------
# Tests: one GoogleTest executable per src/tests/test_N/ directory
#   (all test_*.cpp in that directory are linked together)
# Run with ctest, or run build/bin/tests/test_N directly.
# ---------------------------------------------------------------------------
enable_testing()

find_package(GTest CONFIG QUIET)           # use vcpkg/Homebrew copy if present
if(NOT GTest_FOUND)
  include(FetchContent)
  FetchContent_Declare(googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.tar.gz)
  set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
  set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
  FetchContent_MakeAvailable(googletest)
endif()
include(GoogleTest)

foreach(i RANGE 0 ${CP_LAST_STAGE})
  set(test_dir ${CMAKE_SOURCE_DIR}/src/tests/test_${i})
  if(NOT IS_DIRECTORY ${test_dir})
    continue()
  endif()

  file(GLOB_RECURSE test_sources CONFIGURE_DEPENDS ${test_dir}/*.cpp)
  if(NOT test_sources)
    continue()                              # empty folder: nothing to build yet
  endif()

  set(target test_${i})
  add_executable(${target} ${test_sources})
  target_link_libraries(${target} PRIVATE cp_options GTest::gtest_main)
  set_target_properties(${target} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/tests)
  gtest_discover_tests(${target})
endforeach()