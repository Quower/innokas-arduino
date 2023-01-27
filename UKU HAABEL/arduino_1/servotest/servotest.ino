#include <Servo.h>
#define servo 10
#define pingPin 12
#define echoPin 11
#define mrb 6
#define mrf 3
#define mlf 5
#define mlb 9
#define calibratePin 8
int walldistance = 20;

Servo myservo;
void setup()
{
    myservo.attach(servo);
    Serial.begin(250000);
    pinMode(calibratePin, INPUT);
    pinMode(mrf, INPUT);
    pinMode(mrb, INPUT);
    pinMode(mlf, INPUT);
    pinMode(mlb, INPUT);
}
void loop()
{
    if (digitalRead(calibratePin) == HIGH)
    {
        analogWrite(mrb, 0);
        analogWrite(mrf, 0);
        analogWrite(mlb, 0);
        analogWrite(mlf, 0);
        Serial.print("calibrating - ");
        myservo.write(90);
        long duration, cm;
        pinMode(pingPin, OUTPUT);
        digitalWrite(pingPin, LOW);
        delayMicroseconds(2);
        digitalWrite(pingPin, HIGH);
        delayMicroseconds(10);
        digitalWrite(pingPin, LOW);
        pinMode(echoPin, INPUT);
        duration = pulseIn(echoPin, HIGH);
        cm = microsecondsToCentimeters(duration);
        Serial.println(cm);
        //walldistance = cm;
    }
    else
    {
        analogWrite(mrb, 0);
        analogWrite(mrf, 255);
        analogWrite(mlb, 0);
        analogWrite(mlf, 255);
        myservo.write(90);
        delay(50);
        long duration, cm;
        pinMode(pingPin, OUTPUT);
        digitalWrite(pingPin, LOW);
        delayMicroseconds(2);
        digitalWrite(pingPin, HIGH);
        delayMicroseconds(10);
        digitalWrite(pingPin, LOW);
        pinMode(echoPin, INPUT);
        duration = pulseIn(echoPin, HIGH);
        cm = microsecondsToCentimeters(duration);
        Serial.println(cm);
        if (walldistance > cm)
        {
            analogWrite(mrb, 0);
            analogWrite(mrf, 0);
            analogWrite(mlb, 0);
            analogWrite(mlf, 0);
            look(7);
            delay(1000);
        }
    }
}
long microsecondsToCentimeters(long microseconds)
{
    return microseconds / 29 / 2;
}

int look(int repeat)
{
    int avrageLeft = 0;
    int avrageRight = 0;
    for (int i = 0; i < repeat; i++)
    {
        myservo.write(0);
        delay(500);
        long duration, cm;
        pinMode(pingPin, OUTPUT);
        digitalWrite(pingPin, LOW);
        delayMicroseconds(2);
        digitalWrite(pingPin, HIGH);
        delayMicroseconds(10);
        digitalWrite(pingPin, LOW);
        pinMode(echoPin, INPUT);
        duration = pulseIn(echoPin, HIGH);
        cm = microsecondsToCentimeters(duration);
        avrageRight += cm;
        Serial.print(cm);
        Serial.print(" - ");
        myservo.write(180);
        delay(500);
        pinMode(pingPin, OUTPUT);
        digitalWrite(pingPin, LOW);
        delayMicroseconds(2);
        digitalWrite(pingPin, HIGH);
        delayMicroseconds(10);
        digitalWrite(pingPin, LOW);
        pinMode(echoPin, INPUT);
        duration = pulseIn(echoPin, HIGH);
        cm = microsecondsToCentimeters(duration);
        avrageLeft += cm;
        Serial.print(cm);
        Serial.print(" | ");
    }
    avrageLeft = avrageLeft / repeat;
    avrageRight = avrageRight / repeat;
    Serial.print("avrage: ");
    Serial.print(avrageLeft);
    Serial.print(" | ");
    Serial.print(avrageRight);
    Serial.println("    complete");
    myservo.write(90);
    if (avrageLeft > avrageRight)
    {
        analogWrite(mrb, 0);
        analogWrite(mrf, 0);
        analogWrite(mlb, 255);
        analogWrite(mlf, 255);
        delay(1000);
        return 2;
        
    }
    else
    {
        analogWrite(mrb, 255);
        analogWrite(mrf, 255);
        analogWrite(mlb, 0);
        analogWrite(mlf, 0);
        delay(1000);
        return 1;
    }
}
