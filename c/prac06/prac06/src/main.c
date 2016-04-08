/*   Ricardo Ruiz Maldonado
 *	 Practica 1: contador binario con retardo	
 */

#include <avr/io.h>
#include <asf.h>
#include <util/delay.h>

int encenderNum(int num);

int main (void)
{
	/* Insert system clock initialization code here (sysclk_init()). */

	board_init();

	/* Insert application code here, after the board has been initialized. */
	
	DDRB = 0xFF;
	for(int counter = 0; counter <= 15 ; counter++){
		PORTB = encenderNum(counter);
		_delay_ms(10000);
		if (counter == 15)
		{
			counter = 0;
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