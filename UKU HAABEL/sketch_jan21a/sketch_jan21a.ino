#define r1 52
#define r2 50
#define r3 48
#define r4 46
#define r5 44
#define r6 42
#define r7 40
#define r8 38
#define r9 36
#define r10 34
#define r11 32
#define r12 30
#define r13 28
#define r14 26
#define r15 24
#define r16 22
#define s1 53
#define s2 51
#define s3 49
#define s4 47
#define s5 45
#define s6 43
#define s7 41
#define s8 39
#define s9 37
#define s10 35
#define s11 33
#define s12 31
#define s13 29
#define s14 27
#define s15 25
#define s16 23
#define s 2
#define gsc 3
#define gs 4
#define sc 5
#define buttonPin 8
int qwerty;
int qw;
String sendText;




void setup() {
  pinMode(r1, INPUT);
  pinMode(r2, INPUT);
  pinMode(r3, INPUT);
  pinMode(r4, INPUT);
  pinMode(r5, INPUT);
  pinMode(r6, INPUT);
  pinMode(r7, INPUT);
  pinMode(r8, INPUT);
  pinMode(r9, INPUT);
  pinMode(r10, INPUT);
  pinMode(r11, INPUT);
  pinMode(r12, INPUT);
  pinMode(r13, INPUT);
  pinMode(r14, INPUT);
  pinMode(r15, INPUT);
  pinMode(r16, INPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(s4, OUTPUT);
  pinMode(s5, OUTPUT);
  pinMode(s6, OUTPUT);
  pinMode(s7, OUTPUT);
  pinMode(s8, OUTPUT);
  pinMode(s9, OUTPUT);
  pinMode(s10, OUTPUT);
  pinMode(s11, OUTPUT);
  pinMode(s12, OUTPUT);
  pinMode(s13, OUTPUT);
  pinMode(s14, OUTPUT);
  pinMode(s15, OUTPUT);
  pinMode(s16, OUTPUT);
  pinMode(s, OUTPUT);
  pinMode(gsc, INPUT);
  pinMode(gs, INPUT);
  pinMode(sc, OUTPUT);
  pinMode(buttonPin, INPUT);
Serial.begin(9600);
}

void loop() {
  qwerty = 0;
  while(Serial.available()){
      String sendText = Serial.readString();
      Serial.println(sendText);
      }
  while(1){
    if (digitalRead(buttonPin) == HIGH) {
      delay(500);
      //Serial.println(TextToBinary("dab6969"));
    qw = millis();  
    for(int i = 0; i < sendText.length()/2; i++){
      String test = CharToBinary(sendText.charAt(i*2)) + CharToBinary(sendText.charAt((i*2)+1)); 
    Send(test);
    } 
    qw = millis() - qw;
    Serial.println(qw);
      return;
    }

    
    if (digitalRead(gs) == HIGH) {
    Serial.print((char)Recive1());
    Serial.print((char)Recive2());
      return;
    }
    while(Serial.available()){
      sendText = Serial.readString();
      Serial.println(sendText);
      }
  }
  /*if (qwerty == 1) {
    Serial.println("test1.5");
    for(int i = 0; i < ArrayLenght; i++){
      Serial.println("test2");
    Send(SendBinary[i]);
    Serial.println("test3");
    }
  }
  if (qwerty == 2) {
    String text;
    Serial.println("test2_1");
    text = Recive();
    Serial.println("test3_1");
    Serial.println(text);
  }*/

}
byte Recive1(){
  byte textC;
if (digitalRead(r1) == HIGH) {textC = textC + 128;} else {textC = textC + 0;}
if (digitalRead(r2) == HIGH) {textC = textC + 64;} else {textC = textC + 0;}
if (digitalRead(r3) == HIGH) {textC = textC + 32;} else {textC = textC + 0;}
if (digitalRead(r4) == HIGH) {textC = textC + 16;} else {textC = textC + 0;}
if (digitalRead(r5) == HIGH) {textC = textC + 8;} else {textC = textC + 0;}
if (digitalRead(r6) == HIGH) {textC = textC + 4;} else {textC = textC + 0;}
if (digitalRead(r7) == HIGH) {textC = textC + 2;} else {textC = textC + 0;}
if (digitalRead(r8) == HIGH) {textC = textC + 1;} else {textC = textC + 0;}
return textC;
}
byte Recive2(){
  byte textC;
if (digitalRead(r9) == HIGH) {textC = textC + 128;} else {textC = textC + 0;}
if (digitalRead(r10) == HIGH) {textC = textC + 64;} else {textC = textC + 0;}
if (digitalRead(r11) == HIGH) {textC = textC + 32;} else {textC = textC + 0;}
if (digitalRead(r12) == HIGH) {textC = textC + 16;} else {textC = textC + 0;}
if (digitalRead(r13) == HIGH) {textC = textC + 8;} else {textC = textC + 0;}
if (digitalRead(r14) == HIGH) {textC = textC + 4;} else {textC = textC + 0;}
if (digitalRead(r15) == HIGH) {textC = textC + 2;} else {textC = textC + 0;}
if (digitalRead(r16) == HIGH) {textC = textC + 1;} else {textC = textC + 0;}
  digitalWrite(sc, HIGH);
  while(1){
    if (digitalRead(gs) == LOW) {
      digitalWrite(sc, LOW);
      return textC;
    }
  }
}
void Send(String binary){
  //digitalWrite(s1, binary.charAt(0));
 if (binary.charAt(0) == '1'){
  digitalWrite(s1, HIGH);
 }
 digitalWrite(s, HIGH);
 if (binary.charAt(1) == '1'){
  digitalWrite(s2, HIGH);
 }
 if (binary.charAt(2) == '1'){
  digitalWrite(s3, HIGH);
 }
 if (binary.charAt(3) == '1'){
  digitalWrite(s4, HIGH);
 }
 if (binary.charAt(4) == '1'){
  digitalWrite(s5, HIGH);
 }
 if (binary.charAt(5) == '1'){
  digitalWrite(s6, HIGH);
 }
 if (binary.charAt(6) == '1'){
  digitalWrite(s7, HIGH);
 }
 if (binary.charAt(7) == '1'){
  digitalWrite(s8, HIGH);
 }
 if (binary.charAt(8) == '1'){
  digitalWrite(s9, HIGH);
 }
 if (binary.charAt(9) == '1'){
  digitalWrite(s10, HIGH);
 }
 if (binary.charAt(10) == '1'){
  digitalWrite(s11, HIGH);
 }
 if (binary.charAt(11) == '1'){
  digitalWrite(s12, HIGH);
 }
 if (binary.charAt(12) == '1'){
  digitalWrite(s13, HIGH);
 }
 if (binary.charAt(13) == '1'){
  digitalWrite(s14, HIGH);
 }
 if (binary.charAt(14) == '1'){
  digitalWrite(s15, HIGH);
 }
 if (binary.charAt(15) == '1'){
  digitalWrite(s16, HIGH);
 }
 while(1){
    if (digitalRead(gsc) == HIGH) {
       digitalWrite(s, LOW);
 digitalWrite(s1, LOW);
 digitalWrite(s2, LOW);
 digitalWrite(s3, LOW);
 digitalWrite(s4, LOW);
 digitalWrite(s5, LOW);
 digitalWrite(s6, LOW);
 digitalWrite(s7, LOW);
 digitalWrite(s8, LOW);
 digitalWrite(s9, LOW);
 digitalWrite(s10, LOW);
 digitalWrite(s11, LOW);
 digitalWrite(s12, LOW);
 digitalWrite(s13, LOW);
 digitalWrite(s14, LOW);
 digitalWrite(s15, LOW);
 digitalWrite(s16, LOW);
      return;
    } 
  }
}
String TextToBinary(String convertText) {
String convertedText;
for(int i=0; i<convertText.length(); i++){

   char myChar = convertText.charAt(i);
  
    for(int i=7; i>=0; i--){
      byte bytes = bitRead(myChar,i);
      convertedText = convertedText + bytes;
    }
    convertedText = convertedText + " ";
}
return convertedText;
}
String CharToBinary(char myChar) {
String convertedChar;
  
    for(int i=7; i>=0; i--){
      byte bytes = bitRead(myChar,i);
      convertedChar = convertedChar + bytes;
    }

return convertedChar;
}



