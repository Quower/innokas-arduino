#include <IRremote.hpp>
//#include <Servo.h>

//Servo myservo;



#define PIN_RECV 2
#define mrb 6
#define mrf 3
#define mlf 5
#define mlb 11
#define servo A5
//IRrecv irrecv(PIN_RECV);
//decode_results results;
int ir_result;
long tim;
int x = 0;
int y = 0;
int deadzone = 25;
int borderdeadzone = 5;
long mls = 0;





void setup() {
  Serial.begin(250000);
  pinMode(mrf, INPUT);
  pinMode(mrb, INPUT);
  pinMode(mlf, INPUT);
  pinMode(mlb, INPUT);
  //irrecv.enableIRIn();
  IrReceiver.begin(PIN_RECV, true);
  //myservo.attach(servo);

}

void loop() {
  if (IrReceiver.decode()) {
    ir_result = IrReceiver.decodedIRData.decodedRawData;
      //Serial.println(ir_result);
      IrReceiver.resume();
      //Serial.println(myservo.read());

      if (ir_result>6000 && ir_result<7025){
        x = ir_result - 6000;
        mls = millis();
      }
      else if (ir_result>8000 && ir_result<9025){
        y = ir_result - 8000;
        mls = millis();
      } else if (millis() - mls > 300) {
        analogWrite(mrb, 0);
        analogWrite(mrf, 0);
        analogWrite(mlb, 0);
        analogWrite(mlf, 0);
        return;
      }
      else {
        return;
      }
      int vmlf = map(y, 512+deadzone, 1024-borderdeadzone, 0, 255);
      int vmrf = map(y, 512+deadzone, 1024-borderdeadzone, 0, 255);
      int vmlb = map(y, 512-deadzone, 1+borderdeadzone, 0, 255);
      int vmrb = map(y, 512-deadzone, 1+borderdeadzone, 0, 255);
      
      if (vmrf>255) {vmrf = 255;}
      if (vmrf<0) {vmrf = 0;}
      if (vmrb>255) {vmrb = 255;}
      if (vmrb<0) {vmrb = 0;}
      if (vmlf>255) {vmlf = 255;}
      if (vmlf<0) {vmlf = 0;}
      if (vmlb>255) {vmlb = 255;}
      if (vmlb<0) {vmlb = 0;}

      
      int sider = map(x, 512+deadzone, 1024-borderdeadzone, 100, 1);
      int sidel = map(x, 0+borderdeadzone, 512-deadzone, 1, 100);

      if (vmrf > 0) {


      if (sider>100) {sider = 100;}
      if (sider<1) {sider = 1;}
      if (sidel>100) {sidel = 100;}
      if (sidel<1) {sidel = 1;}

      /*Serial.print(sidel);
      Serial.print("  ");
      Serial.print(sider);
      Serial.print("     ");*/

        vmrf = (vmrf * map(sider, 1, 100, 50, 100 ))/100;
        vmlf = (vmlf * map(sidel, 1, 100, 50, 100 ))/100;

      if (sidel = 1) {
        vmlf = ((vmlf * sider) + ((255 * (100 - sider))))/100;
      } else if (sider = 1) {
        vmrf = ((vmrf * sidel) + ((255 * (100 - sidel))))/100;
      }
      }
      else if (vmrb > 0) {

      if (sider>100) {sider = 100;}
      if (sider<1) {sider = 1;}
      if (sidel>100) {sidel = 100;}
      if (sidel<1) {sidel = 1;}

      /*Serial.print(sidel);
      Serial.print("  ");
      Serial.print(sider);
      Serial.print("     ");*/
 
        vmrb = (vmrb * map(sider, 1, 100, 50, 100 ))/100;
        vmlb = (vmlb * map(sidel, 1, 100, 50, 100 ))/100;

      if (sidel = 1) {
        vmlb = ((vmlb * sider) + ((255 * (100 - sider))))/100;
      } else if (sider = 1) {
        vmrb = ((vmrb * sidel) + ((255 * (100 - sidel))))/100;
      }
      }

      

      if (vmrf>255) {vmrf = 255;}
      if (vmrf<0) {vmrf = 0;}
      if (vmrb>255) {vmrb = 255;}
      if (vmrb<0) {vmrb = 0;}
      if (vmlf>255) {vmlf = 255;}
      if (vmlf<0) {vmlf = 0;}
      if (vmlb>255) {vmlb = 255;}
      if (vmlb<0) {vmlb = 0;}

      /*Serial.print(vmlf);
      Serial.print("  ");
      Serial.print(vmrf);
      Serial.print("  ");
      Serial.print(vmlb);
      Serial.print("  ");
      Serial.println(vmrb);*/
      //myservo.write(map(vmrf, 0, 255, 0, 180));


      analogWrite(mrb, vmrb);
      analogWrite(mrf, vmrf);
      analogWrite(mlb, vmlb);
      analogWrite(mlf, vmlf);

      
      
      
  }
}
