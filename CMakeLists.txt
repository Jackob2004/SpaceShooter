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
        src/core/events/Subject.h
        src/entities/projectiles/BeamProjectile.cpp
        src/entities/projectiles/BeamProjectile.h
        src/entities/enemies/CandyEnemy.cpp
        src/entities/enemies/CandyEnemy.h
        src/core/TextureManager.cpp
        src/core/TextureManager.h
        src/entities/enemies/states/CandyEnemyState.h
        src/entities/enemies/states/CandyAdvancingState.cpp
        src/entities/enemies/states/CandyAdvancingState.h
        src/entities/enemies/states/CandyTargetingState.cpp
        src/entities/enemies/states/CandyTargetingState.h
        src/entities/enemies/states/CandyShootingState.cpp
        src/entities/enemies/states/CandyShootingState.h
        src/entities/enemies/states/CandyEnemyState.cpp
        src/entities/EntityPool.h
        src/entities/projectiles/EnemyProjectile.cpp
        src/entities/projectiles/EnemyProjectile.h
        src/entities/projectiles/EnemyMissile.cpp
        src/entities/projectiles/EnemyMissile.h
        src/entities/enemies/states/CandyPausingState.cpp
        src/entities/enemies/states/CandyPausingState.h
        src/entities/effects/Explosion.cpp
        src/entities/effects/Explosion.h
        src/entities/Damageable.h
        src/utils/MathUtils.h
        src/utils/MathUtils.cpp
        src/entities/enemies/KamikazeEnemy.cpp
        src/entities/enemies/KamikazeEnemy.h
        src/entities/enemies/states/KamikazeEnemyState.cpp
        src/entities/enemies/states/KamikazeEnemyState.h
        src/entities/enemies/states/KamikazeAdvancingState.cpp
        src/entities/enemies/states/KamikazeAdvancingState.h
        src/entities/enemies/states/KamikazeTargetingState.cpp
        src/entities/enemies/states/KamikazeTargetingState.h
        src/entities/enemies/states/KamikazeDyingState.cpp
        src/entities/enemies/states/KamikazeDyingState.h
)

target_include_directories(SpaceShooter PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_link_libraries(SpaceShooter PRIVATE raylib glfw)

# Add this after your add_executable(...) line
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})