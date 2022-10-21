#include <IRremote.h>
#include <IRremoteInt.h>
#include <IRremoteTools.h>

#define IR_PIN
#define potPin A0
#define controlPin1 2
#define controlPin2 3
#define onOff 5
#define enablePin 9

IRrecv irDetect(IR_PIN);

//#define nosLevelPin A1
//#define nosPin 8
int motorDir = 0;
int motorSpeed = 0;
int onOffm = 1;
int number = 127;
//int nosLevel;
//int nos;


void setup() {
  pinMode(onOff, INPUT);
  pinMode(potPin, INPUT);
  pinMode(controlPin1, OUTPUT);
  pinMode(controlPin2, OUTPUT);
  pinMode(enablePin, OUTPUT);
  //pinMode(nosLevelPin, INPUT);
  //pinMode(nosPin, INPUT);
Serial.begin(9600);
}

void loop() {
  motorSpeed = map(analogRead(potPin), 0, 1024, 0, number*2);
  //nos = digitalRead(nosPin);
  //nosLevel = analogRead(nosLevelPin);
  if (digitalRead(onOff)==HIGH){
    if(onOffm == 0){
      onOffm = 1;
      delay(500);
    }
    else{
      onOffm = 0;
      delay(500);
    }
  }
  if(motorSpeed > number) {
    motorSpeed = map((motorSpeed - number), 0, number, number, number*2);
    motorDir = 1;
  }
  else{
    motorSpeed = map(motorSpeed, 0, number, number*2, 0);
    motorDir = 0;
  }
  if(motorDir == 1){
    digitalWrite(controlPin1, HIGH);
    digitalWrite(controlPin2, LOW);
    
  }
  else {
    digitalWrite(controlPin1, LOW);
    digitalWrite(controlPin2, HIGH);
  }
  if(onOffm == 1){
    analogWrite(enablePin, motorSpeed);
  }
  else{
    analogWrite(enablePin, 0);
  }
  Serial.print(motorSpeed);
  Serial.print("      ");
  Serial.print(motorDir);
  Serial.print("      ");
  Serial.println(onOffm);
  //Serial.print("      ");
  //Serial.print(nos);
  //Serial.print("      ");
  //Serial.println(nosLevel);
  


}
