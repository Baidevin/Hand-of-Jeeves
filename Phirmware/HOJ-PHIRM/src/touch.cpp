#include "touch.h"

#include <Arduino.h>


TouchSensor::TouchSensor(int pin)
{
    _pin = pin;
    pinMode(pin, INPUT);
    _itr = 0;
}

bool TouchSensor::isTouched()
{
    int avg = 0;
    for (int i=0; i < BUFFER_LENGTH - 1; i++)
    {
        avg += _values[i];
    }
    avg = avg / BUFFER_LENGTH;

    return avg < ON_THRESH;
}

void TouchSensor::update()
{
    _itr++;
    _itr = _itr % 5;
    _values[_itr] = touchRead(_pin);

}