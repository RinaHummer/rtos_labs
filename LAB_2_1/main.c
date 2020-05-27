void delay(int val) {
		int i;
		for(i=0;i<val;i++){}
}
			

int main (void){
		//Pointers init
	int *GPIO_B_CRH = (int*)(0x40010C04);
	int *GPIO_B_ODR =(int*)(0x40010C0C);

	int *GPIO_A_CRL = (int*)(0x40010800);
	int *GPIO_A_ODR = (int*)(0x4001080C);

	int *apb2enr = (int*)(0x40021018);

	//Init bus for A and B
	*apb2enr |= 0x00000004;
	*apb2enr |= 0x00000008;
	
	//Set B12 as output
	*GPIO_B_CRH = 0x0030000;
	
	//Set A4 as output
	*GPIO_A_CRL = 0x00030000;
	
	
	for (;;) {
		
		*GPIO_A_ODR = 0x00000010;
		delay(0x3500);
		*GPIO_A_ODR = 0x00000000;
		delay(0x1500);

	}
	
}



