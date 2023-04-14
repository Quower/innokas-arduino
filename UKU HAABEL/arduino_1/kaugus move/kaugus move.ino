
#define trig 9
#define echo 6

// void setup()
// {
//     pinMode(trig, OUTPUT);
//     pinMode(echo, INPUT);
// }
// void loop()
// {
    // long time, distance;
    // digitalWrite(trig, LOW);
    // delayMicroseconds(2);
    // digitalWrite(trig, HIGH);
    // delayMicroseconds(10);
    // digitalWrite(trig, LOW);
    // time = pulseIn(echo, HIGH);
    // distance = time / 58.2;
// }

#include <Servo.h>

#include <SPI.h>
#include <TFT.h>

#define p A0
#define y A1
#define x A2
#define CS 10
#define DC 9
#define RESET 8
char TEXTE[4];

#define servo 11
int val = 0;

TFT myScreen = TFT(CS, DC, RESET);
Servo myservo;

void setup()
{
    myScreen.begin();
    myservo.attach(servo);

    myScreen.background(0, 0, 0);
    pinMode(p, INPUT);
    pinMode(y, INPUT);
    pinMode(x, INPUT);
    pinMode(trig, OUTPUT);
    pinMode(echo, INPUT);
    Serial.begin(2000000);
    myScreen.stroke(0, 0, 0);
    myScreen.fill(0, 0, 0);
    myScreen.rect(0, 0, 160, 20);
    myScreen.stroke(255, 255, 255);
    myScreen.textSize(2);
    myScreen.text("angle:", 5, 5);
}
void loop()
{
delay(25);
    int hiina = analogRead(y);
    int value = map(hiina, 0, 1024, 0, 180);
    myservo.write(value);
    long time, distance;
    digitalWrite(trig, LOW);
    delayMicroseconds(2);
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);
    time = pulseIn(echo, HIGH);
    distance = time / 58.2;
    Serial.println(distance);
    display(value, distance);
}

void display(int angle, int read)
{
    String(angle).toCharArray(TEXTE, 4);

    myScreen.stroke(0, 0, 0);
    myScreen.fill(0, 0, 0);
    myScreen.rect(80, 5, 34, 14);
    myScreen.textSize(2);
    myScreen.stroke(255, 255, 255);
    myScreen.text(TEXTE, 80, 5);
    if (val == 160)
    {
        val = 0;
    }

    myScreen.stroke(0, 0, 0);
    myScreen.fill(0, 0, 0);
    myScreen.rect(val, 30, 4, 98);
    myScreen.stroke(0, 200, 0);
    myScreen.fill(0, 200, 0);
    int kaga = map(read, 0, 150, 0, 98);
    if (kaga>98) {
        kaga = 98;
    }
    myScreen.line(val, 128, val, 128 - kaga);
    val++;
}