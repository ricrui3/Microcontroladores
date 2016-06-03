;
; prac0Ass.asm
;
; Created: 04/04/2016 04:03:53 p.m.
; Author : Ricardo Ruiz Maldonado
; Practica: Aritm�tica Binaria
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
LOOP:		IN R0, PINA
			MOV R1, R0
			AND R0, R18
			AND R1, R19
			SWAP R1
			ADD R0, R1
			OUT PORTB, R0	;ESCRIBO DATO EN PUERTO B
			RJMP LOOP	;SALTO A LOOP