cmake_minimum_required(VERSION 4.0)
project(SpaceShooter)

set(CMAKE_CXX_STANDARD 20)

find_package(raylib CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)

add_executable(SpaceShooter main.cpp)

target_link_libraries(SpaceShooter PRIVATE raylib glfw)