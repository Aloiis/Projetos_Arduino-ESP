#include <BluetoothSerial.h>
#include <HID.h>

BluetoothSerial SerialBT;

const int button_S_Pin = 2;   // Substitua pelos pinos corretos
const int button_N_Pin = 3;   // Substitua pelos pinos corretos
const int button_F2_Pin = 4;  // Substitua pelos pinos corretos
const int button_F4_Pin = 5;  // Substitua pelos pinos corretos

int prevbutton_S_State = HIGH;
int prevbutton_N_State = HIGH;
int prevButton_F2_State = HIGH;
int prevButton_F4_State = HIGH;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32_BT");  // Nome do dispositivo Bluetooth

  pinMode(button_S_Pin, INPUT_PULLUP);  // Configura os pinos como entrada com pull-up interno
  pinMode(button_N_Pin, INPUT_PULLUP);
  pinMode(button_F2_Pin, INPUT_PULLUP);
  pinMode(button_F4_Pin, INPUT_PULLUP);
}

void loop() {
  int button_S_State = digitalRead(button_S_Pin);
  int button_N_State = digitalRead(button_N_Pin);
  int buttonCState = digitalRead(button_F2_Pin);
  int buttonDState = digitalRead(button_F4_Pin);
  
  if (button_S_State != prevbutton_S_State) {
    prevbutton_S_State = button_S_State;
    if (button_S_State == LOW) {
      SerialBT.write('S'); // Envia a letra 'S' via Bluetooth
      delay(1000); // Aguarda um segundo antes de enviar outra tecla
    }
  }

  if (button_N_State != prevbutton_N_State) {
    prevbutton_N_State = button_N_State;
    if (button_N_State == LOW) {
      SerialBT.write('N'); // Envia a letra 'N' via Bluetooth
      delay(1000);
    }
  }

  if (buttonCState != prevButton_F2_State) {
    prevButton_F2_State = buttonCState;
    if (buttonCState == LOW) {
      SerialBT.write(KEY_F2); // Envia a tecla F2 via Bluetooth
      delay(1000);
    }
  }

  if (buttonDState != prevButton_F4_State) {
    prevButton_F4_State = buttonDState;
    if (buttonDState == LOW) {
      SerialBT.write(KEY_F4); // Envia a tecla F4 via Bluetooth
      delay(1000);
    }
  }
}
