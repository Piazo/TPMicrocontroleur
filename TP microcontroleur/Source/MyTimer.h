#ifndef Raymond
#define Raymond

#include "stm32f10x.h"


void MyTimer_Base_Init ( TIM_TypeDef * Timer, unsigned short ARRarg, unsigned short PSCarg );

void MyTimer_Base_Start (TIM_TypeDef * Timer);
void MyTimer_Base_Stop (TIM_TypeDef * Timer);

#endif

