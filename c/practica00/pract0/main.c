/*   Ricardo Ruiz Maldonado
 *	 Practica 0: contador binario sin retardo	
 */

#include <avr/io.h>

 int main (void)
 {
	DDRB = 0xFF; //Inicializa PORTB como salidas
	while(1){
		//Itera desde 0 (0x00) hasta 255 (0xFF)
		for(int counter = 0x00; counter <= 0xFF ; counter++)
			PORTB = counter;
	}
}