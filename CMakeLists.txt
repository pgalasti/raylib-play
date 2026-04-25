# 1. Minimum version of CMake required
cmake_minimum_required(VERSION 3.10)

# 2. Project name and version
project(RaylibPlaying VERSION 1.0)

# 3. Set the C++ standard (e.g., C++23)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 4. Add raylib
add_subdirectory(external/raylib)

# 5. Add the executable
add_executable(play src/main.cpp src/core/Game.cpp src/game/TestLevel.cpp)

target_include_directories(play PRIVATE include)
target_link_libraries(play PRIVATE raylib)
target_compile_definitions(play PRIVATE $<$<CONFIG:Debug>:_DEBUG>)

