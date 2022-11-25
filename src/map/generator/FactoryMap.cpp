#include "FactoryMap.h"

std::shared_ptr<Map> FactoryMap::generateMap(size_t width, size_t height){
    std::shared_ptr<Map> map = std::make_unique<Map>(width, height);

    for(unsigned int i = 0; i < width; i++){
        for(unsigned int j = 0; j < height; j++){
            if(i == j || i == j-1 || i == j+1 || j == i-1 || j == i+1){
                map->get(i, j).setTexture(TextureToolAnimation::water);
            }else if(i % 2 == 0){
                map->addEntity(sf::Vector2f(i, j), TypeEntity::forest);
            }else{
                map->addEntity(sf::Vector2f(i, j), TypeEntity::house);
            }

            if(i == 0){
                //this->map.setHeightBlock(i, j, 1);
            }
        }
    }

    map->addEntity(sf::Vector2f(2, 6), TypeEntity::mountain);    

    return map;
}