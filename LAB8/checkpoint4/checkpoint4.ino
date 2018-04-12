#include <LiquidCrystal.h>
//initialize
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int tmp=0,votds, words;
int ss = 0,mm = 0,hh = 0;

void setup(){
  Serial.begin(9600);
//set up the LCD's number of coluans and rovs
lcd.begin(16,2);
lcd.print ("HH:MM:SS");}

void loop(){
 lcd.setCursor (0,1);
 tmp=(millis()/1);
 ss= tmp % 60;
 mm =(tmp/60)%60;
 hh =(tmp/60/60)%24;

  if (hh<10)
  lcd.print("0");
  lcd.print (hh);
  lcd.print(":");
  
  if (mm<10)
  lcd.print("0");
  lcd.print (mm);
  lcd.print(":");
  
   if (ss<10)
  lcd.print("0");
  lcd.print (ss);
  words = Serial.read();
   
if (words =='h'){
  Serial.print("Hours: ");
  Serial.println(hh) ;
  
}

if (words =='m'){
  Serial.print("Minute: ");
  Serial.println(mm) ;
  
}

if (words =='s'){
  Serial.print("Second: ");
  Serial.println(ss) ;
}}
