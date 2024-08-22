#ifndef __KEY_H
#define __KEY_H

#include "main.h"
#include "stdbool.h"
void Key_Scan(void);
uint8_t Key_GetNum(void);

extern uint8_t KeyNum;

struct keys
{
    uint8_t judge_sta;  //按键的步骤
    bool key_sta;       //按键的状态
    bool single_flag;   //按下的类型  单击
    bool long_flag;     //按下的类型  长按
    uint8_t key_time;   //按下的时间

};

extern struct keys key[];

#endif
