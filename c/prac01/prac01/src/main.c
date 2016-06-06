/*   Ricardo Ruiz Maldonado
 *	 Practica 1: contador binario con retardo	
 */

#include <avr/io.h>
#include <asf.h>

int main (void)
{	
	int portBValue = 0x00;
	DDRB = 0xFF;
	while(true){
		PORTB = portBValue;
		for(int counter = 0x00; counter <= 0xFF ; counter++)
		{
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
		}
		if (portBValue == 0xFF)
		{
			portBValue = 0x00;
		}
	}
}