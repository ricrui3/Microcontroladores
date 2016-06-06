/*   Ricardo Ruiz Maldonado
 *	 Practica 2: Lectura/escritura puertos (A->B)
 */

#include <avr/io.h>

int main (void)
{
	/* Insert application code here, after the board has been initialized. */
	
	DDRA = 0x00;
	DDRB = 0xFF;
	PORTA = 0XFF;
	
	while(1){
		PORTB = PINA;
	}
}

