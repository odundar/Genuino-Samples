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

#include <math.h>

int analogPin = A0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  float thermistorVoltage = analogRead(analogPin);
  float temperature = calculateTemperature(thermistorVoltage);
  Serial.println(temperature);
  delay(3000);
}

//Apply formula at
float calculateTemperature(float analogVoltage){
  float A = 0.001129148;
  float B = 0.000234125;
  float C = 0.0000000876741;
  
  float Vin = 1024.0;
  float ntcResistance = 10000;
  float kelvinConstant = 273.15;

  float newResistance = (Vin - analogVoltage) * ntcResistance / Vin;

  float temp = A + B * log(newResistance) + C * pow(log(newResistance), 3.0);

  temp = (1.0 / temp) - kelvinConstant;

  return temp;
}

