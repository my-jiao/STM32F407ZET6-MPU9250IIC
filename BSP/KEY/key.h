#ifndef __KEY_H
#define __KEY_H

#include "main.h"
#include "stdbool.h"
void Key_Scan(void);
uint8_t Key_GetNum(void);

extern uint8_t KeyNum;

struct keys
{
    uint8_t judge_sta;  //�����Ĳ���
    bool key_sta;       //������״̬
    bool single_flag;   //���µ�����  ����
    bool long_flag;     //���µ�����  ����
    uint8_t key_time;   //���µ�ʱ��

};

extern struct keys key[];

#endif
