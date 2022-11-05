cmake_minimum_required(VERSION 3.20)
project(game-development VERSION 0.0.1)

add_executable(game-development src/main.cpp)

add_subdirectory(submodules/glfw)
add_subdirectory(submodules/glew)

target_include_directories(game-development PUBLIC submodules/glfw/include)
target_include_directories(game-development PUBLIC submodules/glew/include)
target_link_directories(game-development PUBLIC submodules/glfw/src)
target_link_directories(game-development PUBLIC submodules/glew/src)
target_link_libraries(game-development glfw libglew_static)