#include <Arduino.h>

int pinA = 2, pinB = 3, pinC = 4, pinD = 5;
int pinW = 6, pinX = 7;
int pinClk = 13;

int D=0,C=0,B,A;
int X,W;
int in,out;

int rst;

void disp_7447(int D, int C, int B, int A)
{
    digitalWrite(pinA, A);
    digitalWrite(pinB, B);
    digitalWrite(pinC, C);
    digitalWrite(pinD, D);
}

void setup() {
    pinMode(pinA, OUTPUT);
    pinMode(pinB, OUTPUT);
    pinMode(pinC, OUTPUT);
    pinMode(pinD, OUTPUT);
    pinMode(pinW, INPUT);
    pinMode(pinX, INPUT);
    Serial.begin(9600);

    rst = 1;
}

void loop() {
    digitalWrite(pinClk, LOW);
    delay(500);
    digitalWrite(pinClk, HIGH);
    delay(500);

    if (rst) {
        W = 0;
        X = 0;
        rst = 0;
    }
    else {
        W = digitalRead(pinW);
        X = digitalRead(pinX);
    }

    in=random(0,1);
    Serial.write(in);

    A=(in && !W) || (in && X);
    B=(in &&  W) || (in && X);
    out=(in && X);
    Serial.write(A);
    Serial.write(B);
    Serial.write(out);
    disp_7447(D,C,B,A);
}
