/*
 * Copyright (c) 2007, Ryo Ichinose
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without 
 * modification, are permitted provided that the following conditions are met:
 *
 *    * Redistributions of source code must retain the above copyright 
 *      notice, this list of conditions and the following disclaimer.
 *    * Redistributions in binary form must reproduce the above copyright 
 *      notice, this list of conditions and the following disclaimer in the 
 *      documentation and/or other materials provided with the distribution.
 *    * Neither the name of the auther nor the 
 *      names of its contributors may be used to endorse or promote products 
 *      derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, 
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR 
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR 
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, 
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, 
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, 
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR 
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF 
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <avr/interrupt.h>
#include <avr/io.h>
#include <inttypes.h>

#include "usart.h"


/* Baud rate (bps) */
#define USART_BAUD 9600 


static void (*rx_interrupt_handler)(void);


/*
 * rx complete interrupt handler called by avr-libc.
 * This will be enabled when the macro USART_USE_INT is specified to usart_init().
 */
ISR(USART_RX_vect)
{
	rx_interrupt_handler();
}


/*
 * The setter of user function
 * which will be called from rx complete interrupt handler.
 */
void
usart_set_rx_interrupt(void (*func)(void))
{
	rx_interrupt_handler = func;
}


/*
 * Sets the USART parameters to 9600bps/8N1.
 *
 * When the program will use rx complete interrupt,
 * call sei() after executing this function (usart_init()). 
 */
void
usart_init(int use_interrupt)
{
	/* Calculates the baud rate parameter to set UBRR to. Equation is (F_CPU/(16*BAUD)) - 1 */
	uint16_t baud = (F_CPU / (16UL * USART_BAUD)) - 1;
	
	UBRRH = (uint8_t)(baud >> 8);
	UBRRL = (uint8_t)baud;

	if (use_interrupt) {
		/* Enables Tx/Rx/rx complete interrupt */
		UCSRB = _BV(TXEN) | _BV(RXEN) | _BV(RXCIE);
	}
	else {
		/* Enables Tx/Rx */
		UCSRB = _BV(TXEN) | _BV(RXEN);
	}
}


/*
 * Receives 1 character.
 * Returns -1 when the framing error or overrun occurred.
 */
int8_t
usart_rx_char(void)
{
	loop_until_bit_is_set(UCSRA, RXC);

	if ((UCSRA & _BV(FE)) || (UCSRA & _BV(DOR))) {
		return -1;
	}

	return UDR;
}


/*
 * Sends 1 character.
 */
void
usart_tx_char(int8_t c)
{
	loop_until_bit_is_set(UCSRA, UDRE);
	UDR = c;
}


/*
 * Sends character string.
 */
void
usart_tx_string(char *string)
{
	while (*string != '\0') {
		usart_tx_char(*string);
		string ++;
	}
}


/* End of usart.c */
