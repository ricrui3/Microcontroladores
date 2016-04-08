/*   Ricardo Ruiz Maldonado
 *	 Practica 0: contador binario sin retardo	
 */
#include <avr/io.h>
#include <asf.h>

int main (void)
{
	DDRB = 0xFF;
	for(int counter = 0x00; counter <= 0xFF ; counter++)
		PORTB = counter;
}