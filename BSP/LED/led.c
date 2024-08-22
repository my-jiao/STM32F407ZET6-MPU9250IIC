#include "led.h"

void LED_Init(void)
{
    HAL_GPIO_WritePin(GPIOF,GPIO_PIN_15,GPIO_PIN_SET);
}
/**************************************************************************
函数功能：LED闪烁
入口参数：闪烁频率
返回  值：无
**************************************************************************/
void LED_Flash(u32 time)
{
    static u32 last_time,temp=0;
    if(temp==0)last_time=time;          //temp为0时才把当前时间赋给上个时间，防止上个闪烁没执行完时间发生改变导致led灯状态不确定
    if(last_time==0) LED=1;             //时间为0时，设置灯状态为灭
    else if(last_time==1) LED=0;        //时间为1时设置灯状态为亮
    else
    {
        if(++temp==last_time)
        {
            if(LED==0)LED=1;            //其他非0和1的正整数设置灯状态为闪烁，数值100表示1秒时间改变状态
            else LED=0;
            temp=0;
        }
    }

}
