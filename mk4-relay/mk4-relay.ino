#include <Irrigation.h>

Irrigation irrigation0(A0, 2, 5);
Irrigation irrigation1(A1, 3, 18);
Irrigation irrigation2(A2, 4, 50);

void setup() {
  Serial.begin(9600); // open serial port, set the baud rate to 9600 bps
  Serial.println("---------------------");
}

void loop() {
  irrigation0.work();

  Serial.print("A0: ");
  Serial.print(irrigation0.getHumidity());
  Serial.print("% --- ");
  Serial.println(irrigation0.getValve());


  irrigation1.work();

  Serial.print("A1: ");
  Serial.print(irrigation1.getHumidity());
  Serial.print("% --- ");
  Serial.println(irrigation1.getValve());


  irrigation2.work();

  Serial.print("A2: ");
  Serial.print(irrigation2.getHumidity());
  Serial.print("% --- ");
  Serial.println(irrigation2.getValve());

  Serial.println("-----");
  
  delay(1000);
}
