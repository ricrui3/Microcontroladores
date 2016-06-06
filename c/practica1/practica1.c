#include <avr/io.h>

int main (void)
{	
	int counter = 0x00;
	int counter2 = 0x00;
	int counter3 = 0x00;

	DDRB = 0xFF;
	for(counter = 0x00; counter <= 0xFF ; counter++){
		PORTB = counter;
		for (counter2 = 0x00; counter2 <= 0xFF; counter2++)
		{
			for (counter3 = 0x00; counter3 <=0xFF; counter3++)
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
	return 0;
}