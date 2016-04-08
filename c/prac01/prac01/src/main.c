/*   Ricardo Ruiz Maldonado
 *	 Practica 1: contador binario con retardo	
 */

#include <avr/io.h>
#include <asf.h>
#include <util/delay.h>

int main (void)
{
	/* Insert system clock initialization code here (sysclk_init()). */

	board_init();

	/* Insert application code here, after the board has been initialized. */
	
	DDRB = 0xFF;
	for(int counter = 0x00; counter <= 0xFF ; counter++){
		PORTB = counter;
		_delay_ms(500);
		if (counter == 0xFF)
		{
			counter = 0x00;
		}
	}
}