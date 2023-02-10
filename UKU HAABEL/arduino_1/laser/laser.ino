#define laser 3

String message[] = {
    "01101000", "01101001", "01101001", "01101110", "01100001"
};
int messagelenght = 5;
int bitdelay = 50;
int bytetdelay = 8;
int wait = 500;
int out1 = 255;
int out0 = 30;

void setup() {
    pinMode(laser, OUTPUT);
    Serial.begin(9600);
}

void loop() {

    for (int i3 = 0; i3 < 8; i3++) {
        analogWrite(laser, out0);
        delay(bitdelay);
    }
    Serial.print("|");
    for (int i = 0; i < messagelenght; i++) {
        for (int i2 = 0; i2 < 8; i2++) {
            Serial.print(message[i][i2]);
            if (message[i][i2] == '1') {
                analogWrite(laser, out1);
            } else if (message[i][i2] == '0') {
                analogWrite(laser, out0);
            }
            delay(bitdelay);
        }
        for (int i5 = 0; i5 < bytetdelay; i5++) {
        
        analogWrite(laser, 0);
        delay(bitdelay);
    }
        Serial.print("|");

    }
    for (int i4 = 0; i4 < 8; i4++) {
        analogWrite(laser, out0);
        delay(bitdelay);
    }
    analogWrite(laser, 0);
    delay(wait);
    Serial.println(" ");


}