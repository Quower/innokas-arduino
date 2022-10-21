#include <TFT.h>  
#include <SPI.h>
#define light_sensor A0
#define cs   10
#define dc   9
#define rst  8
//#define trig A2 
//#define echo A1 



void setup() {
  // put your setup code here, to run once:
pinMode(light_sensor, INPUT);
Serial.begin(9600);
TFT TFTscreen = TFT(cs, dc, rst);
TFTscreen.setTextSize(2);
 TFTscreen.text("Sensor Value :\n ", 2, 2);
TFTscreen.setTextSize(2);


}

void loop() {
  // put your main code here, to run repeatedly:
  int light = analogRead(light_sensor);
Serial.println(light);
light.toCharArray(sensorPrintout, 5);
TFTscreen.stroke(255, 0, 255);
TFTscreen.background (255,255,255);
TFTscreen.text(sensorPrintout, 2, 22);
}
