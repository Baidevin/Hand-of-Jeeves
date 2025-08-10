#include <Arduino.h>
// #include <IMU.h>
#include "IMU.h"
#include <Wire.h>
#include "FastIMU.h"
#define IMU_ADDRESS 0x68    //Change to the address of the IMU
#define PERFORM_CALIBRATION //Comment to disable startup calibration


IMU::IMU()
{
  // BMI160 BMI;  _

}

void IMU::begin()
{
  const int Addr = 0x68;
              //Change to the name of any supported IMU! 
  // Currently supported IMUS: MPU9255 MPU9250 MPU6886 MPU6500 MPU6050 ICM20689 ICM20690 BMI055 BMX055 BMI160 LSM6DS3 LSM6DSL QMI8658
  int punch_count=0;
  bool on_cooldown=0;
  int cooldown_counter =0;
  double abs_acc=0;
  int abs_acc_index=0;
  int abs_acc_index_prev =0;
  Wire.begin();
  Wire.setClock(400000); //400khz clock
  int err = _BMI.init(calib, IMU_ADDRESS);
  if (err != 0) {
    Serial.print("Error initializing IMU: ");
    Serial.println(err);
  }
  
  calibrate();
  //err = BMI.setGyroRange(500);      //USE THESE TO SET THE RANGE, IF AN INVALID RANGE IS SET IT WILL RETURN -1
  //err = BMI.setAccelRange(2);       //THESE TWO SET THE GYRO RANGE TO ±500 DPS AND THE ACCELEROMETER RANGE TO ±2g
  
  if (err != 0) {
    Serial.print("Error Setting range: ");
    Serial.println(err);
  }
}

void IMU::calibrate(){
    Serial.println("FastIMU calibration & data example");
  if (_BMI.hasMagnetometer()) {
    delay(1000);
    Serial.println("Move IMU in figure 8 pattern until done.");
    delay(3000);
    _BMI.calibrateMag(&calib);
    Serial.println("Magnetic calibration done!");
  }
  else {
    delay(5000);
  }

  delay(5000);
  Serial.println("Keep IMU level.");
  delay(5000);
  _BMI.calibrateAccelGyro(&calib);
  Serial.println("Calibration done!");
  Serial.println("Accel biases X/Y/Z: ");
  Serial.print(calib.accelBias[0]);
  Serial.print(", ");
  Serial.print(calib.accelBias[1]);
  Serial.print(", ");
  Serial.println(calib.accelBias[2]);
  Serial.println("Gyro biases X/Y/Z: ");
  Serial.print(calib.gyroBias[0]);
  Serial.print(", ");
  Serial.print(calib.gyroBias[1]);
  Serial.print(", ");
  Serial.println(calib.gyroBias[2]);
  delay(5000);
  _BMI.init(calib, IMU_ADDRESS);
}

void IMU::update()
{
    // Wire.beginTransmission(Addr);
    // Wire.write(0x3B);
    // Wire.endTransmission(false);
    // Wire.requestFrom(Addr, 6, true); 

    // accelX = (Wire.read() << 8 | Wire.read()) / 16384.0; 
    // accelY = (Wire.read() << 8 | Wire.read()) / 16384.0;
    // accelZ = (Wire.read() << 8 | Wire.read()) / 16384.0;

    // Wire.beginTransmission(Addr);
    // Wire.write(0x43); 
    // Wire.endTransmission(false);
    // Wire.requestFrom(Addr, 6, true); 
    // gyroX = (Wire.read() << 8 | Wire.read()) / 131.0; 
    // gyroY = (Wire.read() << 8 | Wire.read()) / 131.0;
    // gyroZ = (Wire.read() << 8 | Wire.read()) / 131.0;
    _BMI.update();
    _BMI.getAccel(&accelData);
}

float IMU::getAccelX() 
{
    return accelData.accelX;
}

float IMU::getAccelY() 
{
    return accelData.accelY;
}

float IMU::getAccelZ() 
{
    return accelData.accelZ;
}

float IMU::getGyroX() 
{
    return 0;
}

float IMU::getGyroY() 
{
    return 0;
}

float IMU::getGyroZ() 
{
    return 0;
}
