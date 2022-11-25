#include <IRremote.hpp>

#define PIN_RECV 2
#define mrb 6
#define mrf 3
#define mlf 5
#define mlb 11
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
      Serial.print("     ");
      
      if (ir_result>6000 && ir_result<7025){
        x = ir_result - 6000;
        mls = millis();
      }
      else if (ir_result>8000 && ir_result<9025){
        y = ir_result - 8000;
        mls = millis();
      } else if (millis() - mls > 600) {
        analogWrite(mrb, 0);
        analogWrite(mrf, 0);
        analogWrite(mlb, 0);
        analogWrite(mlf, 0);
      }
      else {
        return;
      }
      int svmlf = map(y, 512+deadzone, 1024-borderdeadzone, 0, 255);
      int svmrf = map(y, 512+deadzone, 1024-borderdeadzone, 0, 255);
      int svmlb = map(y, 512-deadzone, 1+borderdeadzone, 0, 255);
      int svmrb = map(y, 512-deadzone, 1+borderdeadzone, 0, 255);

      int vmlf = 0;
      int vmrf = 0;
      int vmlb = 0;
      int vmrb = 0;
      
      if (svmrf>255) {svmrf = 255;}
      if (svmrf<0) {svmrf = 0;}
      if (svmrb>255) {svmrb = 255;}
      if (svmrb<0) {svmrb = 0;}
      if (svmlf>255) {svmlf = 255;}
      if (svmlf<0) {svmlf = 0;}
      if (svmlb>255) {svmlb = 255;}
      if (svmlb<0) {svmlb = 0;}

      
      int sider = map(x, 512+deadzone, 1024-borderdeadzone, 100, 1);
      int sidel = map(x, 0+borderdeadzone, 512-deadzone, 1, 100);

      if (vmrf > 0) {


      if (sider>100) {sider = 100;}
      if (sider<1) {sider = 1;}
      if (sidel>100) {sidel = 100;}
      if (sidel<1) {sidel = 1;}

      Serial.print(sidel);
      Serial.print("  ");
      Serial.print(sider);
      Serial.print("     ");

        vmrf = ((svmrf * map(sider, 1, 100, 50, 100 ))-(svmrf * map(svmlf, 0, 255, 1, 50 )))/100;
        vmlf = ((svmlf * map(sidel, 1, 100, 50, 100 ))-(svmlf * map(svmrf, 0, 255, 1, 50 )))/100;

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

      Serial.print(sidel);
      Serial.print("  ");
      Serial.print(sider);
      Serial.print("     ");
 
        vmrb = ((svmrb * map(sider, 1, 100, 50, 100 ))-(svmrb * map(svmlb, 0, 255, 1, 50 )))/100;
        vmlb = ((svmlb * map(sidel, 1, 100, 50, 100 ))-(svmlb * map(svmrb, 0, 255, 1, 50 )))/100;

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

      Serial.print(vmlf);
      Serial.print("  ");
      Serial.print(vmrf);
      Serial.print("  ");
      Serial.print(vmlb);
      Serial.print("  ");
      Serial.println(vmrb);


      analogWrite(mrb, vmrb);
      analogWrite(mrf, vmrf);
      analogWrite(mlb, vmlb);
      analogWrite(mlf, vmlf);

      
      
      
  }
}
