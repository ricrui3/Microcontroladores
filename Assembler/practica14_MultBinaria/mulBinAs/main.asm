;
; mulBinAs.asm
;
; Created: 22/04/2016 05:47:56 p.m.
; Author : Rubik
;

			.INCLUDE "M8535DEF.INC"
			.CSEG
			.ORG $0
			RJMP INICIO
			.ORG $015
INICIO:		LDI R16, $FF	;CARGO R16 CON $FF
			OUT DDRB, R16	;CONFIGURO PUERTO B COMO SALIDA
			OUT PORTA, R16
			LDI R17, $00	;CARGO R17 CON $00
			OUT DDRA, R17   ;CONFIGURO PUERTO A COMO ENTRADA
			LDI R18, $0F
			LDI R19, $F0
LOOP:		IN R21, PINA
			MOV R20, R21
			AND R21, R18
			AND R20, R19
			SWAP R20
			MULS R21, R20
			OUT PORTB, R0	;ESCRIBO DATO EN PUERTO B
			RJMP LOOP	;SALTO A LOOP
