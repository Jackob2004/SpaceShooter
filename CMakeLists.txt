cmake_minimum_required(VERSION 4.0)
project(SpaceShooter)

set(CMAKE_CXX_STANDARD 20)

find_package(raylib CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)

add_executable(SpaceShooter main.cpp
        Entity.cpp
        Entity.h
        SpriteRenderer.cpp
        SpriteRenderer.h
        Player.cpp
        Player.h
        Game.cpp
        Game.h
        Observer.h
        Event.h
        Subject.cpp
        Subject.h
        BeamProjectile.cpp
        BeamProjectile.h
        BeamPool.cpp
        BeamPool.h)

target_link_libraries(SpaceShooter PRIVATE raylib glfw)

# Add this after your add_executable(...) line
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})