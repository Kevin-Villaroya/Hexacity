#ifndef __TEXTURE_TOOL_ANIMATION_H__
#define __TEXTURE_TOOL_ANIMATION_H__

#include "TextureTool.h"
#include <string>
#include <vector>


class TextureToolAnimation{
    public:
        static const TextureToolAnimation EMPTY;
        static const TextureToolAnimation forest;
        static const TextureToolAnimation house;
        static const TextureToolAnimation mountain;

        static const TextureToolAnimation basic;
        static const TextureToolAnimation plain;
        static const TextureToolAnimation water;

    private:
        TextureToolAnimation(std::string path, std::string name = "unknown");
        std::vector<TextureTool> textures;
        std::string name;

    public:
        const TextureTool& getTexture(uint x) const;
        uint getSize() const;
};

#endif