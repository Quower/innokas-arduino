#define temp A1
#define r 6
#define g 5
#define b 9

// long max = 80;
// long min = 30;
int value = 30;
int bitdelay = 20;
int adin = 0;
int number = 0;
int zero = 0;
long mills = 0;
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
    mills = millis();
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
    int nm = 0;
    //recording = recording + " ";
            if (recording[0] == '1') {nm = nm + 128;}
if (recording[1] == '1') {nm = nm + 64;}
if (recording[2] == '1') {nm = nm + 32;}
if (recording[3] == '1') {nm = nm + 16;}
if (recording[4] == '1') {nm = nm + 8;}
if (recording[5] == '1') {nm = nm + 4;}
if (recording[6] == '1') {nm = nm + 2;}
if (recording[7] == '1') {nm = nm + 1;}
    Serial.print((char)nm);



    recording = "";
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

        //Serial.println(recording);
        //Serial.print("|");
        Serial.println("");
        recording = "";

    }
    delay(mills - millis() + bitdelay);


}