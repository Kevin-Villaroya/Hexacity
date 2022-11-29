#ifndef __FACTORY_MAP_H__
#define __FACTORY_MAP_H__

#include <memory>
#include "Map.h"

class FactoryMap{
public:
    static std::shared_ptr<Map> generateMap(size_t width, size_t height);
private:
    static void generateSea(std::shared_ptr<Map> map);
    static void generateRivers(std::shared_ptr<Map> map);
    static void generateLakes(std::shared_ptr<Map> map);

    static void generateMountainRanges(std::shared_ptr<Map> map);
    static void generateForest(std::shared_ptr<Map> map);

    static void generateCities(std::shared_ptr<Map> map);

    static sf::Vector2f getPositionSource(std::shared_ptr<Map> map);
    static void generateRiver(std::shared_ptr<Map> map, sf::Vector2f positionSource);
};

#endif