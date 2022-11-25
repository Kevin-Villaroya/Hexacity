#ifndef __FOREST_H__
#define __FOREST_H__

#include "../../Entity.h"

class Forest : public Entity{
    public:
        Forest(const sf::Vector3f& position);

        void update() override;
        TypeEntity getType() const override;
};

#endif