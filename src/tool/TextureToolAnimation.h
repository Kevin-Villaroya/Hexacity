#ifndef __TEXTURE_TOOL_ANIMATION_H__
#define __TEXTURE_TOOL_ANIMATION_H__

#include "TextureTool.h"
#include <string>
#include <vector>


class TextureToolAnimation{
    public:
        static const TextureToolAnimation plain;
        static const TextureToolAnimation water;

    private:
        TextureToolAnimation(std::string path);
        std::vector<TextureTool> textures;

    public:
        const TextureTool& getTexture(uint x) const;
        uint getSize() const;
};

#endif