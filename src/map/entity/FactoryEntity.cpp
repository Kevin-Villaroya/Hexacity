#include "FactoryEntity.h"
#include "FactoryEntityException.h"

#include "entities/forest/Forest.h"
#include "entities/house/House.h"
#include "entities/mountain/Mountain.h"

std::shared_ptr<Entity> FactoryEntity::create(TypeEntity type, const sf::Vector3f& position){
    switch(type){
        case TypeEntity::forest:
            return std::make_shared<Forest>(position);
            break;
        case TypeEntity::house:
            return std::make_shared<House>(position);
            break;
        case TypeEntity::mountain:
            return std::make_shared<Mountain>(position);
            break;
        default:
            throw FactoryEntityException(type);
    }
}