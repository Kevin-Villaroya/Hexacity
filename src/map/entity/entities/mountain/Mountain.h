#ifndef __MOUNTAIN_H__
#define __MOUNTAIN_H__

#include "../../Entity.h"

class Mountain : public Entity{
    public:
        Mountain(const sf::Vector3f& position);

        void update() override;
        TypeEntity getType() const override;
};

#endif