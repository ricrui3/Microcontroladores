/*
 * pract10.c
 *
 * Created: 05/06/2016 11:40:38 p.m.
 * Author : Rubik
 */ 

#include <stdio.h>
#include <avr/io.h>
#include <avr/sfr_defs.h>

int main(void) {
	UBRRL = 79;									//SE CONFIGURA LOS BAUD
												//	9600@12MHz
	UCSRC = (1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);	//8 bits de datos
	UCSRB = (1<<TXEN);							//SE ENCIENDE EN MODO DE TRANSMISION
	DDRB = 0xFF;								//Define DDRB como salidas
	TCCR1B = _BV(CS11);							//Enciende el bit CS11 del timer 1 para
												//	frecuencia CLK/8
	char * PortData = "IPN ESCOM MICROCONTROLADORES HECTOR M PAZ R 2016$";
	char charActual = 'R';
	int counter = 0;
	
	
	//Ciclo infinito
	while(1){
		//Comprueba si ya hubo desbordamiento del timer1:
		if((TIFR & _BV(TOV1))){
			TIFR |= _BV(TOV1);					//Limpia la bandera
			
			//-----------------------TRANSMISION-----------------------------------------
				charActual = PortData[counter];
				UDR = charActual;
				while (!(UCSRA & (1<<UDRE)));
				if (charActual == '$')
					counter = 0;
				else
					counter++;
			//--------------------------------------------------------------------------
		}
	};
}

