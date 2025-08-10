// owe
#include "inputs.h"
#include "touch.h"
#include "gesture.h"
#include <Arduino.h>


Controller::Controller(BleGamepad* gamepad)
{
    
}

void Controller::update()
{
    switch (gestureEngine->getGesture())
    {
    case GESTURE_PUNCH:
        _gamepad->press(BUTTON_100);
        break;
    case GESTURE_SWING:
    
    
    default:
        break;
    }
    // Update each sensor
    for (int i = 0; i < 5; i++) {
        if (sensors[i]) {
            sensors[i]->update();
            int state = sensors[i]->getSensorState();
            // Handle the sensor state, e.g., update gamepad buttons
            switch (state) {
                case TOUCHTHUMB:
                    _gamepad->press(BUTTON_1);
                    break;
                case TOUCHUPPERPALM:
                    _gamepad->release(BUTTON_1);
                    break;
                case TOUCHLOWERPALM:
                    // Handle lower palm touch
                    break;
                default:
                    break;
            }
        }
    }
}