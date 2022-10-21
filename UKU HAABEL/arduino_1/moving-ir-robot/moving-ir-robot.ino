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
int x = 0;
int y = 0;





void setup() {
  Serial.begin(250000);
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
      //Serial.println(ir_result);
      IrReceiver.resume();
      
      if (ir_result>6000 && ir_result<7025){
        x = ir_result - 6000;
      }
      else if (ir_result>8000 && ir_result<9025){
        y = ir_result - 8000;
      } else {
        return;
      }
      Serial.print(x);
      Serial.print("  ");
      Serial.print(y);
      Serial.print("  ");
      Serial.println(ir_result);
      
  }
  /*if (millis() - tim > 500) {
    stopm();
  }*/
}
void front() {
  analogWrite(pin2, 255);
  analogWrite(pin3, 255);
  //Serial.println(millis() - tim);
  
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
  //Serial.println("test2");
}

