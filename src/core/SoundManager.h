#ifndef SPACESHOOTER_SOUNDMANAGER_H
#define SPACESHOOTER_SOUNDMANAGER_H
#include <raylib.h>


class SoundManager {
public:
    SoundManager();

    void update();

private:
    Music music;
};


#endif //SPACESHOOTER_SOUNDMANAGER_H