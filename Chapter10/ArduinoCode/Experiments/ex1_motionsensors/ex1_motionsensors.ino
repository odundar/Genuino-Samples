/**
* The MIT License (MIT)

* Copyright (c) 2016 Onur Dundar
* onur.dundar1@gmail.com

* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:

* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.

* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
**/

#include "CurieIMU.h"

void setup() {
  //Initialize Serial communication
  Serial.begin(9600);
  Serial.println("Initializing Motion Sensors");
  CurieIMU.begin();
  Serial.println("Set Range for Accel 2G");
  CurieIMU.setAccelerometerRange(4);
  int accelRate = CurieIMU.getAccelerometerRate();
  Serial.print("Accelerometer Rate: ");
  Serial.println(accelRate);
  Serial.println("Set Range for Gyro 250 degrees");
  CurieIMU.setGyroRange(250);
  int gyroRate = CurieIMU.getGyroRate();
  Serial.print("Gyro Rate: ");
  Serial.println(gyroRate);
}

void loop() {
  //read values
  int axRaw, ayRaw, azRaw;
  int gxRaw, gyRaw, gzRaw;

  CurieIMU.readAccelerometer(axRaw, ayRaw, azRaw);

  CurieIMU.readGyro(gxRaw, gyRaw, gzRaw);

  float ax, ay, az;
  float gx, gy, gz;

  ax = convertRawAccel(axRaw);
  ay = convertRawAccel(ayRaw);
  az = convertRawAccel(azRaw);

  Serial.print("Acceleration in mg ");
  Serial.print(" X: ");
  Serial.print(ax);
  Serial.print(" Y: ");
  Serial.print(ay);
  Serial.print(" Z: ");
  Serial.println(az);
  
  gx = convertRawGyro(gxRaw);
  gy = convertRawGyro(gyRaw);
  gz = convertRawGyro(gzRaw);

  Serial.print("Angular Velocity degree/second ");
  Serial.print(" X: ");
  Serial.print(gx);
  Serial.print(" Y: ");
  Serial.print(gy);
  Serial.print(" Z: ");
  Serial.println(gz);
  
  delay(1000);
}

float convertRawAccel(int rawAccel){
  float a = (rawAccel/32768.0) * CurieIMU.getAccelerometerRange(); 
  return a; 
}

float convertRawGyro(int rawGyro){
  float a = ( rawGyro/32768.9) * CurieIMU.getGyroRange();
  return a;
}

