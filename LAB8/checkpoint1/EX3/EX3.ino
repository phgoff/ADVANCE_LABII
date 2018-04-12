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
// Turn off the blinking cursor:
  lcd.noBlink();
  delay(1000);

 // Turn on the blinking cursor:
  lcd.blink();
  delay(1000);
}

