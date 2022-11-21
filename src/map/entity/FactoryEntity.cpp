#include "FactoryEntity.h"
#include "FactoryEntityException.h"

#include "entities/forest/Forest.h"
#include "entities/house/House.h"

std::unique_ptr<Entity> FactoryEntity::create(TypeEntity type){
    switch(type){
        case TypeEntity::forest:
            return std::make_unique<Forest>();
            break;
        case TypeEntity::house:
            return std::make_unique<House>();
            break;
        default:
            throw FactoryEntityException(type);
    }
}