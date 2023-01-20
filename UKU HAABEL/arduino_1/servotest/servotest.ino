#include <Servo.h>
#define servo 10
#define pingPin 12
#define echoPin 11

Servo myservo;
void setup() {
    myservo.attach(servo);
    Serial.begin(250000);
}
void loop() {
    for(int i = 0; i<5;i = i+1) {
        myservo.write(i*36);
        delay(75);
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
        Serial.print(cm);
        Serial.print(" - ");
    }
    Serial.println("   done 1");
    for(int i = 5; i>0; i = i-1) {
        myservo.write(i*36);
        delay(75);
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
        Serial.print(cm);
        Serial.print(" - ");
    }
    Serial.println("   done 2");
   
}
long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}