#define nupp 5
#define kollane 2
#define roheline 3
#define punane 4

void setup() {
pinMode(nupp, INPUT);
pinMode(kollane, OUTPUT);
pinMode(roheline, OUTPUT);
pinMode(punane, OUTPUT);
Serial.begin(9600);
}

void loop() {
Serial.println(analogRead(nupp));

}

