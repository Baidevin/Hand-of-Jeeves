#pragma once
#include <Arduino.h>

enum bounds {
  Lower = 20,
  Upper = 40,
};

enum sensorState {
  TOUCHTHUMB,
  TOUCHLOWERPALM,
  TOUCHUPPERPALM
};

enum touchSensors {
  TOUCH0 = 4,
  TOUCH1 = 0,
  TOUCH2 = 2,
  TOUCH3 = 15,
  TOUCH4 = 13,
  TOUCH5 = 12,
  TOUCH6 = 14,
  TOUCH7 = 27
};

#define BUFFER_LENGTH 5

class TouchSensor
{
    public:
        TouchSensor(int pin) : _pin(pin) {
        pinMode(_pin, INPUT);
        }
    
        int getSensorState();
        void update();
    
    private:
        int _pin;
        int _values[BUFFER_LENGTH];
        int _itr;
        int _sensorReference;

};