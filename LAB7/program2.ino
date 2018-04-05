const  int rs_pin = 12;
const  int en_pin = 11;
const int  data_pin[] =  {5,4,3,2};

void write4bits(int value){
  delayMicroseconds(1);   //delay 1us
  digitalWrite(en_pin, HIGH);
  
  for(int i=0;i<4;i++)
    digitalWrite(data_pin[i],(value >> i) & 1);
   
  delayMicroseconds(1);
  digitalWrite(en_pin, LOW);
  delayMicroseconds(100);
}
// bool isData - false = command , true = data
void sendLCD8bits(int value, bool isData){
  if(isData) 
    digitalWrite(rs_pin, HIGH); // true - Data
  else
    digitalWrite(rs_pin, LOW); // false - command
  
  delayMicroseconds(1);
  write4bits(value >> 4); //4bit'H to 4bit'L
  write4bits(value);
  
  
}

void setupLCD(){
    pinMode(rs_pin, OUTPUT);
    pinMode(en_pin, OUTPUT);

    for(int i=0;i<4;i++)
      pinMode(data_pin[i], OUTPUT);
    
    digitalWrite(rs_pin, LOW);
    digitalWrite(en_pin, LOW);  
    
    delay(50);
    write4bits(0x03);
    delay(5);
    write4bits(0x03);
    delay(5);
    write4bits(0x03);
    delay(5);
    write4bits(0x02);
    delay(5);
    
   sendLCD8bits(0x28, false);
   sendLCD8bits(0x06, false);
   sendLCD8bits(0x0F, false);
   sendLCD8bits(0x01, false);
   delay(10);
}

void setup(){
  setupLCD();
}
// Display Character
void loop(){

  sendLCD8bits(0x53, true);  
  sendLCD8bits(0x45, true);
  sendLCD8bits(0x4E, true);
  sendLCD8bits(0x53, true);
  sendLCD8bits(0x4F, true);
  sendLCD8bits(0x52, true);
  sendLCD8bits(0x3A, true);
  
  //new line
  sendLCD8bits(0xC0, false);

  sendLCD8bits(0x56, true);  
  sendLCD8bits(0x4F, true);
  sendLCD8bits(0x4C, true);
  sendLCD8bits(0x54, true);
  sendLCD8bits(0x41, true);
  sendLCD8bits(0x47, true);
  sendLCD8bits(0x45, true);
  sendLCD8bits(0x3A, true);
 
  while(1);
}
