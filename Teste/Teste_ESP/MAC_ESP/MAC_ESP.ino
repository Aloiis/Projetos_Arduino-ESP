#include <WiFi.h>

void setup() {
  Serial.begin(115200);
  
  uint8_t mac[6];
  WiFi.macAddress(mac);
  
  Serial.print("MAC Address: ");
  for (int i = 0; i < 6; i++) {
    Serial.print(mac[i], HEX);
    if (i < 5) Serial.print(':');
  }
  
  Serial.println();
}

void loop() {
  // Seu código aqui
}
