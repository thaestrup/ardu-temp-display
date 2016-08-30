/* SevSeg Counter Example

 Copyright 2014 Dean Reading

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at
 http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.


 This example demonstrates a very simple use of the SevSeg library with a 4
 digit display. It displays a counter that counts up, showing deci-seconds.
 */

#include "SevSeg.h"

SevSeg sevseg; //Instantiate a seven segment controller object


#include <dht11.h>

dht11 DHT11;

  float prevtemp = 0;
  int diffcounter = 0;
#define DHT11PIN 1

void setup() {
  byte numDigits = 4;
  byte digitPins[] = {2, 3, 4, 5};
  byte segmentPins[] = {6, 7, 8, 9, 10, 11, 12, 13};

  sevseg.begin(COMMON_ANODE, numDigits, digitPins, segmentPins);
  sevseg.setBrightness(20);
}
void checkdht11(int chk) {

  switch (chk) {
      case DHTLIB_OK:
        Serial.print("DHTLIB_OK: ");
  		  break;
      case DHTLIB_ERROR_CHECKSUM:
        Serial.print("DHTLIB_ERROR_CHECKSUM: ");
  		  break;
      case DHTLIB_ERROR_TIMEOUT:
        Serial.print("DHTLIB_ERROR_TIMEOUT: ");
        break;
      default:
        Serial.print("DHTLIB_DEFAULT: ");
  		  break;
  }
}

void loop() {
  int chk = DHT11.read(DHT11PIN);
  //checkdht11(chk);
  //Serial.print("Read sensor: ");
  //Serial.print("Temperature (°C): ");
  //Serial.println((float)DHT11.temperature, 2);
  float temp = (float) DHT11.temperature;
  
  //if (temp != prevtemp) {
    diffcounter++;
    prevtemp=temp;
    sevseg.setNumber(temp, 0);
    sevseg.refreshDisplay(); // Must run repeatedly
  //sevseg.setNumber(1234, 2);
  //delay(200);
  //}  
    
}

/// END ///
