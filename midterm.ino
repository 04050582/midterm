#include "SevSeg.h"
SevSeg sevseg;

void setup() 
{
  Serial.begin(9600);
  Serial.println("15");
  Serial.println("04050582");
  Serial.println("04050742");
  byte numDigits = 4;
  byte digitPins[] = {2,3,4,5};
  byte segmentPins[] = {6,7,8,9,10,11,12,13};
  sevseg.begin(COMMON_CATHODE, numDigits, digitPins,segmentPins);
}


 void loop()
{
  int val;
    if(Serial.available())
    {
      val = Serial.parseInt();
      Serial.println(val);    
      if(val>=0 && val<=9999)
      {
        sevseg.setNumber(val);
          sevseg.refreshDisplay();
        }
      else
        Serial.println("range error");  
    }
    else
            sevseg.refreshDisplay();
}

