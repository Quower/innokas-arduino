#define temp A1
#define r 6
#define g 5
#define b 9

// long max = 80;
// long min = 30;
int value = 50;
int bitdelay = 50;
int adin = 0;
int number = 0;
int zero = 0;
boolean record = false;
String recording = "";

void setup() {
    pinMode(temp, INPUT);
    pinMode(r, OUTPUT);
    pinMode(g, OUTPUT);
    pinMode(b, OUTPUT);
    Serial.begin(250000);
}

void loop() {
    long light = analogRead(temp);
    
    if (light > value) {
        digitalWrite(r, LOW);
        digitalWrite(g, LOW);
        digitalWrite(b, HIGH);
        if (record == true) {recording = recording + "0";}
        adin = 0;
        zero++;


    } else {
        digitalWrite(r, HIGH);
        digitalWrite(g, LOW);
        digitalWrite(b, LOW);
        if (record == true) {recording = recording + "1";}
        adin++;
        zero = 0;

    }
    if (record == true) {number++;}
    if (number == 8) {
    number = 0;
    recording = recording + " ";
    }
    if (adin == 8) {
        record = true;

        // Serial.print(recording);
        // Serial.print("|");
        // recording = "";

    }
    if (zero == 8) {
        record = false;
        number = 0;

        Serial.println(recording);
        //Serial.print("|");
        recording = "";

    }
    delay(bitdelay);


}