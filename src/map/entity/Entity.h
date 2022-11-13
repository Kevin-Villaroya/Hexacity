#ifndef __ENTIY_H__
#define __ENTIY_H__

#include <SFML/sprite>

class Entity{
    private:
        sf::Vector2f size;
        sf::Vector2f position;

        AnimatedTexture texture;

    public:
        Entity();
        virtual void update(float dt) = 0;
};

#endif