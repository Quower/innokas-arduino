#include <IRremote.hpp>

#define PIN_RECV 2
#define mrb 6
#define mrf 3
#define mlf 5
#define mlb 10
//IRrecv irrecv(PIN_RECV);
//decode_results results;
int ir_result;
long tim;
int x = 0;
int y = 0;
int deadzone = 25;
int borderdeadzone = 5;





void setup() {
  Serial.begin(57600);
  pinMode(mrf, INPUT);
  pinMode(mrb, INPUT);
  pinMode(mlf, INPUT);
  pinMode(mlb, INPUT);
  //irrecv.enableIRIn();
  IrReceiver.begin(PIN_RECV, true);

}

void loop() {
  if (IrReceiver.decode()) {
    ir_result = IrReceiver.decodedIRData.decodedRawData;
      //Serial.println(ir_result);
      IrReceiver.resume();

      Serial.print(ir_result);
      Serial.print("   ");
      
      if (ir_result>6000 && ir_result<7025){
        x = ir_result - 6000;
      }
      else if (ir_result>8000 && ir_result<9025){
        y = ir_result - 8000;
      } else {
        return;
      }
      int vmlf = map(y, 512+deadzone, 1024-borderdeadzone, 0, 255);
      int vmrf = map(y, 512+deadzone, 1024-borderdeadzone, 0, 255);
      int vmlb = map(y, 512-deadzone, 1+borderdeadzone, 0, 255);
      int vmrb = map(y, 512-deadzone, 1+borderdeadzone, 0, 255);

      Serial.print(vmlf);
      Serial.print("  ");
      Serial.print(vmrf);
      Serial.print("  ");
      Serial.print(vmlb);
      Serial.print("  ");
      Serial.print(vmrb);
      Serial.print("     ");
      
      if (vmrf>255) {vmrf = 255;}
      if (vmrf<0) {vmrf = 0;}
      if (vmrb>255) {vmrb = 255;}
      if (vmrb<0) {vmrb = 0;}
      if (vmlf>255) {vmlf = 255;}
      if (vmlf<0) {vmlf = 0;}
      if (vmlb>255) {vmlb = 255;}
      if (vmlb<0) {vmlb = 0;}

      Serial.print(vmlf);
      Serial.print("  ");
      Serial.print(vmrf);
      Serial.print("  ");
      Serial.print(vmlb);
      Serial.print("  ");
      Serial.print(vmrb);
      Serial.print("     ");
      
      /*int sider;
      int sidel;
      if (vmrf > 0) {

      sider = map(x, 512+deadzone, 1024-borderdeadzone, 0, vmrf);
      sidel = map(x, 1+borderdeadzone, 512-deadzone, vmrf, 0);

      if (sider>255) {sider = 255;}
      if (sider<0) {sider = 0;}
      if (sidel>255) {sidel = 255;}
      if (sidel<0) {sidel = 0;}

        vmrf = vmrf - sider;
        vmlf = vmlf - sidel;
      }
      else if (vmrb > 0) {

      sider = map(x, 512+deadzone, 1024-borderdeadzone, 0, vmrb);
      sidel = map(x, 0+borderdeadzone, 512-deadzone, vmrb, 0);

      if (sider>255) {sider = 255;}
      if (sider<0) {sider = 0;}
      if (sidel>255) {sidel = 255;}
      if (sidel<0) {sidel = 0;}
 
        vmrb = vmrb - sider;
        vmlb = vmlb - sidel;
      }

      if (vmrf>255) {vmrf = 255;}
      if (vmrf<0) {vmrf = 0;}
      if (vmrb>255) {vmrb = 255;}
      if (vmrb<0) {vmrb = 0;}
      if (vmlf>255) {vmlf = 255;}
      if (vmlf<0) {vmlf = 0;}
      if (vmlb>255) {vmlb = 255;}
      if (vmlb<0) {vmlb = 0;}*/

      /*Serial.print(vmlf);
      Serial.print("  ");
      Serial.print(vmrf);
      Serial.print("  ");
      Serial.print(vmlb);
      Serial.print("  ");
      Serial.print(vmrb);
      Serial.print("     ");
      Serial.print(sidel);
      Serial.print("  ");
      Serial.print(sider);
      Serial.print("     ");*/


      analogWrite(mrb, vmrb);
      Serial.print("1");
      analogWrite(mrf, vmrf);
      Serial.print("2");
      analogWrite(mlb, vmlb);
      Serial.print("3");
      analogWrite(mlf, vmlf);
      Serial.println("4");

      
      
      
  }
  /*if (millis() - tim > 500) {
    stopm();
  }*/
}
/*void front() {
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
}*/
