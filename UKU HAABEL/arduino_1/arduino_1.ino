#define R 6
#define G 5
#define B 3


void setup() {
pinMode(R, OUTPUT);
pinMode(G, OUTPUT);
pinMode(B, OUTPUT);

}

void loop() {
  
color(random(0, 255), random(0, 255), random(0, 255)); 
delay(69);
 

}
void color(int Red, int Green, int Blue){
  Red = (255 - Red);
  Green = (255 - Green);
  Blue = (255 - Blue);
  analogWrite(R, Red);
  analogWrite(G, Green);
  analogWrite(B, Blue);   
  
}

