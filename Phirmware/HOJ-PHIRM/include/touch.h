#pragma once
#include <Arduino.h>


enum sensorState {
  NONE,
  TOUCHTHUMB,
  TOUCHLOWERPALM,
  TOUCHUPPERPALM
};

enum dPadState
{
  DPAD_TOUCHED,
  DPAD_RELEASE
};

#define DPAD_THRESH 10

#define  LOWER 20
#define  UPPER 40


#define TOUCH0  4
#define TOUCH1  15
#define TOUCH2  12
#define TOUCH3  2
#define TOUCH4  0
#define TOUCH5  2
#define TOUCH6  13
#define TOUCH7  14

#define BUFFER_LENGTH 5

class TouchSensor
{
    public:
        TouchSensor(int pin, bool isDPad = false);

        int getSensorState();
        void update();
    
    private:
        bool _isDPad;
        int _pin;
        int _values[BUFFER_LENGTH];
        int _itr;
        int _sensorReference;
};