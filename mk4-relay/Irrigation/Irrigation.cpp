/*
  Irrigation.h - Library for reading a moisture sensor.
  Created by Juan "Dientuki" Farias, October 19, 2021.
  Released into the public domain.
*/

#include "Irrigation.h"

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

const int AirValue = 630;   //you need to replace this value with Value_1
const int WaterValue = 310;  //you need to replace this value with Value_2
int soilMoistureValue = 0;
int soilmoisturepercent=0;
int humidity = 0;
bool isOpen = false;

Irrigation::Irrigation(int sensor, int relay, int threshold){
  _sensor = sensor;
  _relay = relay;
  _threshold = threshold;
  pinMode(_relay, OUTPUT);
}

int Irrigation::getHumidity() {
  return humidity;
}

int Irrigation::getValve() {
  return isOpen;
}

void Irrigation::work() {
  measure();
  watering();
}

void Irrigation::measure(){

  soilMoistureValue = analogRead(_sensor);  //put Sensor insert into soil
  Serial.println(soilMoistureValue);
  soilmoisturepercent = map(soilMoistureValue, AirValue, WaterValue, 0, 100);
  
  if(soilmoisturepercent >0 && soilmoisturepercent < 100) {
    humidity = soilmoisturepercent;
  } else {
    if(soilmoisturepercent >= 100){
      humidity = 100;
    }
    
    if(soilmoisturepercent <= 0){
      humidity = 0;
    }    
  }
}

void Irrigation::watering(){
  if (humidity <= _threshold) {
    digitalWrite(_relay, LOW);
    isOpen = true;
  } else {
    digitalWrite(_relay, HIGH);
    isOpen = false;    
  }
}
