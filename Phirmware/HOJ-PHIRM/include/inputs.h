#include "BleGamepad.h"
#include "touch.h"
class Controller
{
    private:
        TouchSensor* sensors[5];
        BleGamepad* _gamepad;

    public:
        Controller(BleGamepad* gamepad);

        void update();

};