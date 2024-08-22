#include "key.h"


struct keys key[4]= {0,0,0,0}; //�ĸ������ı�����ʼ��

void Key_Scan(void)
{
    //��ȡ�ĸ�������״̬
    key[0].key_sta = HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_8);
    key[1].key_sta = HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_4);
    //key[2].key_sta = HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_2);
    //key[3].key_sta = HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0);

    for(int i = 0; i < 4; i ++) //ɨ�谴�� ÿ0.1��
    {
        switch(key[i].judge_sta)//�ĸ�����
        {
            case 0:
            {
                if(key[i].key_sta == 0)//�������״̬λ�͵�ƽ���п����Ƕ��������Ҳ�п����ǰ��µ�
                {
                    key[i].judge_sta = 1;
                    
                }
            }break;
            
            case 1:
            {
                if(key[i].key_sta == 0)//�������״̬���ǵ͵�ƽ����Ϊ���µ�
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
                if(key[i].key_sta == 1)     //�ɿ���
                {
                    
                    key[i].judge_sta = 0;
                    
                    if(key[i].key_time < 50)
                    {
                        key[i].single_flag = 1;         //����
                        
                    }    
                    else if(key[i].key_time >= 50)
                    {
                        key[i].long_flag = 1;       //����
                        
                        
                    }
                }
                else if(key[i].key_sta == 0) //���ڰ�
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
    uint8_t KeyNum = 0;//���������Ĭ�ϼ���ֵΪ0
    //==============����=============//
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
    //==============����=============//
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
