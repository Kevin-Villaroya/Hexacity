#include "RenderingEngine.h"
#include <iostream>
#include <cmath>

#include "../../tool/SpriteTool.h"

RenderingEngine::RenderingEngine(Map& map, unsigned int fps, unsigned int widthWindow, unsigned int heightWindow) : map(map), view(sf::Vector2f(0, 0), sf::Vector2f(map.getDrawableWidth(), map.getDrawableHeight())), window(sf::VideoMode(widthWindow, heightWindow), "Hexacity"){
	this->window.setFramerateLimit(fps);

    sf::Vector2<float> centerView = this->getCenterDrawableMap();
	this->view.setCenter(centerView.x, centerView.y);
	this->window.setView(this->view);

	this->entranceAnimation();
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
	std::list<std::reference_wrapper<SpriteTool>> drawables = this->getMapDrawables();

	while(!drawables.empty()){
		SpriteTool& sprite = drawables.front().get();

		this->window.draw(sprite);
		drawables.pop_front();
	}
}

void RenderingEngine::entranceAnimation(){
	int framesDuration = 2;
	auto animation = [](sf::Vector2<float>& position){ position.y -= 1; position.x -= 1; };
	int globalOffset = fmax(this->map.getWidth(), this->map.getHeight());

	for(unsigned int i = 0; i < this->map.getWidth(); i++){
		for(unsigned int j = 0; j < this->map.getHeight(); j++){
			Block& block = this->map.get(sf::Vector2<float>(i, j));

			int blockOffset = fmin(block.getPosition().x - block.getPosition().y, -block.getPosition().x + block.getPosition().y);
			int offset = globalOffset + blockOffset;

			block.animate(sf::Vector2<float>(block.getPosition().x + offset, block.getPosition().y + offset), animation, framesDuration);
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

std::list<std::reference_wrapper<SpriteTool>> RenderingEngine::getMapDrawables(){
	std::list<std::reference_wrapper<SpriteTool>> drawables;

	for(unsigned int i = 0; i < this->map.getWidth() ; i++){
		for(unsigned int j = 0; j < this->map.getHeight(); j++){
			sf::Vector2<float> casePosition(i, j);

			Block& currentCase = this->map.get(casePosition);
			SpriteTool& sprite = currentCase.getSprite();

			this->setCaseSpritePosition(sprite, currentCase.getPosition(), currentCase.getHeight());

			drawables.push_back(sprite);
		}
	}

	return drawables;
}

sf::Vector2<float> RenderingEngine::getCenterDrawableMap(){
	sf::Vector2<float> centerMap = sf::Vector2<float>(this->map.getWidth() / 2, this->map.getHeight() / 2);

	return this->convertMapPositionToWindowPosition(centerMap);
}

void RenderingEngine::setCaseSpritePosition(SpriteTool& sprite, const sf::Vector2<float>& position, unsigned int height){
	sf::Vector2<float> isometricPosition = this->convertMapPositionToWindowPosition(position);

	isometricPosition.y -= (height * sprite.getTexture()->getSize().y / 2);

	sprite.setPosition(isometricPosition.x, isometricPosition.y);
}

sf::Vector2<float> RenderingEngine::convertMapPositionToWindowPosition(const sf::Vector2<float>& position){
	sf::Vector2<float> windowPosition = this->transformEuclidianPositionToIsometric(position);

	windowPosition.x = windowPosition.x * (this->map.get(sf::Vector2<float>(0, 0)).getSprite().getTexture()->getSize().x / 2);
	windowPosition.y = windowPosition.y * (this->map.get(sf::Vector2<float>(0, 0)).getSprite().getTexture()->getSize().y / 4);

	return windowPosition;
}

sf::Vector2<float> RenderingEngine::transformEuclidianPositionToIsometric(const sf::Vector2<float>& position){
	sf::Vector2<float> isometricPosition;

	unsigned int x = position.x;
	unsigned int y = position.y;

	isometricPosition.x = x - y;
	isometricPosition.y = x + y;

	return isometricPosition;
}