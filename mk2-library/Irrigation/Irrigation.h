/*
  Irrigation.h - Library for reading a moisture sensor.
  Created by Juan "Dientuki" Farias, October 19, 2021.
  Released into the public domain.
*/

#ifndef Irrigation_h
#define Irrigation_h

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

class Irrigation
{
  public:
    Irrigation(int sensor);
    int measure();
  private:
    int _sensor;
};

#endif
