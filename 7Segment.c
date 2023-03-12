#include<avr/io.h>
#include<util/delay.h>
int main(){
	uint8_t i = 0;
	/*Configurations*/
	unsigned char sgment []={0X7E,0X0C,0XB6,0X9E,0XCC,0XDA,0XFA,0X0E,0XFE,0XDE};
	DDRA=0xFF;           /*ddr d0,d1,d2,d3,d4,d5,d6,d7 output */
	DDRD &= (~(1<<2)); /*ddrd2 = 0 input*/
	DDRD&=(~(1<<3)); /*ddrd3 = 0 input*/
	PORTA=0X7E;             /*as a start PORTA = 0 */
	DDRC = (1<<6);
	PORTC = (1<<6);
	/*Code*/
	while(1)
	{
		if (!(PIND&(1<<2))) 
		{   if(i>=9){i=9;}
		else{
			i++;
			PORTA=sgment[i];
			_delay_ms(250);}
			
		} else if (!(PIND&(1<<3)))   
		{   if(i<=0){i=0;}
		else{
			i--;
			PORTA=sgment[i];
				_delay_ms(250);}
			
			}
		else{}
		}


	}

