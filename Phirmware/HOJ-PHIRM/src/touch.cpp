#include "touch.h"

#include <Arduino.h>

TouchSensor::TouchSensor(int pin, bool isDPad){
    _pin = pin;
    pinMode(pin, INPUT);
    _sensorReference = touchRead(pin);
    _isDPad = isDPad;
}

int TouchSensor::getSensorState(){


    double average = 0;
    sensorState state;
    for(int i = 0; i < BUFFER_LENGTH; i++){
        average += _values[i];
    }
    average = average / BUFFER_LENGTH;
    

    if (_isDPad)
    {
        return average > DPAD_THRESH ? DPAD_TOUCHED : DPAD_RELEASE;
    }

    if (average <= LOWER){
        state = TOUCHTHUMB;
    } else if (average >= UPPER){
        state = NONE;
    } else {
        state = TOUCHLOWERPALM;
    }
    
    return state;
}

void TouchSensor::update() {
    _itr++;
    _itr = _itr % BUFFER_LENGTH;
    _values[_itr] = touchRead(_pin);
}