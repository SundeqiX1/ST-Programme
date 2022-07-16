#include "exti.h"
#include "delay.h"
#include "led.h"
#include "key.h"
#include "beep.h"

void EXTI4_IRQHandler(void)
{
 delay_ms(10);
if(KEY0==0)
{
LED0=!LED0;
LED1=!LED1;
}
EXTI_ClearITPendingBit(EXTI_Line4);
}


void EXTIX_Init(void)
{
	EXTI_InitTypeDef EXTI_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
  RCC_APB2PeriphResetCmd(RCC_APB2Periph_SYSCFG,ENABLE);
	KEY_Init();
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOE,EXTI_PinSource4);
	
	EXTI_InitStructure.EXTI_Line=EXTI_Line4;
	EXTI_InitStructure.EXTI_LineCmd=ENABLE;
	EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger=EXTI_Trigger_Falling;
	EXTI_Init(&EXTI_InitStructure);
	
	NVIC_InitStructure.NVIC_IRQChannel=EXTI4_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=1;
	NVIC_Init(&NVIC_InitStructure);

}

