#include <IRremote.hpp>
#define xpin A1 
#define zpin A2
#define ypin A0
#define IR_PIN 5

void setup() {
  // put your setup code here, to run once:
IrSender.begin(IR_PIN);
}

void loop() {
  int x = analogRead(xpin);
  int z = analogRead(zpin);
  int y = analogRead(ypin);
  
  if(y == 0) {
    IrSender.sendNECRaw(0x11, 2);
    delay(500);
  }

}
