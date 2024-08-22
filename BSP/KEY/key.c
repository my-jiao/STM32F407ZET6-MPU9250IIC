#include "key.h"


struct keys key[4]= {0,0,0,0}; //四个按键的变量初始化

void Key_Scan(void)
{
    //读取四个按键的状态
    key[0].key_sta = HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_8);
    key[1].key_sta = HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_4);
    //key[2].key_sta = HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_2);
    //key[3].key_sta = HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0);

    for(int i = 0; i < 4; i ++) //扫描按键 每0.1秒
    {
        switch(key[i].judge_sta)//四个步骤
        {
            case 0:
            {
                if(key[i].key_sta == 0)//如果按键状态位低电平，有可能是抖动引起的也有可能是按下的
                {
                    key[i].judge_sta = 1;
                    
                }
            }break;
            
            case 1:
            {
                if(key[i].key_sta == 0)//如果按键状态还是低电平，则为按下的
                {
                    key[i].judge_sta = 2;
                    key[i].key_time = 0;
                }
                else
                {
                    key[i].judge_sta = 0;
                }
            }break;
            
            case 2:
            {
                if(key[i].key_sta == 1)     //松开了
                {
                    
                    key[i].judge_sta = 0;
                    
                    if(key[i].key_time < 50)
                    {
                        key[i].single_flag = 1;         //单击
                        
                    }    
                    else if(key[i].key_time >= 50)
                    {
                        key[i].long_flag = 1;       //长按
                        
                        
                    }
                }
                else if(key[i].key_sta == 0) //还在按
                {
                    key[i].key_time ++;

                }
                
            }break;
            
        }
    }
}



uint8_t KeyNum;
uint8_t Key_GetNum(void)
{
    uint8_t KeyNum = 0;//定义变量，默认键码值为0
    //==============单击=============//
    if(key[0].single_flag == 1)
    {
        KeyNum = 1;
        key[0].single_flag = 0;

    }
    else if(key[1].single_flag == 1)
    {
        KeyNum = 2;
        key[1].single_flag = 0;

    }
    else if(key[2].single_flag == 1)
    {
        KeyNum = 3;
        key[2].single_flag = 0;

    }
    else if(key[3].single_flag == 1)
    {
        KeyNum = 4;
        key[3].single_flag = 0;
    }
    //==============长按=============//
    else if(key[0].long_flag == 1)
    {
        KeyNum = 10;
        key[0].long_flag = 0;
    }
    else if(key[1].long_flag == 1)
    {
        KeyNum = 20;
        key[1].long_flag = 0;
    }
    else if(key[2].long_flag == 1)
    {
        KeyNum = 30;
        key[2].long_flag = 0;
    }
    else if(key[3].long_flag == 1)
    {
        KeyNum = 40;
        key[3].long_flag = 0;
    }

    return KeyNum;
}
