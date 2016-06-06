/*
 * Created: 05/06/2016 07:44:55 p.m.
 * Author : Ricardo Ruiz Maldonado
 * Practica 5: PWM C/Timer2 Up/Down
 */ 

#include <avr/io.h>
#include <avr/sfr_defs.h> // Para la macro _BV()


int main(void)
{
	int portBValue = 0x00;
	bool upDown = true;					//true = up, false = down
	DDRB = 0xFF;						//Define DDRB como salidas
	PORTB = portBValue;					//Se define el valor del puerto B en 00
	DDRD = 0x80;						//Se define el pin 8 de PORTD como salida (PWM)
	//TCCR2 = 0x62;						//Timer2 en modo PWM en fase correcta
	TCCR2 = _BV(WGM20) | _BV(COM21) | _BV(CS21); //	con CLCK/8
	TCCR1B = _BV(CS11);					//Enciende el bit CS11 del timer 1 para
										//	frecuencia CLK/8
	
	/* Replace with your application code */
	while (1)
	{
		//Comprueba si ya hubo desbordamiento del timer1:
		if((TIFR & _BV(TOV1))){
			TIFR |= _BV(TOV1);			//Limpia la bandera
			PORTB = portBValue;			//Muestra el valor en los LEDS
			if (upDown)
			{
							if(portBValue == 0xFF)		//Si el valor es igual a 255
							portBValue = 0x00;		//	regresar a 0
							else                        //De otra forma
							portBValue++;			//Incrementa el valor
			} 
			else
			{
			}
		}
		PORTB = PINA;					//Lee el valor del PINA (minidip) y lo muestra en
										//	en PORTB (LEDS)
		OCR2 = PINA;					//Lee el valor del PINA (minidip) y lo guarda en
										//	OCR2 (PWM)
	}
}
