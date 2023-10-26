#include "mbed.h"

// DigitalOut redLED(PC_2,0);
// DigitalOut yellowLED(PC_3,0);
// DigitalOut greenLED(PC_6,0);
BusOut leds(PC_2, PC_3, PC_6);

// main() runs in its own thread in the OS
int main()
{
    int pattern, count, delay;

    do {
        //Pattern Value 
         printf("\n\nEnter a 'pattern' integer between 0 and 7\n\n");
         scanf("%d", &pattern);

         //Count Value
          printf("\n\nEnter a 'count' integer between 5 and 20\n\n");
          scanf("%d", &count);

          //Delay Value
          printf("\n\nEnter a 'delay' integer between 50 and 2000\n\n");
          scanf("%d", &delay);

          //While conditions
     } while((pattern >=0) || (pattern <=7) || (count >=5) || (count<=20) || (delay >=50) || (delay <=2000));
             
    

    while (true) {

        //For-Loop
            for (int n=1; n<=count; n = n+1) {
                printf("n=%d\n", n);
                leds = pattern;
                wait_us(delay);
        }

        //2s pause
        wait_us(2000000);
    }
}

