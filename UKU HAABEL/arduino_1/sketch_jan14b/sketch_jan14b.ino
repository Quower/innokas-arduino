#include <SPI.h>
#include <TFT.h>

#define CS   10
#define DC   9
#define RESET  8
#define x A10
#define y A9
#define CLICK A8
int Click;
TFT myScreen = TFT(CS, DC, RESET);

void setup() {
  pinMode(x, INPUT);
  pinMode(y, INPUT);
  pinMode(CLICK, INPUT);
  Serial.begin(9600);
  myScreen.begin();
  myScreen.background(0,0,0);
  

}

void loop() {
  if (analogRead(CLICK) == 0) {
    Click = 1;
  }
  else {
    Click = 0;
  }
    //myScreen.stroke(255, 0, 0);
    //myScreen.stroke(255,255,255);
    //myScreen.background(0,0,0);
    //myScreen.rect((map(analogRead(x), 0, 1024, 0, 100)+28), (map(analogRead(y), 0, 1024, 0, 100)+12), (map(analogRead(x), 0, 1024, 0, 100)+32), (map(analogRead(y), 0, 1024, 0, 100)+16)); 
  //myScreen.point(map(analogRead(x), 0, 1024, 0, 100), map(analogRead(y), 0, 1024, 0, 100));
  
  /*myScreen.line(0, 10, myScreen.width(), 10);
  delay(1000);
  myScreen.noStroke();
  myScreen.fill(0,255,0);
  myScreen.rect(0,20,myScreen.width(),10);
  delay(1000);
  myScreen.fill(0,0,255);
  myScreen.stroke(255,255,255);
  myScreen.rect(0,45,myScreen.width(),45);
  delay(1000);
  myScreen.background(0,0,0);*/
  Serial.print(Click);
  Serial.print("   ");
  Serial.print(analogRead(x));
  Serial.print("   ");
  Serial.println(analogRead(y));

}
