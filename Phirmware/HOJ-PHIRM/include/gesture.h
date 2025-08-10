#include <Arduino.h>
#include "IMU.h"

enum gestures{
    GESTURE_PUNCH,
    GESTURE_SWING,
    GESTURE_ROTATE
};

class Gesture
{
    private:
    IMU* _imu;

    public:
    Gesture(IMU* imu);
    void update();
    int getGesture();
};