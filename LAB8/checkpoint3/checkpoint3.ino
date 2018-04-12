#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int tmp = 0, ss = 0,mm = 0 , hh = 0; 

void setup() {

  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("HH:MM:SS");
}

void loop() {
    lcd.setCursor(0,1);
    tmp = (millis()/10);
    ss = tmp % 60;
    mm = (tmp / 60)%60;
    hh = (tmp/ 60 /60)%24;
    
    if (hh<10)
      lcd.print("0");
      lcd.print(hh);
      lcd.print(":");
     
    if (mm<10)
      lcd.print("0");
      lcd.print(mm);
      lcd.print(":");
      
     if (ss<10)
      lcd.print("0");
      lcd.print(ss);
      
    if(hh == 24)
      hh = 0;
    mm = 0;
    ss = 0;
}
