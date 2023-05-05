#include <LiquidCrystal.h>
#define trig 9
#define echo 6

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
byte china[] = {
B00100,B00100,B00100,B00100,B00100,B00100,B00100
};

void setup()
{
    lcd.begin(16, 2);
    lcd.createChar(0, china);
    pinMode(trig, OUTPUT);
    pinMode(echo, INPUT);
}
void loop()
{
    lcd.setCursor(1,0);
    lcd.write(byte(0));
}