void disp_7447(int D, int C, int B, int A)
{
  digitalWrite(2, A); //LSB
  digitalWrite(3, B); 
  digitalWrite(4, C); 
  digitalWrite(5, D); //MSB

}
// the setup function runs once when you press reset or power the board
void setup() {
    pinMode(2, OUTPUT);  
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
}

void int_write(int in)
{
    disp_7447((in & 8) >> 3, (in & 4) >> 2, (in & 2) >> 1, (in & 1) );
}

int count = 0;
void loop() {
    int_write(count);
    count = (count>=9 || count<0) ? 0 : count + 1;

    delay(1000);
}
