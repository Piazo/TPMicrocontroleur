#include "stm32f10x.h"
#include "MyTimer.h"
#include "Driver_GPIO.h"

void CallBack(){
	My_GPIO_Toggle(GPIOC, 10);
}

int main(void){
	
	/* Initialization of GPIOC 13 as Ouput OpenDrain */
	MyGPIO_Struct gp = {GPIOC, 10, Out_OD};
	MyGPIO_Init(&gp);
	
	// Initialization of Timer1 with period 500ms invoking function Callback
	MyTimer_Base_Init (TIM1,36000,1000);
	MyTimer_Base_Start (TIM1);
	MyTimer_ActiveIT(TIM1, 1, CallBack);
	
	while	(1) {
		;
	}
}
