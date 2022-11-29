#include "RenderingEngine.h"
#include <iostream>
#include <cmath>
#include <SFML/Graphics/Color.hpp>

RenderingEngine::RenderingEngine(std::shared_ptr<Map> map, unsigned int fps, unsigned int widthWindow, unsigned int heightWindow) : map(map), view(sf::Vector2f(0, 0), sf::Vector2f(map.get()->getDrawableWidth(), map.get()->getDrawableLenght())), window(sf::VideoMode(widthWindow, heightWindow), "Hexacity"){
	this->window.setFramerateLimit(fps);

	this->view.setCenter(32, this->view.getSize().y / 2);
	this->window.setView(this->view);

	//this->entranceAnimation();
}

bool RenderingEngine::tick(){
	this->render();

	return this->checkEvents();
}

void RenderingEngine::render(){
	this->window.clear(sf::Color::Black);
	
	this->drawMap();

	this->window.display();
}

void RenderingEngine::drawMap(){
	std::list<sf::Sprite*> drawables = this->getMapDrawables();

	while(!drawables.empty()){
		sf::Sprite* sprite = drawables.front();

		this->window.draw(*sprite);
		drawables.pop_front();
	}
}

void RenderingEngine::entranceAnimation(){
	int framesDuration = 2;
	auto animation = [](sf::Vector3<float>& position){ position.y -= 1; position.x -= 1;};
	int globalOffset = fmax(this->map->getWidth(), this->map->getHeight());

	for(unsigned int i = 0; i < this->map.get()->getWidth(); i++){
		for(unsigned int j = 0; j < this->map.get()->getHeight(); j++){
			for(unsigned int k = 0; k < this->map.get()->getColumn(i, j).size(); k++){
				Block& block = this->map.get()->get(i, j, k);

				int blockOffset = fmin(block.getPosition().x - block.getPosition().y, -block.getPosition().x + block.getPosition().y);
				int offset = globalOffset + blockOffset;

				block.animateBlock(sf::Vector3<float>(block.getPosition().x + offset, block.getPosition().y + offset, block.getPosition().z), animation, framesDuration);
			}
		}
	}
}

bool RenderingEngine::checkEvents(){
	sf::Event event;

	while (window.pollEvent(event)){
		if (event.type == sf::Event::Closed){
			window.close();
			return false;
		}else if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
			if(event.type == sf::Event::MouseMoved){
				sf::Vector2i mousePosition = sf::Mouse::getPosition(this->window);

				this->view.move(-1*(mousePosition.x - event.mouseMove.x), -1*(mousePosition.y - event.mouseMove.y));
				this->window.setView(this->view);
			}
		}else if(event.type == sf::Event::MouseWheelScrolled){
			if(event.mouseWheelScroll.delta > 0){
				this->view.zoom(0.9);
			}else{
				this->view.zoom(1.1);
			}

			this->window.setView(this->view);
		}
	}

	return true;
}

std::list<sf::Sprite*> RenderingEngine::getMapDrawables(){
	std::list<sf::Sprite*> drawables;
	std::list<sf::Sprite*> blockDrawables;
	std::list<sf::Sprite*> entityDrawables;

	for(unsigned int i = 0; i < this->map->getWidth() ; i++){
		for(unsigned int j = 0; j < this->map->getHeight(); j++){
			for(unsigned int k = 0; k < this->map.get()->getColumn(i, j).size(); k++){				

				Block& currentCase = this->map->get(i, j, k);
				sf::Sprite& blockSprite = currentCase.getSprite();

				this->setCaseSpritePosition(blockSprite, currentCase.getPosition(), currentCase.getHeight());

				blockDrawables.push_back(&blockSprite);

				if(currentCase.hasEntity()){
					Entity& entity = currentCase.getEntity();
					sf::Sprite& entitySprite = entity.getSprite();

					this->setEntitySpritePosition(blockSprite, entity, currentCase.getHeight());

					entityDrawables.push_back(&entitySprite);
				}
			}
		}
	}

	drawables.insert(std::end(drawables), std::begin(blockDrawables), std::end(blockDrawables));
	drawables.insert(std::end(drawables), std::begin(entityDrawables), std::end(entityDrawables));

	return drawables;
}

sf::Vector3<float> RenderingEngine::getCenterDrawableMap(){
	sf::Vector3<float> centerMap = sf::Vector3<float>(this->map->getWidth() / 2, this->map->getHeight() / 2, 0);

	return centerMap;
}

void RenderingEngine::setEntitySpritePosition(sf::Sprite& blockSprite, Entity& entity, unsigned int height){
	sf::Vector3<float> isometricPosition = this->convertMapPositionToWindowPosition(entity.getPosition());
	sf::Sprite& entitySprite = entity.getSprite();

	isometricPosition.y -= blockSprite.getTexture()->getSize().y * 0.5;
	isometricPosition.y -= (isometricPosition.z * entitySprite.getTexture()->getSize().y / 2);

	isometricPosition.y -= entity.getSize().y * entitySprite.getTexture()->getSize().y / 8;
	isometricPosition.y -= height *  entitySprite.getTexture()->getSize().y / 2;

	entitySprite.setPosition(isometricPosition.x, isometricPosition.y);
}

void RenderingEngine::setCaseSpritePosition(sf::Sprite& sprite, const sf::Vector3<float>& position, unsigned int height){
	sf::Vector3<float> isometricPosition = this->convertMapPositionToWindowPosition(position);

	isometricPosition.y -= (height * sprite.getTexture()->getSize().y / 2);

	sprite.setPosition(isometricPosition.x, isometricPosition.y);
}

sf::Vector3<float> RenderingEngine::convertMapPositionToWindowPosition(const sf::Vector3<float>& position){
	sf::Vector3<float> newPosition = this->transformEuclidianPositionToIsometric(position);

	newPosition.x = newPosition.x * (this->map.get()->get(sf::Vector2<float>(0, 0)).getSprite().getTexture()->getSize().x / 2);
	newPosition.y = newPosition.y * (this->map.get()->get(sf::Vector2<float>(0, 0)).getSprite().getTexture()->getSize().y / 4);

	return newPosition;
}

sf::Vector3<float> RenderingEngine::transformEuclidianPositionToIsometric(const sf::Vector3<float>& position){
	sf::Vector3<float> isometricPosition;

	int x = position.x;
	int y = position.y;
	int z = position.z;

	isometricPosition.x = x - y;
	isometricPosition.y = x + y;
	isometricPosition.z = z;

	return isometricPosition;
}