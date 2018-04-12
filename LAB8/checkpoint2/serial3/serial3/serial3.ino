// RS232 get and print data
char incomingByte = 0;

void setup() 
{ 
  Serial.begin(9600); 

  // prints title with ending line break 
  Serial.println("Reads incoming serial data"); 
} 

void loop()
{
  if (Serial.available() > 0) 
  {
    incomingByte = Serial.read();  // read the incoming byte:
    Serial.print("I received :  ");     //say what you got:
    Serial.print(incomingByte);
    Serial.print(" ");
    Serial.print(incomingByte, DEC);
    Serial.print(" ");
    Serial.println(incomingByte, HEX);
  }
}

