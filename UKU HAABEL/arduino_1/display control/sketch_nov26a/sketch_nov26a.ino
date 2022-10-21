#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
/*int red0 = 10;
int green0 = 9;
int blue0 = 6;
int motor0 = A3;*/                                 
String button;
int lcdpos1 = 0;
int lcdpos2 = 0;
int motor_speed = 69;
int mode = 0;
/*int brg = 0;
int red = 50;
int blue = 50;
int green = 50;
int mp;*/



void setup() {
  lcd.begin(16, 2);
  pinMode(10, INPUT);//down
  pinMode(9, INPUT);//right
  pinMode(8, INPUT);//up
  pinMode(7, INPUT);//left
  pinMode(6, INPUT);//enter
  pinMode(13, INPUT);//back
  /*pinMode(red0, OUTPUT);
  pinMode(green0, OUTPUT);
  pinMode(blue0, OUTPUT);
  pinMode(motor0, OUTPUT);*/
 
  Serial.begin(9600);

}

void loop() {
  delay(100);
  if(digitalRead(10)==HIGH){
    lcd.clear();
    //lcd.print("[down]");
    button = "down";
    if (mode == 0) {
      lcdpos2 = lcdpos2 + 1;
    }
    
    Serial.println("test  s");
  }
  else if(digitalRead(9)==HIGH){
    lcd.clear();
    //lcd.print("right");
    button = "right";
    if (mode == 0) {
      lcdpos1 = lcdpos1 + 5;
    }
    else {
      if (lcdpos1 == 0) {
        if (lcdpos2 == 0) {
          motor_speed++;
        }
        
      }
    }
    
    Serial.println("test d");
  }
  else if(digitalRead(8)==HIGH){
    lcd.clear();
    //lcd.print("up");
    button = "up";
    if (mode == 0) {
      lcdpos2 = lcdpos2 - 1;
    }
    
    Serial.println("test w");
  }
  else if(digitalRead(7)==HIGH){
    lcd.clear();
    //lcd.print("left");
    button = "left";
    if (mode == 0) {
      lcdpos1 = lcdpos1 - 5;
    }
    else if (mode == 1){
      if (lcdpos1 == 0) {
        if (lcdpos2 == 0) {
          motor_speed--;
        }
      }
    }
    
    Serial.println("test a");
  }
  else if(digitalRead(6)==HIGH){
    lcd.clear();
    //lcd.print("enter");
    button = "enter";
    mode = 1;
    Serial.println("test e");
  }
  else if(digitalRead(13)==HIGH){
    lcd.clear();
    //lcd.print("back");
    button = "back";
    mode = 0;
    Serial.println("test b");
  }
  if (lcdpos1>10){
    lcdpos1 = 10;
  }
  else if (lcdpos1<0){
    lcdpos1 = 0;
  }
  else if (lcdpos2>1){
    lcdpos2 = 1;
  }
  else if (lcdpos2<0){
    lcdpos2 = 0;
  }
  Serial.print(lcdpos1);
  Serial.print("    ");
  Serial.print(mode);
  Serial.print("    ");
  Serial.println(lcdpos2);
  
  
  lcd.setCursor(lcdpos1, lcdpos2);
  lcd.print("[");
  lcd.setCursor(lcdpos1+5, lcdpos2);
  lcd.print("]");
  lcd.setCursor(1, 0);
  lcd.print(motor_speed);
  lcd.setCursor(4, 0);
  lcd.print("%");
  //mp = map(brg, 0, 100, 0, 255);
  //analogWrite(red0, map(red, 0, 100, 0, mp));
  //analogWrite(blue0, map(blue, 0, 100, 0, mp));
  //analogWrite(green0, map(green, 0, 100, 0, mp));
  //analogWrite (A0, 90);
  analogWrite(A0, map(motor_speed, 0, 100, 0, 256));
  
  
  /*lcd.print("your mom");
  lcd.setCursor(0, 1);
  lcd.print("your dad");
  delay(2000);
  lcd.clear();
  delay(2000);*/
}
