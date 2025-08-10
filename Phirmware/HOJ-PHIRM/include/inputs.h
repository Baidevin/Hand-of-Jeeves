#include "BleGamepad.h"
#include "touch.h"
class Controller
{
    private:
        BleGamepad* _gamepad;
        TouchSensor* sensors[5];
        Gesture* gestureEngine;

    public:
        Controller(BleGamepad* gamepad);

        void update();

};