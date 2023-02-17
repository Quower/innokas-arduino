#define laser 3

String messagebin = "hiina";
int bitdelay = 50;
//int bytetdelay = 8;
int wait = 16;
int out1 = 255;
int out0 = 0;

void setup()
{
    pinMode(laser, OUTPUT);
    Serial.begin(250000);
}

void loop()
{
String message = TextToBinary(messagebin);
    analogWrite(laser, out1);
        delay(bitdelay*8);
    
    Serial.println(message);
    // for (int i = 0; i < messagelenght; i++)
    // {
        for (int i = 0; i < message.length(); i++)
        {
            //Serial.print(message[i]);
            if (message[i] == '1')
            {
                analogWrite(laser, out1);
            }
            else if (message[i] == '0')
            {
                analogWrite(laser, out0);
            }
            delay(bitdelay);
        }
        //     for (int i5 = 0; i5 < bytetdelay; i5++) {

        //     analogWrite(laser, 0);
        //     delay(bitdelay);
        // }
    //}

        //analogWrite(laser, out1);
        //delay(bitdelay*8);

    analogWrite(laser, 0);
    delay(bitdelay*wait);
    //Serial.println(" ");
}

String TextToBinary(String convertText) {
String convertedText;
for(int i=0; i<convertText.length(); i++){

   char myChar = convertText.charAt(i);
  
    for(int i=7; i>=0; i--){
      delay(5);
      byte bytes = bitRead(myChar,i);
      convertedText = convertedText + bytes;
    }
    //convertedText = convertedText + " ";
}
return convertedText;
}
String CharToBinary(char myChar) {
String convertedChar;
  
    for(int i=7; i>=0; i--){
      byte bytes = bitRead(myChar,i);
      convertedChar = convertedChar + bytes;
    }

return convertedChar;
}