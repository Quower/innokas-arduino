#include <IRremote.hpp>
#define IR_PIN 3
/*IRrecv irrecv(IR_PIN);
decode_results results;*/


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  IrReceiver.begin(IR_PIN, ENABLE_LED_FEEDBACK);

}

void loop() {
  if(IrReceiver.decode()){
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
    //IrReceiver.printIRResultShort(&Serial);
    IrReceiver.resume();
  }
}
