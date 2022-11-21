#include "TextureToolAnimation.h"
#include <filesystem>
#include <iostream>

const TextureToolAnimation TextureToolAnimation::EMPTY = TextureToolAnimation("assets/none", "none");

const TextureToolAnimation TextureToolAnimation::basic = TextureToolAnimation("assets/block/default", "default");
const TextureToolAnimation TextureToolAnimation::plain = TextureToolAnimation("assets/block/plain", "plain");
const TextureToolAnimation TextureToolAnimation::water = TextureToolAnimation("assets/block/water", "water");

TextureToolAnimation::TextureToolAnimation(std::string path, std::string name) : name(name){
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