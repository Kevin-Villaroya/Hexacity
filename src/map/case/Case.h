#ifndef __CASE_H__
#define __CASE_H__

#include "../biome/Biome.h"

class Case{
  private:
    Biome& biome;
    unsigned int height;
    unsigned int temperature;
    unsigned int humidity;
  
  public:
    Case(unsigned int height = 0);
    Case(unsigned int height, unsigned int temperature);
    Case(unsigned int height, unsigned int temperature, unsigned int humidity);

    unsigned int getHeight() const;
    unsigned int getTemperature() const;
    unsigned int getHumidity() const;

    void setHeight(unsigned int height);
    void setTemperature(unsigned int temperature);
    void setHumidity(unsigned int humidity);
    
};

#endif