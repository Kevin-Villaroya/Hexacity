#include "TextureToolAnimation.h"
#include <filesystem>

const TextureToolAnimation TextureToolAnimation::basic = TextureToolAnimation("assets/block/default");
const TextureToolAnimation TextureToolAnimation::plain = TextureToolAnimation("assets/block/plain");
const TextureToolAnimation TextureToolAnimation::water = TextureToolAnimation("assets/block/water");

TextureToolAnimation::TextureToolAnimation(std::string path){
    for (const auto & entry : std::filesystem::directory_iterator(path)){
        TextureTool texture(entry.path());
        this->textures.push_back(texture);
    } 
}

const TextureTool& TextureToolAnimation::getTexture(uint x) const{
    return this->textures[x];
}

uint TextureToolAnimation::getSize() const{
    return this->textures.size();
}