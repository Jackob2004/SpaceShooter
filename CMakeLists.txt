cmake_minimum_required(VERSION 4.0)
project(SpaceShooter)

set(CMAKE_CXX_STANDARD 20)

find_package(raylib CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)

add_executable(SpaceShooter src/main.cpp
        src/entities/Entity.cpp
        src/entities/Entity.h
        src/components/SpriteRenderer.cpp
        src/components/SpriteRenderer.h
        src/entities/Player.cpp
        src/entities/Player.h
        src/core/Game.cpp
        src/core/Game.h
        src/core/events/Observer.h
        src/core/events/Event.h
        src/core/events/Subject.cpp
        src/core/events/Subject.h
        src/entities/projectiles/BeamProjectile.cpp
        src/entities/projectiles/BeamProjectile.h
        src/entities/projectiles/BeamPool.cpp
        src/entities/projectiles/BeamPool.h)

target_include_directories(SpaceShooter PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_link_libraries(SpaceShooter PRIVATE raylib glfw)

# Add this after your add_executable(...) line
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})