/*   Ricardo Ruiz Maldonado
 *	 Practica 1: contador binario con retardo	
 */

#include <avr/io.h>
#include <asf.h>
#include <stdint.h>
#include <stdlib.h>

#include <avr/eeprom.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <avr/sleep.h>
#include <avr/wdt.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <inttypes.h>
#include <compiler.h>
#include <parts.h>
#include <util/delay.h>

unsigned int TIM16_ReadTCNT1(void);
void TIM16_WriteTCNT1( unsigned int i );

int main (void)
{	
	unsigned int i;
	
	/* Set TCNT1 to 0x01FF */
	TCNT1 = 0x1FF;
	/* Read TCNT1 into i */
	i = TCNT1;		
}

unsigned int TIM16_ReadTCNT1(void)
{
	unsigned char sreg;
	unsigned int i;
	/* Save Global Interrupt Flag */
	sreg = SREG;
	/* Disable interrupts */
	_CLI();
	/* Read TCNT1 into i */
	i = TCNT1;
	/* Restore Global Interrupt Flag */
	SREG = sreg;
	return i;
}

void TIM16_WriteTCNT1( unsigned int i )
{
	unsigned char sreg;
	/* Save Global Interrupt Flag */
	sreg = SREG;
	/* Disable interrupts */
	_CLI();
	/* Set TCNT1 to i */
	TCNT1 = i;
	/* Restore Global Interrupt Flag */
	SREG = sreg;
}