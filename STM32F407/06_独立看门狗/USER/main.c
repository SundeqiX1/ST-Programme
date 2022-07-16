#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "beep.h"
#include "key.h"
#include "iwdg.h"




int main(void)
{ 
 
 	delay_init(168);  //初始化延时函数
	LED_Init();				//初始化LED端口 
	BEEP_Init();      //初始化蜂鸣器端口
	KEY_Init();       //初始化与按键连接的硬件接口
	delay_ms(500);
	LED0=0;				  	//先点亮红灯

  IWDG_Init(4,500);
	while(1)
	{
		if(KEY_Scan(0)==WKUP_PRES)
		{
		IWDG_ReloadCounter();
		}
		delay_ms(10);
	}
	
}
