#include "TextureManager.h"

std::unordered_map<std::string, Texture2D> TextureManager::textures;

Texture2D TextureManager::getTexture(const char* path) {
    const auto it = textures.find(path);
    if (it == textures.end()) {
        textures.insert({path, LoadTexture(path)});
    }

    return textures[path];
}

void TextureManager::unloadTextures() {
    for (const auto& it : textures) {
        UnloadTexture(it.second);
    }
}
