#include "stm32f10x.h"

#ifndef Raymond
#define Raymond

void MyTimer_Base_Init ( TIM_TypeDef * Timer, unsigned short ARRarg, unsigned short PSCarg );

void MyTimer_Base_Start (TIM_TypeDef * Timer);
void MyTimer_Base_Stop (TIM_TypeDef * Timer);

/**
	* @brief
	* @param Timer Timer1..4 to be configured
	* @param Channel Channel spécifié à activer
	*	@Note Active le chanel spécifié sur Timer
	* Ne configure pas l'I/O ni ne règle la période de la PWM
	*/
void MyTimer_PWM(TIM_TypeDef * Timer, char Channel);

void MyTimer_PWM_StartPWM(TIM_TypeDef * Timer, char Channel, unsigned short Arr, unsigned short Psc );

void MyTimer_PWM_SetCyclicDuty(TIM_TypeDef * Timer, char Channel);


#endif

#ifndef Didier
#define Didier

void MyTimer_ActiveIT (TIM_TypeDef * Timer, char Prio, void (*IT_function) (void));

#endif
