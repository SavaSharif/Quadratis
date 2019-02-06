#ifndef GyroAcc_H
#define GyroAcc_H

#include <Arduino.h>
#include "I2Cdev.h"
#include "MPU6050.h"

// Arduino Wire library is required if I2Cdev I2CDEV_ARDUINO_WIRE implementation
// is used in I2Cdev.h
#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
#include "Wire.h"
#endif

#define NOISE 1000
#define TRESHOLDVALUE 22000
#define DEPTH 10
#define AXES 3
#define X 0
#define Y 1
#define Z 2
#define INTERVAL 1

class GyroAcc
{
  
public:
  GyroAcc();
  ~GyroAcc();
  int getControls(int prevScreen, int screenOff);
  boolean getShaking();
  int getDirection();

private:
  MPU6050 accelgyro;

  int screenOff = 0;
  int minVal=265; int maxVal=402;

  double x; double y; double z;

  int16_t lastTop = 0;
  int16_t lastDal = 0;
  unsigned long dal[DEPTH][AXES] = {{0, 0}};
  unsigned long top[DEPTH][AXES] = {{0, 0}};

  int topCounter = 0;
  int dalCounter = 0;

  long previousMillis = 0;

  boolean topMode = true;

  void getAcceleration(int16_t accData[3]);
  void getGyro(int16_t gyroData[3]);
  boolean handleShake(unsigned long dal[DEPTH][AXES], unsigned long top[DEPTH][AXES]);
  unsigned long getDal(int16_t x);
  unsigned long getTop(int16_t x);

  int prevScreen = 2;
  
  int getScreenOff(int16_t x, int16_t y, int16_t z);
  
};

#endif
