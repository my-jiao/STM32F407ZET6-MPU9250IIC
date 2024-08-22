#include "led.h"

void LED_Init(void)
{
    HAL_GPIO_WritePin(GPIOF,GPIO_PIN_15,GPIO_PIN_SET);
}
/**************************************************************************
�������ܣ�LED��˸
��ڲ�������˸Ƶ��
����  ֵ����
**************************************************************************/
void LED_Flash(u32 time)
{
    static u32 last_time,temp=0;
    if(temp==0)last_time=time;          //tempΪ0ʱ�Űѵ�ǰʱ�丳���ϸ�ʱ�䣬��ֹ�ϸ���˸ûִ����ʱ�䷢���ı䵼��led��״̬��ȷ��
    if(last_time==0) LED=1;             //ʱ��Ϊ0ʱ�����õ�״̬Ϊ��
    else if(last_time==1) LED=0;        //ʱ��Ϊ1ʱ���õ�״̬Ϊ��
    else
    {
        if(++temp==last_time)
        {
            if(LED==0)LED=1;            //������0��1�����������õ�״̬Ϊ��˸����ֵ100��ʾ1��ʱ��ı�״̬
            else LED=0;
            temp=0;
        }
    }

}
