cmake_minimum_required(VERSION 3.20)
project(warp VERSION 0.0.1)

add_executable(warp src/main.cpp src/window.cpp includes/window.hpp)

add_definitions(-DGLEW_STATIC)
add_subdirectory(submodules/glfw)
add_subdirectory(submodules/glew)
add_subdirectory(submodules/glm)

target_include_directories(warp PUBLIC submodules/glfw/include)
target_include_directories(warp PUBLIC submodules/glew/include)
target_link_libraries(warp glfw libglew_static glm)