#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);//arduino pins connected to LCD
const int contrastPin = 9;  

int V_out_q=0;

float V_in = 5,V_out;

float R1=330,R2; 

void setup()
{
lcd.begin(16,2);
lcd.setCursor(0,0);
lcd.print("----OHM METER---");
pinMode(contrastPin, OUTPUT);
analogWrite(contrastPin, 122);
Serial.begin(9600);
}

void loop()
{
//V_0ut_q is an integer between 0 to 1023
V_out_q=analogRead(0);//reading from A0

//V_out is the actual voltage at the junction of R1 and R2
V_out = V_in*V_out_q/1024;

R2 = R1/((V_in)/(V_out)-1.0);
Serial.println(R2);
lcd.setCursor(0,1);
lcd.print("R = ");
lcd.print(R2);
lcd.print("Ohm");
delay(3000);
}

