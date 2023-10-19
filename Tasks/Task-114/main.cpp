#include "mbed.h"

DigitalOut redLED(PC_2,1); //LEDs are on/high at start (1)
DigitalOut greenLED(PC_6,1);
DigitalOut yellowLED(PC_3,1);

// main() runs in its own thread in the OS
int main()
{
    //All LEDs are high/on as a power-on test
    wait_us(2000000);
    
    //Reset - Off all LEDs
    redLED = 0;
    greenLED = 0;
    yellowLED = 0;

    while (true) {
        //Red
        redLED = 1;
        wait_us(2000000);
        //Red & Yellow
        yellowLED = 1;
        wait_us(2000000);
        //Red & Yellow off
        redLED = 0;
        yellowLED = 0;
        //Green
        greenLED = 1;
        wait_us(2000000);
        //Green off
        greenLED = 0;
        
        //Flashing Yellow
        int count =0;
        while (count < 8){
            yellowLED = !yellowLED;
            wait_us(200000);                       
            count = count +1;
            }
        









    }
}

