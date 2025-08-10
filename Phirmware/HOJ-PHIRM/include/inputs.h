#pragma once
#include "BleGamepad.h"
#include "touch.h"
#include "gesture.h"
class Controller
{
    private:
        BleGamepad* _gamepad;
        // Gesture* gestureEngine;

        TouchSensor indexFinger = TouchSensor(TOUCH0);
        TouchSensor middleFinger = TouchSensor(TOUCH1);
        TouchSensor ringFinger = TouchSensor(TOUCH2);
        TouchSensor pinkieFinger = TouchSensor(TOUCH3);

        // TouchSensor dUpSensor = TouchSensor(TOUCH4);
        // TouchSensor dDownSensor = TouchSensor(TOUCH5);
        // TouchSensor dLeftSensor = TouchSensor(TOUCH6);
        // TouchSensor dRightSensor = TouchSensor(TOUCH7);

        void handleFingerSensor(int state, int button1, int button2, int button3);

    public:
        Controller(BleGamepad* gamepad);

        void update();

};