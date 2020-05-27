#include "stm32f10x.h"

void delay(int delay);

int main(void){ 
      // Enable PORTB Clock    
      RCC -> APB2ENR |= RCC_APB2ENR_IOPBEN;
			// Enable  all low port B for output push-pool Mode
      GPIOB -> CRH &= 0; 
      GPIOB -> CRH |= GPIO_CRL_MODE; 
  
        for(;;){
               
					GPIOB -> ODR |= GPIO_ODR_ODR12;// pin B0 on
          delay(0x2500);
          GPIOB -> ODR &= ~(GPIO_ODR_ODR12);// pin B0 off
					delay(0x2500);
					
        }      
    }

void delay(int delay){
  int i = 0;
    for(i=0;i<delay;i++){
      ;
      }
}

