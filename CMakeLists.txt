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
        src/entities/enemies/ShellEnemy.cpp
        src/entities/enemies/ShellEnemy.h
        src/entities/enemies/states/ShellEnemyState.h
        src/entities/enemies/states/ShellAdvancingState.cpp
        src/entities/enemies/states/ShellAdvancingState.h
        src/entities/enemies/states/ShellTrailingState.cpp
        src/entities/enemies/states/ShellTrailingState.h
        src/entities/effects/Sparkle.cpp
        src/entities/effects/Sparkle.h
        src/items/MissileItem.cpp
        src/items/MissileItem.h
        src/items/Item.cpp
        src/items/Item.h
        src/entities/projectiles/PlayerMissile.cpp
        src/entities/projectiles/PlayerMissile.h
        src/entities/pickups/RandomPickup.cpp
        src/entities/pickups/RandomPickup.h
        src/core/PoolManager.cpp
        src/core/PoolManager.h
        src/entities/IEntityPool.h
        src/core/CollisionManager.cpp
        src/core/CollisionManager.h
        src/entities/projectiles/SquareProjectile.cpp
        src/entities/projectiles/SquareProjectile.h
        src/items/SquareItem.cpp
        src/items/SquareItem.h
        src/entities/projectiles/CircleProjectile.cpp
        src/entities/projectiles/CircleProjectile.h
        src/items/CircleItem.cpp
        src/items/CircleItem.h
        src/core/WavesManager.cpp
        src/core/WavesManager.h
        src/ui/HeldItemDisplay.cpp
        src/ui/HeldItemDisplay.h
        src/ui/Display.cpp
        src/ui/Display.h
        src/ui/HealthBarDisplay.cpp
        src/ui/HealthBarDisplay.h
        src/ui/GameOverDisplay.cpp
        src/ui/GameOverDisplay.h
        src/ui/GameStartDisplay.cpp
        src/ui/GameStartDisplay.h
        src/core/SoundManager.cpp
        src/core/SoundManager.h
        src/entities/powerups/RandomPowerup.cpp
        src/entities/powerups/RandomPowerup.h
)

target_include_directories(SpaceShooter PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_link_libraries(SpaceShooter PRIVATE raylib glfw)

# Add this after your add_executable(...) line
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/sounds DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
