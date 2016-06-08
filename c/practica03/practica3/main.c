/*
 * practica3.c Contador Binario Con TIMER01
 * Author : Ricardo Ruiz Maldonado
 */ 

#include <avr/io.h>
#include <avr/sfr_defs.h> // Para la macro _BV()

int main(void)
{
	int portBValue = 0x00;
	DDRB = 0xFF;						//Define DDRB como salidas
	PORTB = portBValue;					//Se define el valor del puerto B en 00
	TCCR1B = _BV(CS11);					//Enciende el bit CS11 del timer 1 para 
										//	frecuencia CLK/8
	
	/*Aqui va el codigo a ciclar*/
    while (1) 
    {
		//Comprueba si ya hubo desbordamiento del timer1:
		if((TIFR & _BV(TOV1))){
			TIFR |= _BV(TOV1);			//Limpia la bandera
			PORTB = portBValue;			//Muestra el valor en los LEDS
			if(portBValue == 0xFF)		//Si el valor es igual a 255
				portBValue = 0x00;		//	regresar a 0
			else                        //De otra forma
				portBValue++;			//Incrementa el valor
		}
    }
}

