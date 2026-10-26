// Part 2: named controls for the seven external LEDs.
#include "nucleo_led.h"
#include "stm32f446xx_gpio_mort.h"

// Configure the LED pins and start with all LEDs OFF.
void initLEDs(void)
{
    initGpioPF15AsOutput();
    initGpioPE13AsOutput();
    initGpioPF14AsOutput();
    initGpioPE11AsOutput();
    initGpioPE9AsOutput();
    initGpioPF13AsOutput();
    initGpioPD15AsOutput();

    writeRedDetection(0);
    writeGreenDetection(0);
    writeOrangeDetection(0);
    writeWhiteDetection(0);
    writeRedIllumination(0);
    writeGreenIllumination(0);
    writeBlueIllumination(0);
}

// All drivers are NPN: 1 = ON, 0 = OFF.
// D2 / PF15.
void writeRedDetection(uint32_t value)
{
    writeGPIOPF15(value);
}

// D3 / PE13.
void writeGreenDetection(uint32_t value)
{
    writeGPIOPE13(value);
}

// D4 / PF14.
void writeOrangeDetection(uint32_t value)
{
    writeGPIOPF14(value);
}

// D5 / PE11.
void writeWhiteDetection(uint32_t value)
{
    writeGPIOPE11(value);
}

// D6 / PE9.
void writeRedIllumination(uint32_t value)
{
    writeGPIOPE9(value);
}

// D7 / PF13.
void writeGreenIllumination(uint32_t value)
{
    writeGPIOPF13(value);
}

// D9 / PD15.
void writeBlueIllumination(uint32_t value)
{
    writeGPIOPD15(value);
}

