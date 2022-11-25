#ifndef __FACTORY_MAP_H__
#define __FACTORY_MAP_H__

#include <memory>
#include "Map.h"

class FactoryMap{
public:
    static std::shared_ptr<Map> generateMap(size_t width, size_t height);
};

#endif