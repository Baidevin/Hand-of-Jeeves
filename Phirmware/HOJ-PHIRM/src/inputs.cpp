// owe
#include "inputs.h"
#include "touch.h"
#include <Arduino.h>


Controller::Controller(BleGamepad* gamepad)
{
    
}

void Controller::update()
{
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