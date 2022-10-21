#include <IRremote.h> // >v3.0.0
                                            
#define PIN_SEND 3
#define pinx A2
#define piny A1
#define pinv A0
int x = 0;
int y = 0;
int v = 0;

void setup()  
{  
  IrSender.begin(PIN_SEND); // Initializes IR sender
  pinMode(pinx, INPUT);
  pinMode(piny, INPUT);
  pinMode(pinv, INPUT);
  Serial.begin(250000);
}  
                               
void loop()  
{  
  /*IrSender.sendNEC(255, 0x34, true, 0); 
  delay(50);*/
  x = analogRead(pinx);
  y = analogRead(piny);
  v = analogRead(pinv);
  Serial.print(x);
  Serial.print("   ");
  Serial.print(y);
  Serial.print("   ");
  Serial.println(v);
  x = x + 6001;
  y = y + 8001;
  IrSender.sendNEC(y, 0x0, true);
  delay(6);
  IrSender.sendNEC(x, 0x34, true);
  delay(5);
  
  
} 
