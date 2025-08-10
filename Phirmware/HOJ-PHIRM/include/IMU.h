#pragma once
#include <Arduino.h>
#include "FastIMU.h"
// #include <IMU.h>

class IMU {
public:
    IMU();
    void begin();
    void update();
    float getAccelX();
    float getAccelY();
    float getAccelZ();
    float getGyroX();
    float getGyroY();
    float getGyroZ();

private:
    float accelX, accelY, accelZ;
    float gyroX, gyroY, gyroZ;
    BMI160 _BMI;
    calData calib = { 0 };
    void calibrate();
    AccelData accelData;    //Sensor data
    GyroData gyroData;
    MagData magData;  

};