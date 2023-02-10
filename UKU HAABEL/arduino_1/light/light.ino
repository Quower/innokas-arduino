#define temp A1
#define r 6
#define g 5
#define b 9

long max = 80;
long min = 30;
int bitdelay = 50;

void setup() {
    pinMode(temp, INPUT);
    pinMode(r, OUTPUT);
    pinMode(g, OUTPUT);
    pinMode(b, OUTPUT);
    Serial.begin(250000);
}

void loop() {
    long light = analogRead(temp);
    if (light > max) {
        digitalWrite(r, LOW);
        digitalWrite(g, HIGH);
        digitalWrite(b, LOW);
        Serial.print(" ");
    } else if (light < min) {
        digitalWrite(r, LOW);
        digitalWrite(g, LOW);
        digitalWrite(b, HIGH);
        Serial.print("1");
    } else {
        digitalWrite(r, HIGH);
        digitalWrite(g, LOW);
        digitalWrite(b, LOW);
        Serial.print("0");
    }
    delay(bitdelay);


}