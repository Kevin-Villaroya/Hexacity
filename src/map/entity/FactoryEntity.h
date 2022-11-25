#ifndef __FACTORY_ENTITY_H__
#define __FACTORY_ENTITY_H__

#include "Entity.h"
#include "TypeEntity.h"
#include <memory>

class FactoryEntity{
    public:
        static std::shared_ptr<Entity> create(TypeEntity type, const sf::Vector3f& position);
};

#endif