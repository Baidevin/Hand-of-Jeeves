#include <Arduino.h>

enum touchPins {
    TOUCH0,
    TOUCH2,
    TOUCH3,
    TOUCH4,
    TOUCH5,
};

class TouchSensor
{
    public:
        TouchSensor(int pin) : _pin(pin) {
        pinMode(_pin, INPUT);
        }
    
        bool isTouched() {
        return digitalRead(_pin) == HIGH;
        }
    
    private:
        int _pin;
};