#include <Arduino.h>
#include <IMU.h>
#include <Wire.h>

const int Addr = 0x68;

IMU::IMU()
{
    // begin();
}

void IMU::begin()
{
    Wire.begin();
    Wire.beginTransmission(Addr);
    Wire.write(0x6B); // PWR_MGMT_1 register
    Wire.write(0x00);    // Set to zero to wake up the MPU-6050
    Wire.endTransmission(true);
}

void IMU::update()
{
    Wire.beginTransmission(Addr);
    Wire.write(0x3B);
    Wire.endTransmission(false);
    Wire.requestFrom(Addr, 6, true); 

    accelX = (Wire.read() << 8 | Wire.read()) / 16384.0; 
    accelY = (Wire.read() << 8 | Wire.read()) / 16384.0;
    accelZ = (Wire.read() << 8 | Wire.read()) / 16384.0;

    Wire.beginTransmission(Addr);
    Wire.write(0x43); 
    Wire.endTransmission(false);
    Wire.requestFrom(Addr, 6, true); 
    gyroX = (Wire.read() << 8 | Wire.read()) / 131.0; 
    gyroY = (Wire.read() << 8 | Wire.read()) / 131.0;
    gyroZ = (Wire.read() << 8 | Wire.read()) / 131.0;
}

float IMU::getAccelX() 
{
    return accelX;
}

float IMU::getAccelY() 
{
    return accelY;
}

float IMU::getAccelZ() 
{
    return accelZ;
}

float IMU::getGyroX() 
{
    return gyroX;
}

float IMU::getGyroY() 
{
    return gyroY;
}

float IMU::getGyroZ() 
{
    return gyroZ;
}
