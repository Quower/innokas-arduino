#include <LiquidCrystal.h>
#define trig 9
#define echo 6

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
    lcd.begin(16, 2);
    pinMode(trig, OUTPUT);
    pinMode(echo, INPUT);
}
void loop()
{
    long time, distance;
    digitalWrite(trig, LOW);
    delayMicroseconds(2);
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);
    time = pulseIn(echo, HIGH);
    distance = time / 58.2;
    lcd.setCursor(1, 0);

    lcd.print("Sein on NII kaugel");
    lcd.setCursor(3, 1);

    lcd.print(distance);
    delay(100);
}