#include "stm32f10x.h"
#include "MyADC.h"

void MyADC_init_single_conv(ADC_TypeDef *ADC, char Channel, TIM_TypeDef* Timer){
	// Enables the Clock corresponding to chosen ADC
	if (ADC==ADC1) RCC->APB2ENR |= (1<<9);
	if (ADC==ADC2) RCC->APB2ENR |= (1<<10);
	
	ADC->CR2 |= (1<<0); // Sets the ADON bit => power on the ADC
	// ADC->CR1 |= (1<<5); // Enables the interrupt interruption for EOC
	ADC->CR2 &= ~(1<<11); // Force resets the ALIGN bit => right data alignment

	ADC->SQR1 &= ~(1<<20); // Forces the reset of L[3;0] bits => 1 conversion realized par ADC

	/* 
		Configures the ADC's 1st conversion for the chosen Channel
		The temperature sensor is connected to Chan 16
		The internal ref voltage is connected to Chan 17
	 */
	ADC->SQR1 |= (Channel<<0);

}


