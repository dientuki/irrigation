/*
  Irrigation.cpp - Library for flashing Morse code.
  Created by David A. Mellis, November 2, 2007.
  Released into the public domain.
*/

#include "Irrigation.h"

const int AirValue = 630;   //you need to replace this value with Value_1
const int WaterValue = 310;  //you need to replace this value with Value_2
int soilMoistureValue = 0;
int soilmoisturepercent=0;

Irrigation::Irrigation(int sensor){
  _sensor = sensor;
}

int Irrigation::measure(){
  
  soilMoistureValue = analogRead(_sensor);  //put Sensor insert into soil
  soilmoisturepercent = map(soilMoistureValue, AirValue, WaterValue, 0, 100);
  if(soilmoisturepercent >= 100)
  {
    return 100;
  }
  else if(soilmoisturepercent <=0)
  {
    return 0;
  }
  else if(soilmoisturepercent >0 && soilmoisturepercent < 100)
  {
    return soilmoisturepercent;    
  }
}
