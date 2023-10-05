// You need this to use the Module Support Board
#include "uop_msb.h"
using namespace uop_msb;

#define WAIT_TIME_MS 1000 

DigitalOut greenLED(TRAF_GRN1_PIN);
Buzzer buzz;
Buttons buttons;

// TIP: (I suggest you read this!)
//
// Press the black reset button to restart the code (and stop the sound)
// Otherwise, the noise can be "distracting" :)

int main()
{
    //Wait for the BLUE button to be pressed (otherwise this becomes super annoying!)
    while (buttons.BlueButton == 0);
    
    //Repeat everything "forever" (until the power is removed or the chip is reset)
    while (true)
    {
        //On for 250ms each note in scale with light remaining on.
        greenLED = 1;
        buzz.playTone("C");
        wait_us(WAIT_TIME_MS * 250);  //250ms
        buzz.playTone("D");
        wait_us(WAIT_TIME_MS * 250);  //250ms
        buzz.playTone("E");
        wait_us(WAIT_TIME_MS * 250);  //250ms
        buzz.playTone("F");
        wait_us(WAIT_TIME_MS * 250);  //250ms
        buzz.playTone("G");
        wait_us(WAIT_TIME_MS * 250);  //250ms
        buzz.playTone("A", Buzzer::HIGHER_OCTAVE);
        wait_us(WAIT_TIME_MS * 250);  //250ms
        buzz.playTone("B", Buzzer::HIGHER_OCTAVE);
        wait_us(WAIT_TIME_MS * 250);  //250ms
        buzz.playTone("C", Buzzer::HIGHER_OCTAVE);
        wait_us(WAIT_TIME_MS * 250);  //250ms

        //Off for 250ms
        greenLED = 0;
        
        //Pause
        buzz.rest();
        wait_us(WAIT_TIME_MS * 1000);

    }
}