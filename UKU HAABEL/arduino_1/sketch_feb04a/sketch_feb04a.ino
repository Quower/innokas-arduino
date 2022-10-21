#define r1 A0
#define s1 A1
#define s 2
#define gsc 3
#define gs 4
#define sc 5
#define buttonPin 8
int qwerty;
int ArrayLenght = 64;
int qw;
String SendBinary[] = {
  "00101010",
  "10101010",
  "00101010",
  "10101010",
  "10101010",
  "00101010",
  "10101010",
  "00101010",
  "10101010",
  "10101010",
  "00101010",
  "10101010",
  "00101010",
  "10101010",
  "10101010",
  "00101010",
  "10101010",
  "00101010",
  "10101010",
  "10101010",
  "00101010",
  "10101010",
  "00101010",
  "10101010",
  "10101010",
  "00101010",
  "10101010",
  "00101010",
  "10101010",
  "10101010",
  "00101010",
  "10101010",
  "00101010",
  "10101010",
  "10101010",
  "00101010",
  "10101010",
  "00101010",
  "10101010",
  "10101010",
  "00101010",
  "10101010",
  "00101010",
  "10101010",
  "10101010",
  "00101010",
  "10101010",
  "00101010",
  "10101010",
  "10101010",
  "00101010",
  "10101010",
  "00101010",
  "10101010",
  "10101010",
  "00101010",
  "10101010",
  "00101010",
  "10101010",
  "10101010",
  "00101010",
  "10101010",
  "00101010",
  "10101010",
  "10101010",
  "00101010",
  "10101010",
  "00101010",
  "10101010",
  "10101010",
  "00101010",
  "10101010",
  "00101010",
  "10101010",
  "10101010",
  "00101010",
  "10101010",
  "00101010",
  "10101010",
  "10101010",
  };





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
  while(1){
    if (digitalRead(buttonPin) == HIGH) {
      delay(500);
      //Serial.println(TextToBinary("dab6969"));
      
    qw = millis();  
    for(int i = 0; i < ArrayLenght; i++){
    Send(SendBinary[i]);
    }
    qw = millis() - qw; 
    Serial.println(qw);
      return;
    }
    if (digitalRead(gs) == HIGH) {
      String text;
    text = Recive();
    Serial.println(text);
      return;
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
String Recive(){
  String textC;
  textC = analogRead(r1);
  digitalWrite(sc, HIGH);
  while(1){
    if (digitalRead(gs) == LOW) {
      digitalWrite(sc, LOW);
      return textC;
    }
  }
}
void Send(String binary){
  int num;
for(int i = 0; i<8; i++){
  num = num + binary.charAt(i)*i;
}

  analogWrite(s1, num);


 digitalWrite(s, HIGH);
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

