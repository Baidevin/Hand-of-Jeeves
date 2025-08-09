#include "touch.h"

#include <Arduino.h>

TouchSensor::TouchSensor(int pin){
    pinMode(pin, INPUT);
    _sensorReference = touchRead(pin);
}

int TouchSensor::getSensorState(){

    double average = 0;
    sensorState state;
    for(int i = 0; i < BUFFER_LENGTH; i++){
        average += _values[i];
    }
    average = average / BUFFER_LENGTH;

    if (average <= Lower){
        state = TOUCHTHUMB;
    } else if (average >= Upper){
        state = TOUCHUPPERPALM;
    } else {
        state = TOUCHLOWERPALM;
    }
    
    return state;
}

void TouchSensor::update() {
    _itr++;
    _itr = _itr % 5;
    _values[_itr] = touchRead(_pin);
}