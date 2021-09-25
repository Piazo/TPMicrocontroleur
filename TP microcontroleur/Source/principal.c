#include "stm32f10x.h"
#include "MyTimer.h"
#include "Driver_GPIO.h"

void CallBack(){
	
}




int main(void){
	

	
	/* GPIOC->CRH &= ~(0xF << 16);
	GPIOC->CRH |= (In_PullUp << 16);
	
	GPIOC->ODR |= (0x01<<12); */
	
	MyGPIO_Struct gp = {GPIOC, 13, In_PullDown};
	MyGPIO_Init(&gp);
	
	
	
	/* MyTimer_Base_Init (TIM1,36000,1000);
	MyTimer_Base_Start (TIM1);
	MyTimer_ActiveIT(TIM1, 1, CallBack); */

	
	while(1) {
		//if (GPIOC->IDR[]){
			//GPIOC->ODR |= (0x01 << 12);
		//}
	}
}
