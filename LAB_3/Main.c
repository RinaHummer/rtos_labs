#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"

void long_signal();
void short_signal();
void off_signal();
void delay(int del);

void (*statefunc)() = off_signal;
char array[] = {'_', '*', '*'};
int length = sizeof(array) / sizeof(char);

void delay(int del) {
	int i;
	for(i=0;i<del;i++){}
}
void long_signal() {
  GPIO_SetBits(GPIOA, GPIO_Pin_4);
	delay(0x60000);
  statefunc = off_signal;
}

void short_signal() {
  GPIO_SetBits(GPIOA, GPIO_Pin_4);
	delay(0x30000);

  statefunc = off_signal;
}

void off_signal() {
	GPIO_ResetBits(GPIOA, GPIO_Pin_4);
	delay(0xC0000);
}

int main(void) 
{
	GPIO_InitTypeDef  GPIO_InitStructure;
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

   
	//-**
  while(1) {
		for(int i = 0; i < length; i++) {
			(*statefunc)();
			if(array[i] == '_') {
				statefunc = long_signal;
				(*statefunc)();
			
			} else {
				statefunc = short_signal;
				(*statefunc)();
			}
		}
    (*statefunc)();
}
}



