// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);

  // Print a message to the LCD.
  lcd.print("SAY074 - GOF090");
}

void loop() {
  // Turn off the display:
  lcd.noBlink();
  delay(3000);

 // Turn on the blinking cursor:
  lcd.blink();
  delay(3000);
    lcd.setCursor(0, 1);//เลื่อน cursor
    for (int thisLetter = 0; thisLetter <= 9; thisLetter++) {
    lcd.setCursor(thisLetter,1);
    lcd.print(thisLetter);
    delay(500);
    }

}

