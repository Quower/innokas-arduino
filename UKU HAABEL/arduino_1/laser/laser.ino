#define laser 3

String messagebin = "hiina";
int bitdelay = 20;
// int bytetdelay = 8;
int wait = 16;
int out1 = 255;
int out0 = 0;
long mills = 0;

void setup()
{
    pinMode(laser, OUTPUT);
    Serial.begin(250000);
}

void loop()
{
    while (Serial.available())
    {
        messagebin = Serial.readString();
        
    }
    String message = TextToBinary(messagebin);
    analogWrite(laser, out1);
    delay(bitdelay * 8);

    Serial.println(message);
    for (int i = 0; i < message.length(); i++)
    {
        mills = millis();
        if (message[i] == '1')
        {
            analogWrite(laser, out1);
        }
        else if (message[i] == '0')
        {
            analogWrite(laser, out0);
        }
        delay(mills - millis() + bitdelay);
    }
    analogWrite(laser, 0);
    delay(bitdelay * wait);
}

String TextToBinary(String convertText)
{
    String convertedText;
    for (int i = 0; i < convertText.length(); i++)
    {

        char myChar = convertText.charAt(i);

        for (int i = 7; i >= 0; i--)
        {
            delay(5);
            byte bytes = bitRead(myChar, i);
            convertedText = convertedText + bytes;
        }
    }
    return convertedText;
}
String CharToBinary(char myChar)
{
    String convertedChar;

    for (int i = 7; i >= 0; i--)
    {
        byte bytes = bitRead(myChar, i);
        convertedChar = convertedChar + bytes;
    }

    return convertedChar;
}