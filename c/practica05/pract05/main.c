/*
 * Author : Ricardo Ruiz Maldonado
 * Practica 5: PWM C/Timer2 Up/Down
 * Created: 05/06/2016 07:44:55 p.m.
 */ 

#include <avr/io.h>
#include <avr/sfr_defs.h> // Para la macro _BV()

/*Aqui va el codigo a ciclar*/
int main(void)
{
	int portBValue = 0x00;
	int upDown = 1;						//1 = up, 0 = down
	DDRB =	0xFF;						//Define DDRB como salidas
	PORTB = portBValue;						//Se define el valor del puerto B en 00
	DDRD =	0x80;						//Se define el pin 8 de PORTD como salida (PWM)
	//TCCR2 = 0x62;						//Timer2 en modo PWM en fase correcta
	TCCR2 = _BV(WGM20) | _BV(COM21) | _BV(CS21); //	con CLCK/8
	TCCR1B = _BV(CS11);					//Enciende el bit CS11 del timer 1 para
										//	frecuencia CLK/8
	
	/*Aqui va el codigo a ciclar*/
	while (1)
	{
		//Comprueba si ya hubo desbordamiento del timer1:
		if((TIFR & _BV(TOV1))){
			TIFR |= _BV(TOV1);			//Limpia la bandera
			PORTB = portBValue;			//Muestra el valor en los LEDS
			if (upDown == 1)
			{
				if(portBValue == 0xFF)		//Si el valor es igual a 255
					upDown = 0;		//	regresar a 0
				else                        //De otra forma
					portBValue++;			//Incrementa el valor
			} 
			else
			{
				if(portBValue == 0x00)		//Si el valor es igual a 255
					upDown = 1;		//	regresar a 0
				else                        //De otra forma
					portBValue--;			//Incrementa el valor
			}
			OCR2 = portBValue;					//Lee el valor del PINA (minidip) y lo guarda en
											//	OCR2 (PWM)	
		}
	}
}