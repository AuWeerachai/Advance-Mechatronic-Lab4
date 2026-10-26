// Part 2: all seven LEDs use NPN drivers, HIGH = ON and LOW = OFF.
// Detection: D2/PF15 red, D3/PE13 green, D4/PF14 orange, D5/PE11 white.
// Illumination: D6/PE9 red, D7/PF13 green, D9/PD15 blue.
#include "nucleo_led.h"
#include "stm32f446xx_timer_mort.h"

// Wait for one complete timer period.
void delay(void)
{
    restartTimer3();
    while(checkTimer3Overflow() == 0)
    {
    }
}

int main(void)
{
    initLEDs();
    initTimer3();

    while(1)
    {
        // D2 / PF15: red detection ON, then OFF.
        writeRedDetection(1);
        delay();
        writeRedDetection(0);
        delay();

        // D3 / PE13: green detection ON, then OFF.
        writeGreenDetection(1);
        delay();
        writeGreenDetection(0);
        delay();

        // D4 / PF14: orange detection ON, then OFF.
        writeOrangeDetection(1);
        delay();
        writeOrangeDetection(0);
        delay();

        // D5 / PE11: white detection ON, then OFF.
        writeWhiteDetection(1);
        delay();
        writeWhiteDetection(0);
        delay();

        // D6 / PE9: red illumination ON, then OFF.
        writeRedIllumination(1);
        delay();
        writeRedIllumination(0);
        delay();

        // D7 / PF13: green illumination ON, then OFF.
        writeGreenIllumination(1);
        delay();
        writeGreenIllumination(0);
        delay();

        // D9 / PD15: blue illumination ON, then OFF.
        writeBlueIllumination(1);
        delay();
        writeBlueIllumination(0);
        delay();

    }
}
