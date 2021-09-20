#include "stm32f10x.h"


void MyTimer_Base_Init ( TIM_TypeDef * Timer, unsigned short ARRarg, unsigned short PSCarg ){
	if (Timer==TIM1) RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;
	if (Timer==TIM2) RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	if (Timer==TIM3) RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
	if (Timer==TIM4) RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;

	Timer->ARR = ARRarg;
	Timer->PSC = PSCarg;
}
	void MyTimer_Base_Start (TIM_TypeDef * Timer){
		(Timer->CR1 |= 1<<0);
	}
	void MyTimer_Base_Stop (TIM_TypeDef * Timer){
		(Timer->CR1 |= 0<<0);
	}