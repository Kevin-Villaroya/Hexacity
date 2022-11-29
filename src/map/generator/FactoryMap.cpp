#include "FactoryMap.h"
#include <algorithm>
#include <iostream>

std::shared_ptr<Map> FactoryMap::generateMap(size_t width, size_t height){
    std::srand(time(NULL));

    std::shared_ptr<Map> map = std::make_unique<Map>(width, height);

    FactoryMap::generateSea(map);
    FactoryMap::generateRivers(map);
    FactoryMap::generateLakes(map);
    FactoryMap::generateMountainRanges(map);
    FactoryMap::generateForest(map);
    FactoryMap::generateCities(map);

    /*for(unsigned int i = 0; i < width; i++){
        for(unsigned int j = 0; j < height; j++){
            if(i == j || i == j-1 || i == j+1 || j == i-1 || j == i+1){
                map->get(i, j).setTexture(TextureToolAnimation::water);
            }else if(i % 2 == 0){
                map->addEntity(sf::Vector2f(i, j), TypeEntity::forest);
            }else{
                map->addEntity(sf::Vector2f(i, j), TypeEntity::house);
            }

            if(i == 0){
                map->setHeightBlock(i, j, 1);
            }
        }
    }

    map->addEntity(sf::Vector2f(2, 6), TypeEntity::mountain);
    */   

    return map;
}

void FactoryMap::generateSea(std::shared_ptr<Map> map){
    unsigned int width = map->getWidth();
    unsigned int height = map->getHeight();

    unsigned int sizeSea = 1 + std::max(width, height) / 20;

    for(unsigned int i = 0; i < width; i++){
        for(unsigned int j = 0; j < height; j++){

            if(i < sizeSea || i >= width - sizeSea || j < sizeSea || j >= height - sizeSea){
                map->get(i, j).setTexture(TextureToolAnimation::water);
            }

        }
    }
}

void FactoryMap::generateRivers(std::shared_ptr<Map> map){
    /* - choix du nombre de riviere
    - choix de la source de la riviere et de sa taille (largeur)
    - choix de la prochaine direction de la rivier (proba)
    - choix a moment clé de se séparer et changer la taille des deux qui en resultent
    - si croisement avec une autre rivière, joindre les deux */


    unsigned int quantityRivers = map->getSize() / 30;

    if(quantityRivers > 0){
        quantityRivers = 1 + (std::rand() % quantityRivers);
    }else{
        quantityRivers = 1;
    }

    while(quantityRivers > 0){
        sf::Vector2f positionSource = FactoryMap::getPositionSource(map);
        FactoryMap::generateRiver(map, positionSource);

        quantityRivers--;
    }
}

sf::Vector2f FactoryMap::getPositionSource(std::shared_ptr<Map> map){
    //plus on est haut, plus on peut etre une source
    //plus on est loin de zone d'eau plus on peut etre source

    return sf::Vector2f(0, 0);
}

void FactoryMap::generateRiver(std::shared_ptr<Map> map, sf::Vector2f positionSource){

}

void FactoryMap::generateLakes(std::shared_ptr<Map> map){

}

void FactoryMap::generateMountainRanges(std::shared_ptr<Map> map){

}

void FactoryMap::generateForest(std::shared_ptr<Map> map){

}

void FactoryMap::generateCities(std::shared_ptr<Map> map){

}