#define a1 2
#define f1 5
#define g1 6
#define e1 7
#define d1 8
#define b1 3
#define c1 4
void setup() 
{
    pinMode(a1, OUTPUT);
    pinMode(b1, OUTPUT);
    pinMode(c1, OUTPUT);
    pinMode(d1, OUTPUT);
    pinMode(e1, OUTPUT);
    pinMode(f1, OUTPUT);
    pinMode(g1, OUTPUT);
}
void loop() {
    number(random(1,9));
   delay(250);
   
}

void number(int number) {
    switch (number)
    {
    case 0:
        digitalWrite(a1, HIGH);
        digitalWrite(b1, HIGH);
        digitalWrite(c1, HIGH);
        digitalWrite(d1, HIGH);
        digitalWrite(e1, HIGH);
        digitalWrite(f1, HIGH);
        digitalWrite(g1, LOW);
    break;
    case 1:
        digitalWrite(a1, LOW);
        digitalWrite(b1, HIGH);
        digitalWrite(c1, HIGH);
        digitalWrite(d1, LOW);
        digitalWrite(e1, LOW);
        digitalWrite(f1, LOW);
        digitalWrite(g1, LOW);
        
    break;
    case 2:
        digitalWrite(a1, HIGH);
        digitalWrite(b1, HIGH);
        digitalWrite(c1, LOW);
        digitalWrite(d1, HIGH);
        digitalWrite(e1, HIGH);
        digitalWrite(f1, LOW);
        digitalWrite(g1, HIGH);
        
    break;
    case 3:
        digitalWrite(a1, HIGH);
        digitalWrite(b1, HIGH);
        digitalWrite(c1, HIGH);
        digitalWrite(d1, HIGH);
        digitalWrite(e1, LOW);
        digitalWrite(f1, LOW);
        digitalWrite(g1, HIGH);
        
    break;
    case 4:
    digitalWrite(a1, LOW);
        digitalWrite(b1, HIGH);
        digitalWrite(c1, HIGH);
        digitalWrite(d1, LOW);
        digitalWrite(e1, LOW);
        digitalWrite(f1, HIGH);
        digitalWrite(g1, HIGH);
        
    break;
    case 5:
    digitalWrite(a1, HIGH);
        digitalWrite(b1, LOW);
        digitalWrite(c1, HIGH);
        digitalWrite(d1, HIGH);
        digitalWrite(e1, LOW);
        digitalWrite(f1, HIGH);
        digitalWrite(g1, HIGH);
        
    break;
    case 6:
    digitalWrite(a1, HIGH);
        digitalWrite(b1, LOW);
        digitalWrite(c1, HIGH);
        digitalWrite(d1, HIGH);
        digitalWrite(e1, HIGH);
        digitalWrite(f1, HIGH);
        digitalWrite(g1, HIGH);
        
    break;
    case 7:
    digitalWrite(a1, HIGH);
        digitalWrite(b1, HIGH);
        digitalWrite(c1, HIGH);
        digitalWrite(d1, LOW);
        digitalWrite(e1, LOW);
        digitalWrite(f1, LOW);
        digitalWrite(g1, LOW);
        
    break;
    case 8:
    digitalWrite(a1, HIGH);
        digitalWrite(b1, HIGH);
        digitalWrite(c1, HIGH);
        digitalWrite(d1, HIGH);
        digitalWrite(e1, HIGH);
        digitalWrite(f1, HIGH);
        digitalWrite(g1, HIGH);
        
    break;
    case 9:
    digitalWrite(a1, HIGH);
        digitalWrite(b1, HIGH);
        digitalWrite(c1, HIGH);
        digitalWrite(d1, HIGH);
        digitalWrite(e1, LOW);
        digitalWrite(f1, HIGH);
        digitalWrite(g1, HIGH);
        
    break;
    
    }
}