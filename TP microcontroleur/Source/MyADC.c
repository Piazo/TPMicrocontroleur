#include "MyADC.h"

#include "stm32f10x.h"

void MyADC_init_single_conv(ADC_TypeDef* ADC, char Channel, char TrigTimer) {
    // Enables the Clock corresponding to chosen ADC
    if (ADC == ADC1) RCC->APB2ENR |= (1 << 9);
    if (ADC == ADC2) RCC->APB2ENR |= (1 << 10);

    ADC->CR2 |= (1 << 0);    // Sets the ADON bit => power on the ADC
    ADC->CR2 &= ~(1 << 11);  // Force resets the ALIGN bit => right data alignment

    ADC->SQR1 &= ~(1 << 20);  // Forces the reset of L[3;0] bits => 1 conversion realized par ADC
    ADC->CR1 |= (1 << 5);  // Enables the interruption for EOC
    NVIC->ISER[0] |= (1<<18);       // Enables the interrupt for ADC1 and ADC2 in NVIC

    /* 
		Configures the ADC's 1st conversion for the chosen Channel
		The temperature sensor is connected to Chan 16
		The internal ref voltage is connected to Chan 17
	 */
    ADC->SQR1 |= (Channel << 0);

    if (TrigTimer != MANUAL) {
        ADC->CR2 |= (1 << 20);  // Sets the exter trig conversion mode
        ADC->CR2 |= (TrigTimer << 17);
    }
}


void MyADC_start_conversion(ADC_TypeDef* ADC) {
    ADC->CR2 |= (1 << 0);  // Sets the ADON bit again => starts conversion
}

char MyADC_read_value(ADC_TypeDef* ADC) {
    return ADCVAL;
}

/**
 * TODO Check how to use both ADCs
 * ! Current version is not modular
 */
void ADC1_2_IRQHandler() {
    ADCVAL = ADC1->DR;
}


