#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int tmp = 999; 

void setup() {

  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2); //16char 2line
  // Print a message to the LCD.
  lcd.print("DYMICER");
  lcd.setCursor(0, 1);//เลื่อน cursor
  lcd.print(tmp);
}

void loop() {
}

