#ifndef __ENTIY_H__
#define __ENTIY_H__

#include "../animation/AnimatedSprite.h"
#include "TypeEntity.h"
#include <SFML/System/Vector3.hpp>

class Entity{
    private:
        sf::Vector3f position;
        sf::Vector2f size;

        AnimatedSprite sprite;
        TypeEntity type;

    public:
        Entity(const sf::Vector3f& position);
        Entity(const sf::Vector3f& position, const TextureToolAnimation& texture);
        Entity(const sf::Vector3f& position, const sf::Vector2f& size, const TextureToolAnimation& texture);

        virtual void update() = 0;
        virtual TypeEntity getType() const = 0;

        const sf::Vector2f& getSize() const;
        void setSize(const sf::Vector2f& size);

        const AnimatedSprite& getSprite() const;
        AnimatedSprite& getSprite();
};

#endif