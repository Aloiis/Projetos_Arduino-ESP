// Pin do LED
const int ledPin = 13;

void setup() {
  // Inicializa o pino do LED como saída
  pinMode(ledPin, OUTPUT);
}

void loop() { 
  // Liga o LED
  digitalWrite(ledPin, HIGH);
  delay(1000);  // Aguarda 1 segundo

  // Desliga o LED
  digitalWrite(ledPin, LOW);
  delay(1000);  // Aguarda 1 segundo
}
