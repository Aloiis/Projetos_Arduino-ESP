#include <WiFi.h>
#include <Keyboard.h>

const char* ssid = "WiFi_PradoLux";  // SSID da sua rede Wi-Fi
const char* password = "pr0701lux";  // Senha da sua rede Wi-Fi

void setup() {
  Serial.begin(115200);
  delay(2000);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi");
  Keyboard.begin();
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    Keyboard.print("S");  // Substitua pela mensagem que deseja enviar
    Keyboard.write(KEY_RETURN);  // Envio de um pressionamento de tecla "Enter" após a mensagem
    delay(5000);  // Intervalo entre mensagens (5 segundos neste exemplo)
  }
}
