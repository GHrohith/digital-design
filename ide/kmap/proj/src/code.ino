#include <Arduino.h>

int pinA = 2, pinB = 3, pinC = 4, pinD = 5;
int pinW = 6, pinX = 7, pinY = 8, pinZ = 9;
int pinClk = 13;

int D,C,B,A;
int Z,Y,X,W;

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
    pinMode(pinY, INPUT);
    pinMode(pinZ, INPUT);
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
        Y = 0;
        Z = 0;
        rst = 0;
    }
    else {
        W = digitalRead(pinW);
        X = digitalRead(pinX);
        Y = digitalRead(pinY);
        Z = digitalRead(pinZ);
    }

    Serial.write(W);
    Serial.write(X);
    Serial.write(Y);
    Serial.write(Z);

    A = (!W && !X && !Y) || (!W && !Z);
    B = (W && !X && !Z) || (!W && X && !Z);
    C = (W && X && !Y && !Z) || (!W && Y && !Z) || (!X && Y && !Z);
    D = (W && X && Y && !Z) || (!W && !X && !Y && Z);
    Serial.write(A);
    Serial.write(B);
    Serial.write(C);
    Serial.write(D);
    disp_7447(D,C,B,A);
}
