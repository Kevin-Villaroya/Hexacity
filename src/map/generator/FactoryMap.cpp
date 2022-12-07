#include "FactoryMap.h"
#include <algorithm>
#include <iostream>
#include <limits.h>
#include <cmath>

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
    unsigned int quantityRivers = map->getSize() / 100;

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
    unsigned int width = map->getWidth();
    unsigned int height = map->getHeight();

    unsigned int min = (2 + std::max(width, height) / 20);
    unsigned int max = (map->getWidth() - (2 + std::max(width, height) / 20) * 2 - 1);
    unsigned int x = min + std::rand() % max;

    min = (2 + std::max(width, height) / 20);
    max = (map->getHeight() - (2 + std::max(width, height) / 20) * 2 - 1);
    unsigned int y = min + std::rand() % max;

    return sf::Vector2f(x, y);
}

void FactoryMap::generateRiver(std::shared_ptr<Map> map, sf::Vector2f positionSource){
    map->get(positionSource.x, positionSource.y).setTexture(TextureToolAnimation::water);

    sf::Vector2f currentCase;
    sf::Vector2f movement = FactoryMap::getRandomMovement();

    currentCase = positionSource;

    bool arrivedToSea = FactoryMap::closeToSea(map, positionSource);

    while(!arrivedToSea && (movement.x != 0 || movement.y != 0)){
        currentCase = FactoryMap::getNextRiverCasePosition(map, currentCase, movement);
        map->get(currentCase.x, currentCase.y).setTexture(TextureToolAnimation::water);

        arrivedToSea = FactoryMap::closeToSea(map, currentCase);
    }
}

bool FactoryMap::closeToSea(std::shared_ptr<Map> map, sf::Vector2f position){
    unsigned int width = map->getWidth();
    unsigned int height = map->getHeight();

    unsigned int sizeSea = 2 + std::max(width, height) / 20;

    return position.x < sizeSea || position.x >= width - sizeSea || position.y < sizeSea || position.y >= height - sizeSea;
}

sf::Vector2f FactoryMap::getNextRiverCasePosition(std::shared_ptr<Map> map, sf::Vector2f position, sf::Vector2f& movement){
    //50% not change - 20% a bit to the left - 20% a bit to the right - 5% a lot on the left - 5% a lot on the right
    int movementEvolution = std::rand() % 100;
    sf::Vector2f oldMovement = movement;

    if(movementEvolution <= 70){
        //change nothing
    }else if(movementEvolution <= 80){
        //on left
        movement.x = oldMovement.x * cos(20) - oldMovement.y * sin(20);
        movement.y = oldMovement.x * sin(20) + oldMovement.y * cos(20);
    }else if(movementEvolution <= 90){
        movement.x = oldMovement.x * std::cos(-20) - oldMovement.y * std::sin(-20);
        movement.y = oldMovement.x * std::sin(-20) + oldMovement.y * std::cos(-20);
    }else if(movementEvolution <= 95){
        movement.x = oldMovement.x * std::cos(45) - oldMovement.y * std::sin(45);
        movement.y = oldMovement.x * std::sin(45) + oldMovement.y * std::cos(45);
    }else if(movementEvolution <= 100){
        movement.x = oldMovement.x * std::cos(-45) - oldMovement.y * std::sin(-45);
        movement.y = oldMovement.x * std::sin(-45) + oldMovement.y * std::cos(-45);
    }

    movement.x = std::max((float)-1, movement.x);
    movement.x = std::min((float)1, movement.x);
    movement.y = std::max((float)-1, movement.y);
    movement.y = std::min((float)1, movement.y);

    return sf::Vector2f(position.x + movement.x, position.y + movement.y);
}

sf::Vector2f FactoryMap::getRandomMovement(){
    int x;
    int y;
    
    do{
        x = -1 + std::rand() % 2;
        y = -1 + std::rand() % 2;
    }while(x == 0 && y == 0);

    return sf::Vector2f(x ,y);
}

void FactoryMap::generateLakes(std::shared_ptr<Map> map){

}

void FactoryMap::generateMountainRanges(std::shared_ptr<Map> map){

}

void FactoryMap::generateForest(std::shared_ptr<Map> map){

}

void FactoryMap::generateCities(std::shared_ptr<Map> map){

}