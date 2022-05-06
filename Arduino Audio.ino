#include "SD.h"
#define SD_ChipSelectPin 4
#include "TMRpcm.h"
#include "SPI.h"
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 6

Adafruit_NeoPixel strip = Adafruit_NeoPixel(12, PIN, NEO_GRB + NEO_KHZ800);

TMRpcm tmrpcm;

void setup() {
  strip.begin();
  strip.setBrightness(255);
  strip.show(); // Initialize all pixels to 'off'
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
  colorWipe(strip.Color(127, 127, 127), 50);
  if(Serial.available() > 0)
  {
    int number = Serial.read() - '0';
    if (number == 0) {
        tmrpcm.setVolume(6);
        tmrpcm.play("Zero.wav");
        delay(2000);
        tmrpcm.disable();
    }
    else if (number == 1){
        tmrpcm.setVolume(6);
        tmrpcm.play("One.wav");
        delay(2000);
        tmrpcm.disable();
    }
    else if (number == 2){
        tmrpcm.setVolume(6);
        tmrpcm.play("Two.wav");
        delay(2000);
        tmrpcm.disable();
    }
    else if (number == 3){
        tmrpcm.setVolume(6);
        tmrpcm.play("Three.wav");
        delay(2000);
        tmrpcm.disable();
    }
    else if (number == 4){
        tmrpcm.setVolume(6);
        tmrpcm.play("Four.wav");
        delay(2000);
        tmrpcm.disable();
    }
    else if (number == 5){
        tmrpcm.setVolume(6);
        tmrpcm.play("Five.wav");
        delay(2000);
        tmrpcm.disable();
    }
    else if (number == 6){
        tmrpcm.setVolume(6);
        tmrpcm.play("Six.wav");
        delay(2000);
        tmrpcm.disable();
    }
    else if (number == 7) {
        tmrpcm.setVolume(6);
        tmrpcm.play("Seven.wav");
        delay(2000);
        tmrpcm.disable();
    }
    else if (number == 8){
        tmrpcm.setVolume(6);
        tmrpcm.play("Eight.wav");
        delay(2000);
        tmrpcm.disable();
    }
    else if (number == 9){
        tmrpcm.setVolume(6);
        tmrpcm.play("Nine.wav");
        delay(2000);
        tmrpcm.disable(); 
    }
    else{
        tmrpcm.disable();
    }
    }
  }

  void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}