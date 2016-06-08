/*
 * pract16.c
 *
 * Created: 06/06/2016 12:59:51 a.m.
 * Author : Rubik
 */ 
#include <avr/io.h>
#include <avr/sfr_defs.h>

int main (void)
{
	DDRB = 0xFF;						//Define DDRB como salidas
	PORTB = 0x00;
	TCCR1B = _BV(CS11);					//Enciende el bit CS11 del timer 1 para
										//	frecuencia CLK/8
	ADMUX = _BV(ADLAR);					//Configura carga a la izquierda
										//		y entrada ADC0 (PINA0)
	ADCSRA = _BV(ADEN) | _BV(ADATE) | _BV(ADPS2) | _BV(ADPS1);
										//HABILITA EL ADC Y EL AUTODISPARO
										//	fACTOR DE DIVISION DE 64
	
	while(1){
		//Comprueba si ya hubo desbordamiento del timer1:
		if((TIFR & _BV(TOV1))){
			TIFR |= _BV(TOV1);			//Limpia la bandera
			ADCSRA = _BV(ADSC);
			while(!(ADCSRA & (1<<ADIF)));
			PORTB = ADC;
		}
	}
}
