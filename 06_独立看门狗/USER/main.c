#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "beep.h"
#include "key.h"
#include "iwdg.h"




int main(void)
{ 
 
 	delay_init(168);  //��ʼ����ʱ����
	LED_Init();				//��ʼ��LED�˿� 
	BEEP_Init();      //��ʼ���������˿�
	KEY_Init();       //��ʼ���밴�����ӵ�Ӳ���ӿ�
	delay_ms(500);
	LED0=0;				  	//�ȵ������

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
