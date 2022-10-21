#include <SPI.h>
#include <TFT.h>

#define p A0
#define y A1
#define x A2
#define CS   10
#define DC   9
#define RESET  8

#define bgR 255
#define bgG 255
#define bgB 255
#define renderHeight 20
#define renderWidht 20

int renderX = 5;
int renderY = 5;
int prenderX = 5;
int prenderY = 5;

//screen start 2,3

int pictureR[] {
  -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
  -1,-1,-1,-1,-1,-1,-1,-1,0,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,
  -1,-1,-1,-1,-1,-1,-1,0,0,0,0,0,0,0,-1,-1,-1,-1,-1,-1,
  -1,-1,-1,-1,-1,0,0,0,0,0,0,-1,-1,-1,0,-1,-1,-1,-1,-1,
  -1,0,0,0,0,-1,-1,0,0,-1,0,-1,-1,-1,-1,0,-1,-1,-1,-1,
  0,-1,-1,-1,-1,0,0,0,0,-1,-1,0,-1,-1,-1,-1,0,-1,-1,-1,
  -1,0,-1,-1,-1,0,0,-1,0,-1,-1,-1,0,-1,-1,-1,-1,0,-1,-1,
  -1,-1,0,0,0,-1,-1,-1,-1,0,-1,-1,0,-1,-1,-1,-1,-1,0,-1,
  -1,-1,-1,0,-1,-1,-1,-1,-1,-1,0,-1,-1,0,-1,-1,-1,-1,0,-1,
  -1,-1,-1,0,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,0,-1,-1,-1,-1,0,
  -1,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,0,0,0,-1,0,
  -1,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,-1,0,-1,
  -1,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,0,-1,-1,0,0,-1,
  -1,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,0,-1,-1,-1,
  -1,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,
  -1,-1,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,
  -1,-1,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,
  -1,-1,-1,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,-1,
  -1,-1,-1,-1,-1,0,0,-1,-1,-1,-1,-1,0,0,-1,-1,-1,-1,-1,-1,
  -1,-1,-1,-1,-1,-1,-1,0,0,0,0,0,-1,-1,-1,-1,-1,-1,-1,-1
};
int pictureG[] {
  -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
  -1,-1,-1,-1,-1,-1,-1,-1,0,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,
  -1,-1,-1,-1,-1,-1,-1,0,0,0,0,0,0,0,-1,-1,-1,-1,-1,-1,
  -1,-1,-1,-1,-1,0,0,0,0,0,0,-1,-1,-1,0,-1,-1,-1,-1,-1,
  -1,0,0,0,0,-1,-1,0,0,-1,0,-1,-1,-1,-1,0,-1,-1,-1,-1,
  0,-1,-1,-1,-1,0,0,0,0,-1,-1,0,-1,-1,-1,-1,0,-1,-1,-1,
  -1,0,-1,-1,-1,0,0,-1,0,-1,-1,-1,0,-1,-1,-1,-1,0,-1,-1,
  -1,-1,0,0,0,-1,-1,-1,-1,0,-1,-1,0,-1,-1,-1,-1,-1,0,-1,
  -1,-1,-1,0,-1,-1,-1,-1,-1,-1,0,-1,-1,0,-1,-1,-1,-1,0,-1,
  -1,-1,-1,0,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,0,-1,-1,-1,-1,0,
  -1,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,0,0,0,-1,0,
  -1,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,-1,0,-1,
  -1,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,0,-1,-1,0,0,-1,
  -1,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,0,-1,-1,-1,
  -1,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,
  -1,-1,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,
  -1,-1,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,
  -1,-1,-1,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,-1,
  -1,-1,-1,-1,-1,0,0,-1,-1,-1,-1,-1,0,0,-1,-1,-1,-1,-1,-1,
  -1,-1,-1,-1,-1,-1,-1,0,0,0,0,0,-1,-1,-1,-1,-1,-1,-1,-1
};
int pictureB[] {
  -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
  -1,-1,-1,-1,-1,-1,-1,-1,0,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,
  -1,-1,-1,-1,-1,-1,-1,0,0,0,0,0,0,0,-1,-1,-1,-1,-1,-1,
  -1,-1,-1,-1,-1,0,0,0,0,0,0,-1,-1,-1,0,-1,-1,-1,-1,-1,
  -1,0,0,0,0,-1,-1,0,0,-1,0,-1,-1,-1,-1,0,-1,-1,-1,-1,
  0,-1,-1,-1,-1,0,0,0,0,-1,-1,0,-1,-1,-1,-1,0,-1,-1,-1,
  -1,0,-1,-1,-1,0,0,-1,0,-1,-1,-1,0,-1,-1,-1,-1,0,-1,-1,
  -1,-1,0,0,0,-1,-1,-1,-1,0,-1,-1,0,-1,-1,-1,-1,-1,0,-1,
  -1,-1,-1,0,-1,-1,-1,-1,-1,-1,0,-1,-1,0,-1,-1,-1,-1,0,-1,
  -1,-1,-1,0,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,0,-1,-1,-1,-1,0,
  -1,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,0,0,0,-1,0,
  -1,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,-1,0,-1,
  -1,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,0,-1,-1,0,0,-1,
  -1,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,0,-1,-1,-1,
  -1,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,
  -1,-1,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,
  -1,-1,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,
  -1,-1,-1,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,-1,
  -1,-1,-1,-1,-1,0,0,-1,-1,-1,-1,-1,0,0,-1,-1,-1,-1,-1,-1,
  -1,-1,-1,-1,-1,-1,-1,0,0,0,0,0,-1,-1,-1,-1,-1,-1,-1,-1
};

//int Time1;




TFT myScreen = TFT(CS, DC, RESET);

void setup() {
    myScreen.begin();

  myScreen.background(0,0,0);
pinMode(p, INPUT);
pinMode(y, INPUT);
pinMode(x, INPUT);
Serial.begin(250000);
renderMainGUI();
}
void loop() {

int RP = 0;
//int vahearv = 0;
renderX = (map(analogRead(A1), 0, 1024, 2, myScreen.width()-renderWidht));
renderY = (map(analogRead(A2), 0, 1024, 2, myScreen.height()-renderHeight));
/*myScreen.fill(bgB,bgG,bgR);
myScreen.noStroke();
myScreen.rect(prenderX, prenderY, renderHeight, renderWidht);*/

int renderAwayX = renderX-prenderX;
      int renderAwayY = renderY-prenderY;
if(renderAwayX < renderWidht && renderAwayX > renderWidht*-1 && renderAwayY < renderHeight && renderAwayY > renderHeight*-1){
  myScreen.stroke(bgB,bgG,bgR);
for(int i1 = 0; i1<renderHeight; i1++){
    for(int i2 = 0; i2<renderWidht; i2++){
      if(prenderX+i2 > renderX && prenderX+i2 < renderX+renderWidht && prenderY+i1 > renderY && prenderY+i1 < renderY+renderHeight ){
        //Serial.println("true");
        //vahearv++;
      }
      else{
      if(pictureR[RP] == -1){
        //vahearv++;
      }
      else {
      
      myScreen.point(prenderX+i2,prenderY+i1);
      }
      
    
      }RP++;}}
    RP = 0;
    
  for(int i1 = 0; i1<renderHeight; i1++){
    for(int i2 = 0; i2<renderWidht; i2++){
      /*if(renderAwayX < i2*-1-1 && renderAwayX > renderWidht-i2){
        
      }
      else{*/
        
      
      int RPR = renderAwayX+(renderAwayY*10);
      //if (RPR < i1*10 && RPR >= i1*10+10 || yesno(RPR, i1, i2) == true) {
      if (RPR >= 0 && RPR <= renderWidht*renderHeight) {
      int PRColorB = pictureB[RPR];
      int PRColorG = pictureG[RPR];
      int PRColorR = pictureR[RPR];
      
      
      if(pictureB[RP]/*-vahearv*/ == PRColorB && pictureG[RP]/*-vahearv*/ == PRColorG && pictureR[RP] == PRColorR){
        
      }
      else {
        if(pictureR[RP] == -1){
        //vahearv++;
      }
      else {myScreen.stroke(pictureB[RP]/*-vahearv*/,pictureG[RP]/*-vahearv*/,pictureR[RP]);
      myScreen.point(renderX+i2,renderY+i1);}
      }}
      else {
        if(pictureR[RP] == -1){
        //vahearv++;
        myScreen.stroke(bgB,bgG,bgR);
        myScreen.point(renderX+i2,renderY+i1);
      }
      else {
        myScreen.stroke(pictureB[RP]/*-vahearv*/,pictureG[RP]/*-vahearv*/,pictureR[RP]);
        myScreen.point(renderX+i2,renderY+i1);
      }
      }
      
      
      RP++;
      //}
    }
  }
  }


 else {
  myScreen.stroke(bgB,bgG,bgR);
for(int i1 = 0; i1<renderHeight; i1++){
    for(int i2 = 0; i2<renderWidht; i2++){
      if(pictureR[RP] == -1){
        //vahearv++;
      }
      else {
      
      myScreen.point(prenderX+i2,prenderY+i1);
      }
      RP++;
    
    }}
    RP = 0;
  for(int i1 = 0; i1<renderHeight; i1++){
    for(int i2 = 0; i2<renderWidht; i2++){
      if(pictureR[RP] == -1){
        //vahearv++;
      }
      else {
      myScreen.stroke(pictureB[RP]/*-vahearv*/,pictureG[RP]/*-vahearv*/,pictureR[RP]);
      myScreen.point(renderX+i2,renderY+i1);
      }
      RP++;
    
    }
  }
 }
prenderX = renderX;
prenderY = renderY;
}

void renderMainGUI (){
  myScreen.stroke(255, 255, 255);
myScreen.fill(bgB,bgG,bgR);
myScreen.rect(1,2,myScreen.width()-1,myScreen.height()-2);

}

boolean yesno (int PPP, int ii1, int ii2) {
  if (PPP >= 0 && PPP <= renderWidht*renderHeight){
    for ( int i = -1; i<renderHeight; i++){
      if(i*10+ii2 == PPP){
        return true;
      }
    }
  }
  else {
    return false;
  }
  return false;
   
}

