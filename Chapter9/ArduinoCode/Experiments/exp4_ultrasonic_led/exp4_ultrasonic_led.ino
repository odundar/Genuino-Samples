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

int trigPin = 12; 
int echoPin = 3;
int ledPin = 2;

int trigPinDuration = 10; 
int soundBurstDuration = 8; 
float distanceConstant = 59; 
int minDistance = 3; 
int maxDistance = 400;

void setup(){ 
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  pinMode(ledPin, OUTPUT);
}


void loop() {
  float distance = measureDistance(); 
  digitalWrite(ledPin, HIGH);
  delay(distance * 80);
  digitalWrite(ledPin, LOW);
  delay(distance * 80);
}

float measureDistance(){ 
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(trigPinDuration); 
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(soundBurstDuration); 
  int duration = pulseIn(echoPin, HIGH); 
  float distance = (float)duration / distanceConstant ;
  if( (int) distance > maxDistance ) 
  { 
    return maxDistance ; 
  } 
  else if( (int) distance < minDistance ) 
  { 
    return minDistance;  
  } 
  else  
  { 
    return distance; 
  } 
}
