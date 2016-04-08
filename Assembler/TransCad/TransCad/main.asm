;
; TransCad.asm
;
; Created: 04/04/2016 03:27:40 p.m.
; Author : Rubik
;

			.INCLUDE "M85358EF.INC"
			.CSEG
			.ORG $0
			RJMP INICIO
TABLA:		.DB "IPN ESCOM MICROCONTROLADORES HECTOR M PAZ R 2016$"
INICIO:		LDI R16, LOW(RAMEND)		;
			OUT SPL, R16				;   INIT
			LDI R16, HIGH(RAMEND)		;	STACK POINTER
			OUT SPH, R16				;
			LDI R17, $24; GUARDO EL ASCII DE FIN DE CADENA
			LDI R16, 77		;  CONFIGURA BAUD RATE
			OUT UBRRL, R16	;		9600 BAUDS
			SBI UCSRB, TXEN; HABILITO UART EN MODO TRANSMISION
			LDI ZL, LOW(TABLA<<1)	;	CARGO REGISTRO Z
			LDI ZH, HIGH(TABLA<<1)	;		CON (TABLA)
			LPM ;	LEE DATO EN (TABLA), R0 <- (Z)
ENVIA:		OUT UDR, R0;	TRANSMITO DATO
LOOP:		SBIS UCSRA, UDRE	;	ESPERO FIN DE TRANSMISION
			RJMP LOOP			;		DE CARACTER
			ADIW ZL, 1	;	INCREMENTA Z
			LPM			;	LEO ELEMENTO DE (TABLA), R0 <-(Z)
			CPSE R0, R17	; COMPARA SI ES FIN DE CADENA
			RJMP ENVIA		; SI FALSO
DELAY:		;---------		; SI VERDADERO EJECUTA UN RETARDO
			;---------
			;---------
			;---------
			RJMP INICIO

