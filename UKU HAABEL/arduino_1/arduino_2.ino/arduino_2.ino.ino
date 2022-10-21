#define RED 2
#define GREEN 3
#define TEMP A0
float TEMP_C;
float TEMP_0;
void setup() {
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(TEMP, INPUT);
  Serial.begin(9600);

}

void loop() {
TEMP_0 = analogRead(TEMP);
  TEMP_C = map(TEMP_0, 0, 1024, -50, 120);
  Serial.println(analogRead(TEMP_0));
  if (TEMP_0>500) {
    digitalWrite(RED, HIGH);
    digitalWrite(GREEN, LOW);
  }
  else {
    digitalWrite(GREEN, HIGH);
    digitalWrite(RED, LOW);
  }

}
