#include "stm32f10x.h"
#include "MyTimer.h"

int main(void){
	//C->APB2ENR |= (0x01 << 2) | (0x01 << 3) | (0x01 << 4) ;
	
	//GPIOC->CRH |= (0x00<<19) | (0x00<<18) |(0x00<<17) |(0x01<<16);
//	GPIOC->ODR |= (0x01<<12);
	
	MyTimer_Base_Init (TIM2,36000,1000);
	MyTimer_Base_Start (TIM2);

	
	while(1) {
		//if (GPIOC->IDR[]){
			//GPIOC->ODR |= (0x01 << 12);
	//}
	}
}
