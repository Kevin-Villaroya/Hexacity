#include "Case.h"

Case::Case(unsigned int height) : Case(height, 0){}

Case::Case(unsigned int height, unsigned int temperature) : Case(height, temperature, 0){}

Case::Case(unsigned int height, unsigned int temperature, unsigned int humidity) : biome(Biome::NULL_BIOME), height(height), temperature(temperature), humidity(humidity) {}

unsigned int Case::getHeight() const{
  return this->height;
}

unsigned int Case::getTemperature() const{
  return this->temperature;
}

unsigned int Case::getHumidity() const{
  return this->humidity;
}

void Case::setHeight(unsigned int height){
  this->height = height;
}

void Case::setTemperature(unsigned int temperature){
  this->temperature = temperature;
}

void Case::setHumidity(unsigned int humidity){
  this->humidity = humidity;
}