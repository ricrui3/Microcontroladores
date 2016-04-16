/*   Ricardo Ruiz Maldonado
 *	 Practica 0.1: Semaforo	
 */
#include <avr/io.h>
#include <asf.h>

/*#define _BV(bit)\
(1 << (bit))*/
#define _ROJO1()\
(1 << 0)
#define _AMBAR1()\
(1 << 1)
#define _VERDE1()\
(1 << 2)
#define _VUELTA1()\
(1 << 3)
#define _ROJO2()\
(1 << 4)
#define _AMBAR2()\
(1 << 5)
#define _VERDE2()\
(1 << 6)
#define _VUELTA2()\
(1 << 7)


int main (void)
{
	DDRB = 0xFF;
	PORTB = 0x00;
	PORTB |= _ROJO1();
	PORTB |= _VUELTA1();
	PORTB |= _AMBAR2();
	PORTB |= _ROJO2();
}