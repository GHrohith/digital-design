#include "Arduino.h"

void sevenseg(int a,int b,int c,int d,int e,int f,int g)
{
  digitalWrite(2, a); 
  digitalWrite(3, b); 
  digitalWrite(4, c); 
  digitalWrite(5, d); 
  digitalWrite(6, e); 
  digitalWrite(7, f);     
  digitalWrite(8, g); 
}

void writeDig(int dig)
{
    switch(dig % 10){
    case 0:
        sevenseg(0, 0, 0, 0, 0, 0, 1);
        break;
    case 1:
        sevenseg(1, 0, 0, 1, 1, 1, 1);
        break;
    case 2:
        sevenseg(0, 0, 1, 0, 0, 1, 0);
        break;
    case 3:
        sevenseg(0, 0, 0, 0, 1, 1, 0);
        break;
    case 4:
        sevenseg(1, 0, 0, 1, 1, 0, 0);
        break;
    case 5:
        sevenseg(0, 1, 0, 0, 1, 0, 0);
        break;
    case 6:
        sevenseg(0, 1, 0, 0, 0, 0, 0);
        break;
    case 7:
        sevenseg(0, 0, 0, 1, 1, 1, 1);
        break;
    case 8:
        sevenseg(0, 0, 0, 0, 0, 0, 0);
        break;
    case 9:
        sevenseg(0, 0, 0, 1, 1, 0, 0);
        break;
    default:
        sevenseg(1, 1, 1, 1, 1, 1, 1);
        break;
    }
}

void setup() 
{
    pinMode(2, OUTPUT);  
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
    pinMode(8, OUTPUT);
    Serial.begin(9600);
}

int count = 0;
void loop() 
{
//sevenseg(1,0,0,1,1,1,1);  

    writeDig(count);
    count = (count>=9 || count<0) ? 0 : count + 1;

    delay(1000);
}
