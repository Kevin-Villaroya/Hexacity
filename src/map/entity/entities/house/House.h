#ifndef __HOUSE_H__
#define __HOUSE_H__

#include "../../Entity.h"

class House : public Entity{
    public:
        void update() override;
        TypeEntity getType() const override;
};

#endif