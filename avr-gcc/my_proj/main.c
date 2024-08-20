#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>

int main (void) {
    bool F;
    bool p=0,q=0,r=0,s=0;

    DDRD = 0b01000000;
    PORTD = 0b00000000;
    
    while(1){
        _delay_ms (200L);

        s = (PIND & (1 << 5)) == (1 << 5);
        r = (PIND & (1 << 4)) == (1 << 4);
        q = (PIND & (1 << 3)) == (1 << 3);
        p = (PIND & (1 << 2)) == (1 << 2);

        F= (!p & !q) | (!p & q & s) | (p & !q & !r & !s) | (p & !q & r & !s);
        
        PORTD = (F << 6);

        _delay_ms (200L);
    }

    return 0;

}