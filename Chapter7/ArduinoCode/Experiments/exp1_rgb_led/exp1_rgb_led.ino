
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

//pin definitions 
int redPin = 9;  
int greenPin = 6;  
int bluePin = 5; 

//Color codes 
int redColor[] = {255, 0, 0};  
int greenColor[] = {0, 255, 0}; 
int blueColor[] = {0, 0, 255}; 
int yellowColor[] = {255, 255, 0}; 
int orangeColor[] = {255, 128, 0}; 
int maroonColor[] = {75, 0, 130};

//setup pins 
void setup() {  
  // Set output pin modes 
  pinMode(redPin, OUTPUT);   
  pinMode(greenPin, OUTPUT);   
  pinMode(bluePin, OUTPUT); 
} 

//loop to light up RGB Led each second
void loop(){ 
  setRGBColorCommonAnode(redColor); 
  delay(1000); 
  setRGBColorCommonAnode(greenColor); 
  delay(1000); 
  setRGBColorCommonAnode(blueColor); 
  delay(1000); 
  setRGBColorCommonAnode(yellowColor); 
  delay(1000); 
  setRGBColorCommonAnode(orangeColor); 
  delay(1000); 
  setRGBColorCommonAnode(maroonColor); 
  delay(1000); 
}

// Write rgb color function for common anode RGB LED
void setRGBColorCommonAnode(int colorCode[]) 
{ 
  int red = 255 - colorCode[0]; 
  int green = 255 - colorCode[1]; 
  int blue = 255 - colorCode[2]; 
  analogWrite(redPin, red); 
  analogWrite(greenPin, green); 
  analogWrite(bluePin, blue); 
}
