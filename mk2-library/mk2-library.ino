#include <Irrigation.h>

Irrigation irrigation(A0);

void setup() {
  Serial.begin(9600); // open serial port, set the baud rate to 9600 bps
}

void loop() {
  Serial.print(irrigation.measure());
  Serial.println("%");
  delay(250);
}
