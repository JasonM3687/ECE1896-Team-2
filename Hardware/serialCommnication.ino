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
      case 0:
        tmrpcm.setVolume(6);
        tmrpcm.play("Zero.wav");
        delay(2000);
        tmrpcm.disable();
      case 1:
        tmrpcm.setVolume(6);
        tmrpcm.play("One.wav");
        delay(2000);
        tmrpcm.disable();
      case 2:
        tmrpcm.setVolume(6);
        tmrpcm.play("Two.wav");
        delay(2000);
        tmrpcm.disable();
      case 3:
        tmrpcm.setVolume(6);
        tmrpcm.play("Three.wav");
        delay(1000);
        tmrpcm.disable();
      case 4:
        tmrpcm.setVolume(6);
        tmrpcm.play("Four.wav");
        delay(2000);
        tmrpcm.disable();
      case 5:
        tmrpcm.setVolume(6);
        tmrpcm.play("Five.wav");
        delay(2000);
        tmrpcm.disable();
      case 6:
        tmrpcm.setVolume(6);
        tmrpcm.play("Six.wav");
        delay(2000);
        tmrpcm.disable();
      case 7:
        tmrpcm.setVolume(6);
        tmrpcm.play("Seven.wav");
        delay(2000);
        tmrpcm.disable();
      case 8:
        tmrpcm.setVolume(6);
        tmrpcm.play("Eight.wav");
        delay(2000);
        tmrpcm.disable();
      case 9:
        tmrpcm.setVolume(6);
        tmrpcm.play("Nine.wav");
        delay(2000);
        tmrpcm.disable();
      default:
        tmrpcm.disable();
        break;
    }
  }
}
