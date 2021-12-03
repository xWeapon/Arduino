/*
 * Potentiometer calibration code
 */
int analogPin = 15;
float val;
float volt;


void setup() {
Serial.begin(9600);
pinMode(analogPin, INPUT);
}

void loop() {
  val = analogRead(analogPin);
 Serial.print("ADC: ");
 volt = 0.5 + 2 * (val - 493)/(2990 - 493);
 Serial.print(val);
 Serial.print("   Voltage [V]: ");
 Serial.println(volt);
  
  
  
  delay(500);
}
