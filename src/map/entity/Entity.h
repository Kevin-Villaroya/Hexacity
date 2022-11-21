#ifndef __ENTIY_H__
#define __ENTIY_H__

#include "../animation/AnimatedSprite.h"
#include "TypeEntity.h"

class Entity{
    private:
        sf::Vector2f position;
        sf::Vector2f size;

        AnimatedSprite sprite;
        TypeEntity type;

    public:
        Entity();
        Entity(const sf::Vector2f& position);
        Entity(const sf::Vector2f& position, const TextureToolAnimation& texture);
        Entity(const sf::Vector2f& position, const sf::Vector2f& size, const TextureToolAnimation& texture);

        virtual void update() = 0;
        virtual TypeEntity getType() const = 0;

        const AnimatedSprite& getSprite() const;
        AnimatedSprite& getSprite();
};

#endif