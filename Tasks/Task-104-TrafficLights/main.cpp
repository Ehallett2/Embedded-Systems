#include "uop_msb.h"
#include <algorithm>
#include <type_traits>
using namespace uop_msb;

#define WAIT_TIME_MS 500 

DigitalOut red(TRAF_RED1_PIN,0);         //Note the initial state
DigitalOut amber(TRAF_YEL1_PIN,0);
DigitalOut green(TRAF_GRN1_PIN,0);

//Object for controlling the LCD
LCD_16X2_DISPLAY lcd;

int main()
{
    while (true)
    {   
        red = 1;
        lcd.cls();
        lcd.puts("RED");
        wait_us(10000000);

        amber = 1;
        lcd.cls();
        lcd.puts("RED + AMBER");
        wait_us(2000000);
        red = 0;
        amber = 0;

        green = 1;
        lcd.cls();
        lcd.puts("GREEN");    
        wait_us(10000000);
        green = 0;

        lcd.cls();
        lcd.puts("FLASH AMBER");
        int count = 0;
        while (count < 8)
        {
            amber = !amber;
            wait_us(500000);
            count = count + 1;
        }
        
        lcd.cls();
        lcd.puts("TASK-104");
        wait_us(500000);
        
        /*while (true)
        {
            red = !red;
            amber = !amber;
            green = !green;
            wait_us(WAIT_TIME_MS * 1000);
        }*/
    }
}
