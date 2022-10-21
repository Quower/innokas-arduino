#define r1 8
#define s1 7
#define s 2
#define gsc 3
#define gs 4
#define sc 5
#define buttonPin 6
int qwerty;
int qw;
String sendText;




void setup() {
  pinMode(r1, INPUT);
  pinMode(s1, OUTPUT);
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
      Serial.println("test1");
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
      sendText = Serial.readString();
      Serial.println(sendText);
      }
  }
 if (digitalRead(gs) == HIGH) {
    Serial.print(Recive(),BIN);
    Serial.println(" ");
      return;
    }
}
byte Recive(){
  byte textC;
if (digitalRead(r1) == HIGH) {textC = textC + 128;} else {textC = textC + 0;}
if (digitalRead(r1) == HIGH) {textC = textC + 64;} else {textC = textC + 0;}
if (digitalRead(r1) == HIGH) {textC = textC + 32;} else {textC = textC + 0;}
if (digitalRead(r1) == HIGH) {textC = textC + 16;} else {textC = textC + 0;}
if (digitalRead(r1) == HIGH) {textC = textC + 8;} else {textC = textC + 0;}
if (digitalRead(r1) == HIGH) {textC = textC + 4;} else {textC = textC + 0;}
if (digitalRead(r1) == HIGH) {textC = textC + 2;} else {textC = textC + 0;}
if (digitalRead(r1) == HIGH) {textC = textC + 1;} else {textC = textC + 0;}
digitalWrite(sc, HIGH);
  while(1){
    if (digitalRead(gs) == LOW) {
      digitalWrite(sc, LOW);
      return textC;
    }
  }   
  
}


void Send(String binary){
  digitalWrite(s, HIGH);
  delay(1);
  for(int i = 0; i<8; i++){
     if (binary.charAt(i) == '1'){digitalWrite(s1, HIGH);}
     digitalWrite(s1, LOW);
     
 }
  while(1){
    if (digitalRead(gsc) == HIGH) {
       digitalWrite(s, LOW);return;}}
  
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



