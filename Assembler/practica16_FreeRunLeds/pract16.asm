; Author : Ricardo Ruiz Maldonado
; Practica 16 - Conversion 1 canal Free run a LEDS 

			.include "m8535def.inc"
			.cseg		
			.org $0
			rjmp INICIO
			.org $15

INICIO: 	LDI 	R16, 	LOW(RAMEND)		;--------------------------
			OUT 	SPL, 	R16				;    INICIALIZAMOS EL 
			LDI 	R16, 	HIGH(RAMEND)	;	 STACK POINTER
			OUT 	SPH, 	R16				;--------------------------
			;----------------------------------------------------------
			LDI		R16,	78				;SE CONFIGURA LA FRECUENCIA 
			OUT 	UBRRL, 	R16				;	9600@12MHz	

			LDI 	R16,	0b10000110		;
			OUT		UCSRC,	R16

			SBI		UCSRB,	TXEN			;SE ENCIENDE EN MODO DE TRANSMICION
			LDI		R16,	$52				;VALOR DE CARACTER 'R'
			OUT 	PORTB,	R16	
			;----------------------------------------------------------
			SER		R16				
			OUT		DDRB,	R16		;CONFIGURA PUERTO B COMO SALIDA
			OUT		DDRC,	R16		;CONFIGURA PUERTO C COMO SALIDA
			LDI		R17,	$00		;CFG. ADMUX CANAL 0
			OUT		ADMUX,	R17		;	ADUAR = 1
			LDI		R16,	$A6		;CFG. ADCSRA, CLOCK F/64
			OUT		ADCSRA,	R16		;MODO FREE RUN
DISPARO:	SBI		ADCSRA,	6		;DISPARO INICIO DE CONVERSION

LOOP:		SBIS	ADCSRA,	4		;ESPERA FIN DE CONVERSION
			RJMP	LOOP			;	ESPERA
			IN 		R16,	ADCL	;LEE RESULTADO DE LA
			IN		R17,	ADCH	;	CONVERSION
			OUT		PORTB,	R16		;ESCRIBE PRIMEROS 8 BITS DE LA 
									;CONVERSION EN PORTB
			OUT		PORTC, 	R17		;ESCRIBE LOS 2 ULTIMOS BITS DE LA 
									;CONVERSION EN PORTC
			RJMP	DISPARO
