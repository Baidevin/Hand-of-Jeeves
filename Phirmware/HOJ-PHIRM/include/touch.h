#pragma once
#include <Arduino.h>

#define TOUCH0 1
#define TOUCH2 2
#define TOUCH3 3
#define TOUCH4 4

#define BUFFER_LENGTH 5

#define ON_THRESH 10
class TouchSensor
{
    public:
        TouchSensor(int pin);
    
        bool isTouched();
        void update();
    private:
        int _pin;
        int _values[BUFFER_LENGTH];

        int _itr;
};