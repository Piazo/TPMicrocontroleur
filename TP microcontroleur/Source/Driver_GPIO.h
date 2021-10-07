
#ifndef MYGPIO_H
#define MYGPIO_H
#include "stm32f10x.h"

typedef struct {
	GPIO_TypeDef * GPIO;
	char GPIO_Pin;
	char GPIO_Conf;
} MyGPIO_Struct;

#define In_Floating 0x4
#define In_PullDown 0x8
#define In_PullUp 0x8
#define In_Analog 0x0
#define Out_Ppull 0x1
#define Out_OD 0x5
#define AltOut_Ppull 0x9
#define AltOut_OD 0xD

void MyGPIO_Init(MyGPIO_Struct * GPIOStruct);
int MyGPIO_Read(GPIO_TypeDef * GPIO, char GPIO_PIN);
void My_GPIO_Set(GPIO_TypeDef * GPIO, char GPIO_PIN);
void My_GPIO_Reset(GPIO_TypeDef * GPIO, char GPIO_PIN);
void My_GPIO_Toggle(GPIO_TypeDef * GPIO, char GPIO_PIN);

#endif
