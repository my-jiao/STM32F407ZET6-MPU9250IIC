#ifndef __LED_H
#define __LED_H

#include "main.h"
#include "sys.h"

#define LED_ON()     HAL_GPIO_WritePin(GPIOF,GPIO_PIN_15,GPIO_PIN_RESET)
#define LED_OFF()    HAL_GPIO_WritePin(GPIOF,GPIO_PIN_15,GPIO_PIN_SET)
#define LED_TOGG()   HAL_GPIO_TogglePin(GPIOF,GPIO_PIN_15)

#define LED PFout(15)           // DS0

void LED_Init(void);
void LED_Flash(u32 time);
#endif
