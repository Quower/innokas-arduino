#define IR_PIN 12
#define controlPin1 2
#define controlPin2 3
#define onOff 5
#define enablePin 9
#define xpin A0
#define ypin A1
#define prespin A2

int motorDir = 0;
int motorSpeed = 0;
boolean onOffm = false;
int x;
int y;
int pres;




void setup() {
  pinMode(onOff, INPUT);
  pinMode(controlPin1, OUTPUT);
  pinMode(controlPin2, OUTPUT);
  pinMode(enablePin, OUTPUT);
  pinMode(xpin, INPUT);
  pinMode(ypin, INPUT);
  pinMode(prespin, INPUT);
  

Serial.begin(9600);
}


void loop() {
  x = analogRead(xpin);
  y = analogRead(ypin);
  pres = analogRead(prespin);
  if(pres != 0){
    pres = 0;
  } else {
    pres = 1;
    if(onOffm == false) {
      onOffm = true;
    }
    else{
      onOffm = false;
      ,
    }
    delay(300);
  }
  if(100>x){
    motorSpeed++;
    if(motorSpeed>255){
      motorSpeed = 255;
    }
  }
  else if(x>900){
    motorSpeed--;
    if(motorSpeed<0){
      motorSpeed = 0;
    }
  }
  if(100>y){
    motorDir = 0;
  }
  else if(y>900){
    motorDir = 1;
  }
  if(motorDir == 1){
    digitalWrite(controlPin1, HIGH);
    digitalWrite(controlPin2, LOW);
    
  }
  else {
    digitalWrite(controlPin1, LOW);
    digitalWrite(controlPin2, HIGH);
  }
  if(onOffm == true){
    analogWrite(enablePin, motorSpeed);
  }
  else{
    analogWrite(enablePin, 0);
  }
  Serial.print(x);
  Serial.print("     ");
  Serial.print(y);
  Serial.print("     ");
  Serial.print(pres);
  Serial.print("     ");
  Serial.print(onOffm);
  Serial.print("     ");
  Serial.print(motorSpeed);
  Serial.print("     ");
  Serial.println(motorDir);
}


