#include <Arduino.h>
#include "IMU.h"

class Gesture
{
    private:
    IMU* _imu;

    public:
    Gesture(IMU* imu);
    void update();
    int getGesture();
};