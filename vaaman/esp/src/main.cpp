#include <Arduino.h>

void setup() {
  pinMode(2, OUTPUT);
  pinMode(4, INPUT);
  pinMode(6, INPUT);
}

bool mux(bool in0, bool in1, bool in2, bool in3, bool sel0, bool sel1) {
  return sel1? (sel0? in3: in2): (sel0? in1: in0);
}

bool X, Y, out;

void loop() {
  X = digitalRead(4);
  Y = digitalRead(6);

  out = mux (1, 1, 1, 0, Y, X);

  digitalWrite(2, out);

  delay(500);
}