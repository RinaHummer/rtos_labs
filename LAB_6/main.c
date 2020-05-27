#include "STM32F10x.h"
#include <cmsis_os.h>
#include "STM32F10x_gpio.h"
#include "STM32F10x_rcc.h"

void delay(int i) {
    for (int i = 0; i < 10000 * i; i++) {}
}

void thread1(void const *argument)
{
    while(1) {
        GPIO_SetBits(GPIOB, GPIO_Pin_1);
        delay(100);
        GPIO_ResetBits(GPIOB, GPIO_Pin_1);
        delay(100);
    }
}

void thread2(void const *argument)
{
    while(1) {
        GPIO_SetBits(GPIOB, (GPIO_Pin_2));
        delay(300);
        GPIO_ResetBits(GPIOB, GPIO_Pin_2);
        delay(300);
    }
}

osThreadId main_ID, led_ID1, led_ID2, led_ID3;
osThreadDef(thread2, osPriorityNormal,1, 0);
osThreadDef(thread1, osPriorityNormal,1, 0);

int main(void) {
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_2;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
	
    osKernelInitialize();                    
    led_ID1 = osThreadCreate(osThread(thread1), NULL);
    led_ID2 = osThreadCreate(osThread(thread2), NULL);
    osKernelStart();   
	
    for (;;) {}
}