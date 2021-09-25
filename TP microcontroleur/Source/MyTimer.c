#include "stm32f10x.h"
#include "MyTimer.h"

void (* pFunc) (void);

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
		Timer->CR1 &= ~(1<<0);
	}
	
void MyTimer_ActiveIT (TIM_TypeDef * Timer, char Prio, void (*IT_function) (void)){
	Timer -> DIER |= 1<<0; //activation de l'interruption du timer
	if (Timer==TIM1){ NVIC -> ISER[0] |= 1<<25; NVIC -> IP[25] = Prio<<4;} //On autorise les interruption du timer x et on gere la prio
	if (Timer==TIM2){ NVIC -> ISER[0] |= 1<<28; NVIC -> IP[28] = Prio<<4;}
	if (Timer==TIM3){ NVIC -> ISER[0] |= 1<<29; NVIC -> IP[29] = Prio<<4;}
	if (Timer==TIM4){ NVIC -> ISER[0] |= 1<<30; NVIC -> IP[30] = Prio<<4;}
	
	pFunc = IT_function;
}

void TIM1_UP_IRQHandler(void){
	if (pFunc != 0) (*pFunc)();
	TIM1 -> SR &= ~(1<<0); //On reset le bit d'update d'interruption a zero	 
 }

void TIM2_IRQHandler(void){
	if (pFunc != 0) (*pFunc)();
	TIM2 -> SR &= ~(1<<0);
 }
 
void TIM3_IRQHandler(void){
	if (pFunc != 0) (*pFunc)();
	TIM3 -> SR &= ~(1<<0);
}
	
void TIM4_IRQHandler(void){
	if (pFunc != 0) (*pFunc)();
	TIM4 -> SR &= ~(1<<0);
}
 