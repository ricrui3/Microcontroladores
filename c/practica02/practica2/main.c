/*   Ricardo Ruiz Maldonado
 *	 Practica 2: Lectura/escritura puertos (A->B)
 */

#include <avr/io.h>

int main (void)
{
	//--------Inicializa los valores---------
	DDRB = 0xFF;		//Inicializa PORTB como salida
	DDRA = 0x00;		//Inicializa DDRA como salida
	PORTA = 0XFF;		//	pull up activado
	//---------------------------------------
	
	while(1){
		PORTB = PINA;	//Lee el dato de PINA y lo
						//	escribe en PORTB
	}
}

