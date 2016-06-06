/*
 * practica4.c PWM Timer 2 con minidip
 *
 * Created: 05/06/2016 07:25:41 p.m.
 * Author : Ricardo Ruiz Maldonado
 */ 

#include <avr/io.h>
#include <avr/sfr_defs.h> // Para la macro _BV()


int main(void)
{
	int portBValue = 0x00;
	PORTA = 0xFF;						//Activa Pull up en puerto A
	DDRB = 0xFF;						//Define DDRB como salidas
	PORTB = portBValue;					//Se define el valor del puerto B en 00
	DDRD = 0x80;						//Se define el pin 8 de PORTD como salida (PWM)
	//TCCR2 = 0x62;						//Timer2 en modo PWM en fase correcta								
	TCCR2 = _BV(WGM20) | _BV(COM21) | _BV(CS21); //	con CLCK/8
	
    /* Replace with your application code */
    while (1) 
    {
		PORTB = PINA;					//Lee el valor del PINA (minidip) y lo muestra en
										//	en PORTB (LEDS)
		OCR2 = PINA;					//Lee el valor del PINA (minidip) y lo guarda en
										//	OCR2 (PWM)
    }
}

