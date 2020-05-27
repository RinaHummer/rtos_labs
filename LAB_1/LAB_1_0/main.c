void delay(int i, int val) {
				for(i=0;i<val;i++){}
}
			

int main (void){
		//Pointers init
	int *GPIO_B_CRH = (int*)(0x40010C04);
	int *GPIO_B_IDR =(int*)(0x40010C08);

	int *GPIO_A_CRL = (int*)(0x40010800);
	int *GPIO_A_ODR = (int*)(0x4001080C);

	int *apb2enr = (int*)(0x40021018);

	//Init bus for A and B
	*apb2enr |= 0x00000004;
	*apb2enr |= 0x00000008;
	
	//Set B12 as input
	*GPIO_B_CRH = 0x0080000;
	
	//Set A4 as output
	*GPIO_A_CRL = 0x00030000;
	
	//consts and counter for the delays
	int counter;
	int long_delay = 0x60000;
	int short_delay = 0x30000;
	int just_delay = 0xC0000;
	
	//-** *- ---- *- 
	for (;;) {
		delay(counter,just_delay);
		*GPIO_A_ODR = 0x00000010;
		delay(counter,long_delay);
		*GPIO_A_ODR = 0x00000000;
		delay(counter,just_delay);
		*GPIO_A_ODR = 0x00000010;
		delay(counter, short_delay);
		*GPIO_A_ODR = 0x00000000;
		delay(counter, just_delay);
		*GPIO_A_ODR = 0x00000010;
		delay(counter, short_delay);
	}
	
}


