#define redSensor A0 
#define greenSensor A1 
#define blueSensor A2
#define red 10
#define green 9
#define blue 11 

void setup() {
pinMode(redSensor, INPUT);
pinMode(greenSensor, INPUT);
pinMode(blueSensor, INPUT);
pinMode(red, OUTPUT);
pinMode(green, OUTPUT);
pinMode(blue, OUTPUT);
}

void loop() {
  analogWrite(red, analogRead(redSensor)/4);
  analogWrite(green, analogRead(greenSensor)/4);
  analogWrite(blue, analogRead(blueSensor)/4);

}
