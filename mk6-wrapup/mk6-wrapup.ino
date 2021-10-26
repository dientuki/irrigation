#include <Irrigation.h>
#include <Nokia_LCD.h>
const byte T0 = 95;
const byte T1 = 75;
const byte T2 = 55;
char buffer[12];

Irrigation irrigation0(A0, 2, T0);
Irrigation irrigation1(A1, 3, T1);
Irrigation irrigation2(A2, 4, T2);

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
  // Set the cursor on the beginning
  lcd.setCursor(0, 0);
  // Write something on the specific row with inverted color
  lcd.print("<== Status ==>");
}

void loop() {
  irrigation0.work();

  sprintf(buffer, "S1: %d/%d %c", irrigation0.getHumidity(), T0, irrigation0.getPrettyValve());
  lcd.setCursor(0, 2);
  lcd.print(buffer);
  
  irrigation1.work();

  sprintf(buffer, "S2: %d/%d %c", irrigation1.getHumidity(), T1, irrigation1.getPrettyValve());
  lcd.setCursor(0, 3); 
  lcd.print(buffer);

  irrigation2.work();

  sprintf(buffer, "S3: %d/%d %c", irrigation2.getHumidity(), T2, irrigation2.getPrettyValve());
  lcd.setCursor(0, 4);
  lcd.print(buffer);
  
  delay(1000);
}
