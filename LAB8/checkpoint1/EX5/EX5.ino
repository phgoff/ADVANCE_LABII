// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);

  // Print a message to the LCD.
  lcd.print("CODE S:074-090");
}

void loop() {
  
  lcd.setCursor(0,1);
  lcd.print("DISPLAY MODE");
  // Turn off the display:
  lcd.noDisplay();
  delay(500);

   // Turn on the display:
  lcd.display();
  delay(500);
}

