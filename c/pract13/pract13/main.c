/*
 * pract13.c
 *
 * Created: 06/06/2016 12:45:38 a.m.
 * Author : Rubik
 */ 

#include <avr/io.h>

int main (void)
{
	/* Insert application code here, after the board has been initialized. */
	
	DDRA = 0x00;						//Define DDRA como Entradas
	DDRB = 0xFF;						//Define DDRB como salidas
	PORTA = 0XFF;						//PULL UP activado
	int result = 0x00;
	int value1 = 0x00;
	int value2 = 0x00;
	
	while(1){
		result = PINA;					//Lee el dato de PORTA
		value1 = (result & 0x0f);		//Aplica mascara 0x0F -> 00001111
		value2 = (result & 0xf0);		//Aplica mascara 0xF0 -> 11110000
		value2 = value2  >> 4;			//Intercambia nibbles
		result = value2 - value1;		//Resta los valores
		PORTB = result;
	}
}

