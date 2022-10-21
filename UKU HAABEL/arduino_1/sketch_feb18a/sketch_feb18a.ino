#define inputA A1 
#define outputA A0 
#define inputD 7 
#define outputD 8
#define inputP 10 
#define outputP 11 

int milli;

void setup() {
  pinMode(inputA, INPUT);
  pinMode(inputD, INPUT);
  pinMode(inputP, INPUT);
  pinMode(outputA, OUTPUT);
  pinMode(outputD, OUTPUT);
  pinMode(outputP, OUTPUT);
Serial.begin(9600);
digitalWrite(outputD, HIGH);
analogWrite(outputA, 0);
analogWrite(outputP, 0);
}

void loop() {
  digitalWrite(outputD, HIGH);
analogWrite(outputA, 100);
analogWrite(outputP, 20);
/*digitalWrite(outputD, HIGH);
analogWrite(outputA, 69);
analogWrite(outputP, 69);
milli = millis();
for(int i = 1; i<10; i++){
  digitalWrite(outputD, HIGH);
}Serial.print("digital "); 
Serial.println(millis() -milli);


milli = millis();
for(int i = 1; i<10; i++){
  digitalWrite(outputP, 69);
}Serial.print("PMW ");
Serial.println(millis() -milli);


milli = millis();
for(int i = 1; i<10; i++){
  digitalWrite(outputA, 69);
}Serial.print("analog "); 
Serial.println(millis() -milli);*/


milli = millis();
for(int i = 1; i<10; i++){
  Serial.println(digitalRead(inputD));
}Serial.print("digitalR ");
Serial.println(millis() -milli);


milli = millis();
for(int i = 1; i<10; i++){
  Serial.println(analogRead(inputP));
}Serial.print("PMWR ");
Serial.println(millis() -milli);


milli = millis();
for(int i = 1; i<10; i++){
  Serial.println(analogRead(inputA));
}Serial.print("analogR ");
Serial.println(millis() -milli);



}
