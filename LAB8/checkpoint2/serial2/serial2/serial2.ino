// RS232 print data
void setup()
{ 
  Serial.begin(9600); 

  // prints title with ending line break 
  Serial.println("Prints data to the serial port : 0-20"); 
} 

int number = 0; 
void loop() 
{
  Serial.print("Number = ");
  Serial.println(number); 
   while(number >= 20)
     	continue; 
   number++;
}

