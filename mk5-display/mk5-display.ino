#include <Nokia_LCD.h>

Nokia_LCD lcd(13 /* CLK */,
              12 /* DIN */,
              11 /* DC */,
              10 /* CE */,
              9 /* RST */,
              8 /* BL */);


void setup() {
  // Initialize the screen
  lcd.begin();
  // Turn on the backlight
  lcd.setBacklight(true);
  // Set the contrast
  lcd.setContrast(60);  // Good values are usualy between 40 and 60
  // Clear the screen by filling it with white pixels
  lcd.clear();
  // Turn off the backlight
  //lcd.setBacklight(false);
  // Set the cursor on the beginning of the 6th row (the last one)
  lcd.setCursor(0, 0);
  // Write something on the specific row with inverted color
  lcd.print("<== Status ==>");

  // The cursor is still on the 6th row. Newline characters ('\n') move the
  // cursor to the next line. Since we were on the last row, the cursor goes
  // back to the first line. If you check the return value of `println`
  // it will indicate whether an out-of-bounds error occured. In this case it
  // will be `true`.
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0, 2);
  lcd.print("S1: ");
  lcd.print("20/80");
  lcd.print(" A");
  lcd.setCursor(0, 3);
  lcd.print("S2: ");
  lcd.print("20/90");
  lcd.print(" A");  
  lcd.setCursor(0, 4);
  lcd.print("S3: ");    
  lcd.print("60/50");
  lcd.print(" C");  
}
