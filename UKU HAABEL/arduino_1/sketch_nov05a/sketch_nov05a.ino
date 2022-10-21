unsigned long prevTime = 0;
int led = 2;
int prevSwitchState = 0;
int switchState = 0;
long ledInterval = 764;

void setup() {
  // put your setup code here, to run once:

  pinMode(7, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
        
pinMode(8, INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
unsigned long curTime = millis();
Serial.print(curTime - prevTime);
Serial.print("   ");
Serial.print(led);
Serial.print("   ");
if (curTime - prevTime > ledInterval){
  prevTime = curTime;
  digitalWrite(led, HIGH);
  led++;
  if (led > 8){
    led = 8;
    /*for (int x = 0;x>10;x++){
       for (int i = 2;i>8;i++){
  digitalWrite(i, LOW);
    }
    delay(300);
    if (led == 7){
    for (int i = 2;i>8;i++){
  digitalWrite(i, HIGH);
    }
    delay(300);
    }
    }*/
   
  }
}
switchState = digitalRead(8);
Serial.println(switchState);
if(switchState != prevSwitchState){
       
  digitalWrite(7, LOW);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
    
    led = 2;
    prevTime = curTime;
}
prevSwitchState = switchState;
}
