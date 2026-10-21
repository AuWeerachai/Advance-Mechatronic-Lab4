/**
  ******************************************************************************
  * @file    nucleo_led.c 
  * @author  
  * @version 
  * @date    
  * @brief   Controls the LED's on the nucleo board
  ******************************************************************************
  */
  
#include "stm32f446xx_gpio_mort.h"
#include "nucleo_led.h"

/************************************
* Initializes LED1 on the nucleo Board which is connected to Port B Pin 0
*************************************/
void init_LED1(void )
{
    //Fill with gpio function to call to initialize LED1
    initGpioB0AsOutput();
    

}
/************************************
* Toggles LED1 
*************************************/
void toggle_LED1( void )
{
    //Fill with gpio function to call to toggle LED1
    toggleGPIOB0();

}

//NOTE 1.1 Just add some functions here
void turnOn_LED1(void)
{
    setGPIOB0();
}

/* Turn LED1 off. */
void turnOff_LED1(void)
{
    clearGPIOB0();
}

//NOTE 1.2 add checking PC6
void init_Reading(void){
    initGpioC6AsInput();
}



void turnON_LED_with_reading(void) {
    if(checkGPIOC6() == 1){
        turnOn_LED1();
    }
    else{
        turnOff_LED1();
    }
}