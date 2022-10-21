#include <IRremote.hpp>

#define PIN_RECV 2
#define pin1 6
#define pin2 3
#define pin3 5
#define pin4 9
//IRrecv irrecv(PIN_RECV);
//decode_results results;
int ir_result;
long tim;





void setup() {
  Serial.begin(9600);
  pinMode(pin1, INPUT);
  pinMode(pin2, INPUT);
  pinMode(pin3, INPUT);
  pinMode(pin4, INPUT);
  //irrecv.enableIRIn();
  IrReceiver.begin(PIN_RECV, true);

}

void loop() {
  if (IrReceiver.decode()) {
    ir_result = IrReceiver.decodedIRData.decodedRawData;
      Serial.println(ir_result);
      IrReceiver.resume();
      switch (ir_result) {
  case 6176:
    //up
    front();
    tim = millis();
    break;
  case 6160:
    //right
    right();
    tim = millis();
    break;
  case 6161:
    //left
    left();
    tim = millis();
    break;
  case 6177:
    //down
    back();
    tim = millis();
    break;
    case 4128:
    //up
    front();
    tim = millis();
    break;
  case 4112:
    //right
    right();
    tim = millis();
    break;
  case 4113:
    //left
    left();
    tim = millis();
    break;
  case 4129:
    //down
    back();
    tim = millis();
    break;
  }
      
  }
  if (millis() - tim > 1000) {
    stopm();
  }
}
void front() {
  //analogWrite(pin1, 255);
  analogWrite(pin3, 255);
  Serial.println("test1");
  
}
void back() {
  
}
void right() {
  
}
void left() {
  
}
void stopm() {
  analogWrite(pin1, 0);
  analogWrite(pin2, 0);
  analogWrite(pin3, 0);
  analogWrite(pin4, 0);
  Serial.println("test2");
}

