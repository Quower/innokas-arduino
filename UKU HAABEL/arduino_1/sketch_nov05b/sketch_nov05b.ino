#include <Servo.h>

Servo mootor;



void setup() {
  // put your setup code here, to run once:
mootor.attach(3);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(5, HIGH);
for (int i=0; i>180;i++){
  mootor.write(i);
  delay(1);
}
for (int i=360; i>0;i--){
  mootor.write(i);
  delay(1);
}
}
