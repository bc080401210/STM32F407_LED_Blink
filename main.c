
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_gpio.h"

#define LED_PORT  GPIOD
#define LED4 	  GPIO_Pin_12
#define LED5 	  GPIO_Pin_14

void LED_Init(void)
{
	GPIO_InitTypeDef GPIO_LED;

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);

	GPIO_LED.GPIO_Pin = LED4 | LED5;
	GPIO_LED.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_LED.GPIO_OType = GPIO_OType_PP;
	GPIO_LED.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_LED.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(LED_PORT, &GPIO_LED);
}

void Delay(__IO uint32_t nCount)
{
	__IO uint32_t i;

	while(nCount--)
	{
		i = 1000;
		while(i--);
	}
}

int main(void)
{
    LED_Init();

    while(1)
    {
    	 GPIO_ResetBits(LED_PORT, LED5);
    	 GPIO_SetBits(LED_PORT, LED4);
    	 Delay(1000);

    	 GPIO_SetBits(LED_PORT, LED5);
    	 GPIO_ResetBits(LED_PORT, LED4);
    	 Delay(1000);
    }
}


