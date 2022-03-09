#include "SD.h"
#define SD_ChipSelectPin 4
#include "TMRpcm.h"
#include "SPI.h"

TMRpcm tmrpcm;

void setup() {
  // put your setup code here, to run once:
  tmrpcm.speakerPin=9;
  Serial.begin(9600);
  if(!SD.begin(SD_ChipSelectPin))
  {
    Serial.println("SD fail");
    return;
  }



}



void loop() {
  if(Serial.available() > 0)
  {
    int number = Serial.read() - '0';
    switch (number) {
      case 7:
        tmrpcm.setVolume(6);
        tmrpcm.play("test.wav");
        delay(1000);
        tmrpcm.disable();
      default:
        tmrpcm.disable();
        break;
    }
  }
}
