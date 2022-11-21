#ifndef __FACTORY_ENTITY_EXCEPTION_H__
#define __FACTORY_ENTITY_EXCEPTION_H__

#include "TypeEntity.h"
#include <stdexcept>

class FactoryEntityException : public std::invalid_argument{
    private:
        static std::string getTypeName(TypeEntity type){
            switch(type){
                case TypeEntity::forest:
                    return "Forest";
                    break;
                case TypeEntity::house:
                    return "House";
                    break;
                default:
                    return "NOT FOUND";
            }
        }

    public:
        FactoryEntityException(TypeEntity type) : std::invalid_argument("Invalid argument in FactoryEntity given " + FactoryEntityException::getTypeName(type)) {}
};

#endif