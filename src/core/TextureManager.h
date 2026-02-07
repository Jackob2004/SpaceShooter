#ifndef SPACESHOOTER_TEXTUREMANAGER_H
#define SPACESHOOTER_TEXTUREMANAGER_H

#include <raylib.h>
#include <unordered_map>
#include <string>

class TextureManager {
public:
    TextureManager() = delete;

    static Texture2D getTexture(const char* path);

    static void unloadTextures();

private:
    static std::unordered_map<std::string, Texture2D> textures;
};


#endif //SPACESHOOTER_TEXTUREMANAGER_H