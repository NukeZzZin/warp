cmake_minimum_required(VERSION 3.20)
project(game-development VERSION 0.0.1)

add_executable(game-development src/main.cpp src/window.cpp includes/window.hpp)

set_property(TARGET game-development PROPERTY CXX_STANDARD 11)
target_compile_options(game-development PUBLIC -Wall)

add_definitions(-DGLEW_STATIC)
add_subdirectory(submodules/glfw)
add_subdirectory(submodules/glew)
add_subdirectory(submodules/glm)

target_include_directories(game-development PUBLIC submodules/glfw/include)
target_include_directories(game-development PUBLIC submodules/glew/include)
# ! target_link_directories(game-development PUBLIC submodules/glfw/src)
# ! target_link_directories(game-development PUBLIC submodules/glew/src)
target_link_libraries(game-development glfw libglew_static glm)