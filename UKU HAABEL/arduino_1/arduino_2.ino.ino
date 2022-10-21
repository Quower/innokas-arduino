#define RED 2
#define GREEN 3
#define TEMP A0
void setup() {
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(TEMP, INPUT);
  serial.begin(9600);

}

void loop() {
  serial.println(analogRead(TEMP));

}
