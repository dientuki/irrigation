/*
  Irrigation.h - Library for flashing Morse code.
  Created by David A. Mellis, November 2, 2007.
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
