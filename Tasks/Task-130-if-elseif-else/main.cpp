#include "uop_msb.h"
using namespace uop_msb;

BusIn bus(PG_0, PG_1, PG_2, PG_3);

DigitalOut redLED(TRAF_RED1_PIN);       //Red Traffic 1
DigitalOut yellowLED(TRAF_YEL1_PIN);    //Yellow Traffic 1
DigitalOut greenLED(TRAF_GRN1_PIN);     //Green Traffic 1

//Dual Digit 7-segment Display
LatchedLED disp(LatchedLED::SEVEN_SEG);

int main()
{
    int count = 0;

    //Turn ON the 7-segment display
    disp.enable(true);

    //Update display
    disp = count;

    while (true) {
             
        //Test Button A
        if (bus[0] == 1) {
            redLED = !redLED;    //Toggle RED led
            count = count + ((count<99 ? 1 : 0));   //Increment count, less than 99.
            disp = count;       //Update display
            wait_us(100000);  
        }
        //Test Button B
        else if (bus[1] == 1) {
            yellowLED = !yellowLED;    //Toggle yellow led
            count = count - ((count>0 ? 1 : 0));      //Increment count, more than 0
            disp = count;       //Update display
            wait_us(100000);  
        }
        //Both buttons pressed, reset counter
        if ((bus[0] == 1) && (bus[1] == 1)) {
            count = 0;
            disp = count;
            wait_us(100000); 
        }

        //When neither buttons are pressed, toggle green LED.
        else {
            greenLED = !greenLED; 
            
        }
        // Slow it down a bit (and debounce the switches)
        wait_us(100000);  
    }
}


