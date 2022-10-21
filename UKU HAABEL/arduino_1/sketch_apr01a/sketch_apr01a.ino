#include <SPI.h>
#include <TFT.h>

#define p A0
#define y A1
#define x A2
#define CS   10
#define DC   9
#define RESET  8

int rng1-1;
int rng1-2;
int rng1-3;
int rng1-4;

int rng2-1;
int rng2-2;
int rng2-3;
int rng2-4;

int rng3-1;
int rng3-2;
int rng3-3;
int rng3-4;

int rng4-1;
int rng4-2;
int rng4-3;
int rng4-4;



TFT myScreen = TFT(CS, DC, RESET);

void setup() {
    myScreen.begin();

  myScreen.background(0,0,0);
pinMode(p, INPUT);
pinMode(y, INPUT);
pinMode(x, INPUT);
Serial.begin(250000);
Serial.print(myScreen.width());
Serial.print(myScreen.height());


}

void loop() {
Serial.print(analogRead(x));
Serial.print("   ");
Serial.print(analogRead(y));
Serial.print("   ");
Serial.println(analogRead(p));
renderMainGUI();
myScreen.setTextSize(3);
while(1){
for( int i = 0; i<45; i++){
  myScreen.noStroke();
  myScreen.fill(0, 0, 0);
  myScreen.rect(2,3,myScreen.width()-3,myScreen.height()-4);
  myScreen.stroke(0, 0, 0);
  myScreen.stroke(255, 255, 255);
  myScreen.text("12345",1+25,-25+i);
  myScreen.text("12345",1+25,20+i);
  myScreen.text("12345",1+25,65+i);
  myScreen.text("12345",1+25,110+i);
  myScreen.stroke(255, 255, 255);

//myScreen.rect(1,2,myScreen.width()-1,myScreen.height()-4);
}}
 /* myScreen.stroke(255, 0, 0); // set the stroke color to red

  myScreen.line(0, 10, myScreen.width(), 10); // draw a line across the screen

  delay(1000);

  myScreen.noStroke(); // don't draw a line around the next rectangle

  myScreen.fill(0,255,0); // set the fill color to green

  myScreen.rect(0,20,myScreen.width(),10); //draw a rectangle across the screen

  delay(1000);

  myScreen.fill(0,0,255); // set the fill color to blue

  myScreen.stroke(255,255,255); // outline the rectangle with a white line

  myScreen.rect(0,45,myScreen.width(),45); // draw a fat rectangle

  delay(1000);

  myScreen.background(0,0,0); // clear the screen before starting again
*
  delay(1000);*/
}
void renderMainGUI (){
  myScreen.stroke(255, 255, 255);
myScreen.fill(0,0,0);
myScreen.rect(1,2,myScreen.width()-1,myScreen.height()-2);

}

