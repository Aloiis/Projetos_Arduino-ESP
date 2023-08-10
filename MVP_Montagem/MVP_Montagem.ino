#include <Keyboard.h>

const int cano1 = 2;   // Pino ao qual o LED 2 será conectado
const int cano2 = 3;   // Pino ao qual o LED 3 será conectado
const int cano3 = 4;   // Pino ao qual o LED 4 será conectado
const int cano4 = 5;   // Pino ao qual o LED 4 será conectado
const int buttonPin12 = 12;  // Pino ao qual o botão S será conectado
const int buttonPin13 = 13;  // Pino ao qual o botão N será conectado
const int buttonPin11 = 11;  // Pino ao qual o botão F2 será conectado
const int buttonPin10 = 10;  // Pino ao qual o botão F4 será conectado

void setup() {
  Serial.begin(9600);
  pinMode(cano1, OUTPUT);
  pinMode(cano2, OUTPUT);
  pinMode(cano3, OUTPUT);
  pinMode(cano4, OUTPUT);
  pinMode(buttonPin13, INPUT_PULLUP);
  pinMode(buttonPin12, INPUT_PULLUP);
  pinMode(buttonPin11, INPUT_PULLUP);
  pinMode(buttonPin10, INPUT_PULLUP);
  Keyboard.begin();
}

void loop() {
  if (Serial.available()) {
    String input = Serial.readStringUntil('\n');
    input.trim();

    if (input == "L002-2C") {
      digitalWrite(cano1, HIGH);
    } else {
      digitalWrite(cano1, LOW);
    }

    if (input == "L002-2B") {
      digitalWrite(cano2, HIGH);
    } else {
      digitalWrite(cano2, LOW);
    }

    // Se houver mais condições para os outros canos, você pode adicioná-las aqui

    // Exemplo:
    // if (input == "L002-2B") {
    //   digitalWrite(cano3, HIGH);
    // } else {
    //   digitalWrite(cano3, LOW);
    // }

    // if (input == "L002-2B") {
    //   digitalWrite(cano4, HIGH);
    // } else {
    //   digitalWrite(cano4, LOW);
    // }
  }

  if (digitalRead(buttonPin12) == LOW) {
    Keyboard.press('S');
    delay(100);
    Keyboard.release('S');
    delay(100);
  }

  if (digitalRead(buttonPin13) == LOW) {
    Keyboard.press('N');
    delay(100);
    Keyboard.release('N');
    delay(100);
  }

  if (digitalRead(buttonPin11) == LOW) {
    Keyboard.press(KEY_F2);
    delay(100);
    Keyboard.release(KEY_F2);
    delay(100);
  }

  if (digitalRead(buttonPin10) == LOW) {
    Keyboard.press(KEY_F4);
    delay(100);
    Keyboard.release(KEY_F4);
    delay(100);
  }
}
