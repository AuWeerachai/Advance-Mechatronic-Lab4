
/**
  ******************************************************************************
  * @file    main.c 
  * @author  YOU
  * @version 
  * @date    
  * @brief   after the system functions, main is the next function that gets called.
  *             You should modify main and call other functions from here.
  ******************************************************************************
  */
#include <stdint.h>
#include "stm32f446xx_gpio_mort.h"
#include "stm32f446xx_system_mort.h"
#include "stm32f446xx_usart3_mort.h" //always include usart where you want to do communications
#include "nucleo_led.h"




// Simple delay function using software loops, not very good.
// you should implement your own eventually using timers once
// you learn about them.
void delay(volatile int count) {
    while (count--) {
        __asm__("nop");
    }
}


int main (void)
{
    /* Variables*/
    uint32_t number = 0;
    /* Initializations */
    initUSART3(); //always init USART if you want communication!
    init_LED1();
    delay(8000); //give some time for USART to come alive.
    transmitLineUSART3("USART3 is alive!");

    //NOTE 1.2
    init_Reading();
    

    while(1)
    {
    	number = number + 1;
        //USART supports a very simple printf function, check its function declaration for learning what it can do.
        transmitLineUSART3("This board is alive!");
        printfUSART3("This number keeps increasing: %u \n", number);

        //NOTE 1.1
        // delay(800000);
        // toggle_LED1();

        //NOTE 1.2
        turnON_LED_with_reading();
    }
}








