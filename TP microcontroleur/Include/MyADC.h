#include "stm32f10x.h"

#ifndef Roger
#define Roger

	/**
	 * @brief Initializes the ADC on single channel conversion discontinuous mode. \n
	 * The channels are directly connected to Alternate functions of specific GPIOS and must
	 * be chosen accordingly. \n 
	 * Cf. STM32F103RB p. 28 and following for mapping
	 * 
	 * @param ADC ADC1 or ADC2
	 * @param Channel Channel 0..17 to convert from
	 * @param Timer Timer to use for an external trigger, use null to setup with a software trigger
	 */
	void MyADC_init_single_conv(ADC_TypeDef * ADC, char Channel, TIM_TypeDef * Timer);



	
	

#endif
