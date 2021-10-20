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
    Irrigation(int sensor, int relay, int threshold);
    void work();
    int getHumidity();
    int getValve();
  private:
    int _sensor;
    int _relay;
    int _threshold;
    void measure();
    void watering();
};

#endif
