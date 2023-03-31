#define r1 52
#define r2 50
#define r3 48
#define r4 46
#define r5 44
#define r6 42
#define r7 40
#define r8 38
#define s1 53
#define s2 51
#define s3 49
#define s4 47
#define s5 45
#define s6 43
#define s7 41
#define s8 39
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
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(s4, OUTPUT);
  pinMode(s5, OUTPUT);
  pinMode(s6, OUTPUT);
  pinMode(s7, OUTPUT);
  pinMode(s8, OUTPUT);
  pinMode(s, OUTPUT);
  pinMode(gsc, INPUT);
  pinMode(gs, INPUT);
  pinMode(sc, OUTPUT);
  pinMode(buttonPin, INPUT);
Serial.begin(250000);
}

void loop() {

  while(1){
    if (digitalRead(gs) == HIGH) {
    Serial.print((char)Recive1());
      return;
    }
    if (digitalRead(buttonPin) == HIGH) {
      delay(500);
    qw = millis();  
    for(int i = 0; i < sendText.length(); i++){
      String test = CharToBinary(sendText.charAt(i)); 
    Send(test);
    } 
    qw = millis() - qw;
    Serial.println(qw);
      return;
    }

    

    while(Serial.available()){
      sendText = Serial.readString()+"\n";
      Serial.println(sendText);
      qw = millis();  
    for(int i = 0; i < sendText.length(); i++){
      String test = CharToBinary(sendText.charAt(i)); 
    Send(test);
    } 
    qw = millis() - qw;
    Serial.println(qw);
      return;
      }
  }

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
  digitalWrite(s, HIGH);
if (binary.charAt(1) == '1'){digitalWrite(s1, HIGH);}else{digitalWrite(s1, LOW);}
if (binary.charAt(1) == '1'){digitalWrite(s2, HIGH);}else{digitalWrite(s2, LOW);}
if (binary.charAt(1) == '1'){digitalWrite(s3, HIGH);}else{digitalWrite(s3, LOW);}
if (binary.charAt(1) == '1'){digitalWrite(s4, HIGH);}else{digitalWrite(s4, LOW);}
if (binary.charAt(1) == '1'){digitalWrite(s5, HIGH);}else{digitalWrite(s5, LOW);}
if (binary.charAt(1) == '1'){digitalWrite(s6, HIGH);}else{digitalWrite(s6, LOW);}
if (binary.charAt(1) == '1'){digitalWrite(s7, HIGH);}else{digitalWrite(s7, LOW);}
if (binary.charAt(1) == '1'){digitalWrite(s8, HIGH);}else{digitalWrite(s8, LOW);}
 while(1){
    if (digitalRead(gsc) == HIGH) {
       digitalWrite(s, LOW);
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



