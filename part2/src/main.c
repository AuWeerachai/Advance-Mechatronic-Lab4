// Part 2: all seven LEDs use NPN drivers, HIGH = ON and LOW = OFF.
// Detection: D2/PF15 red, D3/PE13 green, D4/PF14 orange, D5/PE11 white.
// Illumination: D6/PE9 red, D7/PF13 green, D9/PD15 blue.
#include "stm32f446xx_gpio_mort.h"
#include "stm32f446xx_timer_mort.h"

// Wait for one complete timer period.
void waitTimer3(void)
{
    restartTimer3();
    while(checkTimer3Overflow() == 0)
    {
    }
}

int main(void)
{
    initGpioPE13AsOutput();
    initGpioPE11AsOutput();
    initGpioPE9AsOutput();
    initGpioPF15AsOutput();
    initGpioPF14AsOutput();
    initGpioPF13AsOutput();
    initGpioPD15AsOutput();

    // Start with all LEDs OFF.
    writeGPIOPE13(0);
    writeGPIOPE11(0);
    writeGPIOPE9(0);
    writeGPIOPF15(0);
    writeGPIOPF14(0);
    writeGPIOPF13(0);
    writeGPIOPD15(0);
    initTimer3();

    while(1)
    {
        // D2 / PF15: red detection ON, then OFF.
        writeGPIOPF15(1);
        waitTimer3();
        writeGPIOPF15(0);
        waitTimer3();

        // D3 / PE13: green detection ON, then OFF.
        writeGPIOPE13(1);
        waitTimer3();
        writeGPIOPE13(0);
        waitTimer3();

        // D4 / PF14: orange detection ON, then OFF.
        writeGPIOPF14(1);
        waitTimer3();
        writeGPIOPF14(0);
        waitTimer3();

        // D5 / PE11: white detection ON, then OFF.
        writeGPIOPE11(1);
        waitTimer3();
        writeGPIOPE11(0);
        waitTimer3();

        // D6 / PE9: red illumination ON, then OFF.
        writeGPIOPE9(1);
        waitTimer3();
        writeGPIOPE9(0);
        waitTimer3();

        // D7 / PF13: green illumination ON, then OFF.
        writeGPIOPF13(1);
        waitTimer3();
        writeGPIOPF13(0);
        waitTimer3();

        // D9 / PD15: blue illumination ON, then OFF.
        writeGPIOPD15(1);
        waitTimer3();
        writeGPIOPD15(0);
        waitTimer3();

    }
}
