#include <LiquidCrystal.h>

#include <Servo.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

Servo mootor;
long lastT;
long curT;
float temperature[50];
int tempN;
float tempM = 0;

#define temp A0
int tempr;
void setup() {
  pinMode(temp, INPUT);
  Serial.begin(9600);
  mootor.attach(10);
  lcd.begin(16, 2);
}

void loop() {
 curT = (millis()-lastT);
 int read = analogRead(temp);
 Serial.print(read);
 Serial.print("          ");
 float volt = (read/1024.0) * 5.0;
 Serial.print(volt);
 Serial.print("          ");
 float tempr = (volt - .5) * 100.0;
 Serial.println(tempr);
 tempN = tempN+1;
 temperature[tempN] = tempr;
 
 if (curT >= 100) {
  lastT = millis();
  Serial.println(tempN);
  for (int i = 1; i<tempN; i++) {
    tempM = tempM+temperature[i];
    Serial.print(temperature[i]);
    Serial.print("          ");
    Serial.println(tempM);
  }
  Serial.println(tempM/tempN);
  lcd.clear();
  lcd.print(tempM/tempN);
  mootor.write(map(tempM/tempN, 15, 25, 0, 180));
  
  tempN = 0;
  tempM = 0;
  
 }
 
 
}
