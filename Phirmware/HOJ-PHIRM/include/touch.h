#include <Arduino.h>

enum touchPins {
    TOUCH0,
    TOUCH2,
    TOUCH3,
    TOUCH4,
    TOUCH5,
};

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