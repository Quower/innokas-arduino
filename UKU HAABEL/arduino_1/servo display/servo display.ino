#include <Servo.h>

#include <SPI.h>
#include <TFT.h>


#define p A0
#define y A1
#define x A2
#define CS   10
#define DC   9
#define RESET  8
char TEXTE[4];

#define servo 11

TFT myScreen = TFT(CS, DC, RESET);
Servo myservo;

void setup() {
    myScreen.begin();
    myservo.attach(servo);

  myScreen.background(0,0,0);
pinMode(p, INPUT);
pinMode(y, INPUT);
pinMode(x, INPUT);
Serial.begin(2000000);
}
void loop() {
    myScreen.stroke(255, 255, 255);
    myScreen.textSize(2);
    int hiina = analogRead(y);
    int value = map (hiina, 0, 1024, 0, 180);
    Serial.println(value);
    myservo.write(value);
    String(value).toCharArray(TEXTE, 4);
    myScreen.fill(255, 255, 255);
    myScreen.rect(30,30,70,70);
    myScreen.stroke(0, 0, 0);
    myScreen.text(TEXTE, 50, 50);

}
