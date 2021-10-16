#include "stm32f10x.h"

#ifndef Roger
#define Roger

#define MANUAL 0x111
#define TIM1_CC1 0x000
#define TIM1_CC2 0x001
#define TIM1_CC3 0x010
#define TIM2_CC2 0x011
#define TIM3_TRGO 0x100
#define TIM4_CC4 0x101

char ADCVAL = 0; /* Global variable containing the result of ADC Conversion, initialized at 0  */

	/**
	 * @brief Initializes the ADC on single channel conversion discontinuous mode. \n
	 * The channels are directly connected to Alternate functions of specific GPIOS and must
	 * be chosen accordingly. \n 
	 * Cf. STM32F103RB p. 28 and following for mapping
	 * 
	 * @param ADC ADC1 or ADC2
	 * @param Channel Channel 0..17 to convert from
	 * @param TrigTimer Configuration mode of Timer and Channel to use for an external trigger, use trigger the conversion manually. \n
	 * The CC1..CC4 modes must be enabled on Timer
	 */
	void MyADC_init_single_conv(ADC_TypeDef * ADC, char Channel, char TrigTimer);

	/**
	 * @brief Starts conversion on the ADC \n
	 * ! To use only in MANUAL trigger mode
	 * 
	 * @param ADC ADC1 or ADC2 
	 */
	void MyADC_start_conversion(ADC_TypeDef * ADC);

	/**
	 * @brief Reads the value converted by the ADC
	 * 
	 * @param ADC ADC1 or ADC2
	 * @return Valeur lue par l'ADC
	 */
	char MyADC_read_value(ADC_TypeDef * ADC);
	

#endif
