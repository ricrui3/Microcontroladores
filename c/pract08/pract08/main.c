/*
 * pract07.c
 *
 * Created: 05/06/2016 09:05:24 p.m.
 * Author : Rubik
 */ 

#include <stdio.h>
#include <avr/io.h>
#include <avr/sfr_defs.h>

int main(void) {
 	UBRRL = 79;									//SE CONFIGURA LA FRECUENCIA
												//	9600@12MHz
 	UCSRC = (1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);	//8 bits de datos
 	UCSRB = (1<<RXEN);							//SE ENCIENDE EN MODO DE TRANSMISION
	DDRB = 0xFF;								//Define DDRB como salidas
	TCCR1B = _BV(CS11);							//Enciende el bit CS11 del timer 1 para
												//	frecuencia CLK/8
	char PortData = 'R';
			
	
	//Ciclo infinito
	while(1){
		//Comprueba si ya hubo desbordamiento del timer1:
		if((TIFR & _BV(TOV1))){
			TIFR |= _BV(TOV1);					//Limpia la bandera
			while(!(UCSRA&(1<<RXC)));			//Espera a que se termine de recibir
			PortData = UDR;						//Lee el dato recibido
			PORTB = PortData;					//Muestra el valor del caracter a enviar 
												//	en los LEDS
		}		
	};
}

