int RelayControl1 = 2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(RelayControl1, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(RelayControl1,HIGH);// NO1 and COM1 Connected (LED on)
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(4000);
  
  digitalWrite(RelayControl1,LOW);// NO1 and COM1 disconnected (LED off) (energizado)
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW (apagado)
  delay(4000);
}
