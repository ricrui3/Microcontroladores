/*   Ricardo Ruiz Maldonado
 *   Practica 0.1: Semaforo 
 */
#include <avr/io.h>
#include <asf.h>

/*#define _BV(bit)\
(1 << (bit))*/
#define _ROJO1(bit)\
 (bit << 0)
#define _AMBAR1(bit)\
 (bit << 1)
#define _VERDE1(bit)\
 (bit << 2)
#define _VUELTA1(bit)\
 (bit << 3)
#define _ROJO2(bit)\
 (bit << 4)
#define _AMBAR2(bit)\
 (bit << 5)
#define _VERDE2(bit)\
 (bit << 6)
#define _VUELTA2(bit)\
 (bit << 7)

//Semaforo

void delay1(bool r1, bool a1, bool v1, bool vuelta1, bool r2, bool a2, bool v2, bool vuelta2);
void delay2(bool r1, bool a1, bool v1, bool vuelta1, bool r2, bool a2, bool v2, bool vuelta2);
void delay3(bool r1, bool a1, bool v1, bool vuelta1, bool r2, bool a2, bool v2, bool vuelta2);

 int main (void)
 {
	DDRB = 0xFF;
	PORTB = 0x00;
	//Prende led Rojo 1 y verde 2
	delay1(true,false,false,false,false,false,true,false);
	//Prende led Rojo 2 y verde 1
	delay1(false,false,false,false,false,false,false,false);
 }

void delay1(bool r1, bool a1, bool v1, bool vuelta1, bool r2, bool a2, bool v2, bool vuelta2){
	for(int counter = 0x00; counter <= 0xFF; counter++)
	{
		for (int counter2 = 0x00; counter2 <= 0xFF; counter2++)
		{
			for (int counter3 = 0x00; counter3 <=0xB9; counter3++)
			{
			}
		}
		
	}
	PORTB |= _ROJO1(r1);
	PORTB |= _AMBAR1(a1);
	PORTB |= _VERDE1(v1);
	PORTB |= _VUELTA1(vuelta1);
	PORTB |= _ROJO2(r2);
	PORTB |= _AMBAR2(a2);
	PORTB |= _VERDE2(v2);
	PORTB |= _VUELTA2(vuelta2);
}