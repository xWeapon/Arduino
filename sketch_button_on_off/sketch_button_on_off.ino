/*
 * Configurazione di: 
 * - GPIO G2 come pin che riceve il segnale di un LED
 * - GPIO G4 come pin che pilota un bottone
 * Assenza di resistenza di pull up nel circuito; utilizzo della funzione INPUT_PULLUP
 * Author: Ahir A.
*/
int pinLed = 2;
int button = 4;

int led_stat = LOW;
int button_stat;
int button_stat_m;

void setup() {
  Serial.begin(9600);
  pinMode(pinLed, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  button_stat = digitalRead(button);
  button_stat_m = digitalRead(button);
}

void loop() {
  button_stat_m = button_stat;
  button_stat = digitalRead(button);

  if(button_stat_m == HIGH && button_stat == LOW) {
    led_stat = !led_stat;
    Serial.println("Bottone premuto");
    digitalWrite(pinLed,led_stat);
  }
}
