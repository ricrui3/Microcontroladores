/*   Ricardo Ruiz Maldonado
 *	 Practica 1: contador binario con retardo	
 */

#include <avr/io.h>
#include <asf.h>

int encenderNum(int num);
int delay1(void);

int main (void)
{
	/* Insert system clock initialization code here (sysclk_init()). */

	board_init();

	/* Insert application code here, after the board has been initialized. */
	
	DDRB = 0xFF;
	for(int counter = 0; counter <= 15 ; counter++){
		for(int counter2 = 0x00; counter2 <= 0xFF ; counter2++){
			for (int counter3 = 0x00; counter3 <= 0xFF; counter3++)
			{
				for (int counter4 = 0x00; counter4 <=0x09; counter4++)
				{
					PORTB = encenderNum(counter);
				}
			}
		}
		if (counter == 15)
		{
			counter = -1;
		}
	}
}

int encenderNum(int num){
	switch(num){
		case 0:{
			return 0xFD;
			break;
		}
		case 1:{
			return 0x60;
			break;
		}
		case 2:{
			return 0xDB;
			break;
		}
		case 3:{
			return 0xF2;
			break;
		}
		case 4:{
			return 0x67;
			break;
		}
		case 5:{
			return 0xB6;
			break;
		}
		case 6:{
			return 0xBF;
			break;
		}
		case 7:{
			return 0xE0;
			break;
		}
		case 8:{
			return 0xFF;
			break;
		}
		case 9:{
			return 0xE6;
			break;
		}
		case 10:{
			return 0xEF;
			break;
		}
		case 11:{
			return 0x3E;
			break;
		}
		case 12:{
			return 0x9D;
			break;
		}
		case 13:{
			return 0x7A;
			break;
		}
		case 14:{
			return 0x9F;
			break;
		}
		case 15:{
			return 0xE2;
			break;
		}
		default:{
			return 0x00;
			break;
		}
	}
}