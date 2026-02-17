#ifndef SPACESHOOTER_WAVESMANAGER_H
#define SPACESHOOTER_WAVESMANAGER_H
#include <raylib.h>

#include "events/Event.h"
#include "events/Observer.h"
#include "events/Subject.h"


class WavesManager : public Observer<Vector2>, public Subject<Vector2> {
public:
    WavesManager();

    void startWavesDispatch();

    void stopWavesDispatch();

    void update();

private:
    static constexpr Event ENEMY_SPAWN_OPTIONS[] = {
        SHELL_ENEMY_SPAWNED,
        KAMIKAZE_ENEMY_SPAWNED,
        CANDY_ENEMY_SPAWNED
    };
    static constexpr Event PICKUP_SPAWN_OPTION = PICKUP_ITEM_SPAWNED;
    static constexpr float DIFFICULTY_MODIFIER = 1.5;
    static constexpr int PICKUP_TO_ENEMY = 4;
    static constexpr int BREAK_BETWEEN_DISPATCH = 5;

    std::vector<Event> wave;
    int currentWave;
    int enemiesInWave;
    int pickupsInWave;
    int leftInWave;
    float timeSinceLastDispatch;

    void onNotify(const Vector2& data, Event event) override;

    void nextWave();

    void populateWave();

    void dispatchWave();
};


#endif //SPACESHOOTER_WAVESMANAGER_H