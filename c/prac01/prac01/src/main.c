/*   Ricardo Ruiz Maldonado
 *	 Practica 1: contador binario con retardo	
 */

#include <avr/io.h>
#include <asf.h>

int main (void)
{	
	DDRB = 0xFF;
	for(int counter = 0x00; counter <= 0xFF ; counter++){
		PORTB = counter;
		for (int counter2 = 0x00; counter2 <= 0xFF; counter2++)
		{
			for (int counter3 = 0x00; counter3 <=0xFF; counter3++)
			{
				/*for (int counter4 = 0x00; counter4 <=0xFF; counter4++)
				{
					//Do nothing
				}*/
			}
		}
		if (counter == 0xFF)
		{
			counter = 0x00;
		}
	}
}