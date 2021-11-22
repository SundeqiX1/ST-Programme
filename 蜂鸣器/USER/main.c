#include "stm32f4xx.h"
#include "led.h"
#include "delay.h"
#include "usart.h"
#include "beep.h"

int main(void)
{
	delay_init(168);
	LED_Init();
	BEEP_Init();
	while(1)
	{
	GPIO_SetBits(GPIOF,GPIO_Pin_9|GPIO_Pin_10);
		//GPIO_SetBits(GPIOF,GPIO_Pin_8);
		BEEP=0;
		delay_ms(500);
			GPIO_ResetBits(GPIOF,GPIO_Pin_9|GPIO_Pin_10);
		//GPIO_ResetBits(GPIOF,GPIO_Pin_8);
		BEEP=1;
		delay_ms(500);
	}
}


