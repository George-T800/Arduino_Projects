//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4); // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  lcd.init();                      // initialize the lcd
  lcd.init();
  // Print a message to the LCD.

}


void loop()
{
  lcd.backlight();
  lcd.setCursor(1, 0); //X da Y gerdze gavaketot gasarkvevad. itoqshi pirveli 0 iani aris x mdebareoba anu wers aso H kideshi xolod meore wervi prchxilebshi aris y mnishvneloba anu shemdegi striqoni
  lcd.print("Hello, world!");
  delay (500);
  lcd.setCursor(1, 0);
  lcd.print(".");
//  


}
