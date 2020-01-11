#include <Arduino.h>

void setup() {
  SerialUSB.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
}

void loop() {
  auto input = SerialUSB.readStringUntil('\n');
  input.trim();
  if(input.length() <= 0) return;
  
  if(input == "help") SerialUSB.println("Enter `1` to enable LED or `0` to disable it.");
  if(input == "1") digitalWrite(LED_BUILTIN, LOW);
  if(input == "0") digitalWrite(LED_BUILTIN, HIGH);
}