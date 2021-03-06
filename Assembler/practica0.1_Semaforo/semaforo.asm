;00511953866078 52629925
;
; SemafAss.asm
;
; Created: 20/05/2016 05:01:09 p.m.
; Author : Ricardo Ruiz Maldonado
; Practica 0.1: Semaforo

; Semaforo
		.INCLUDE "M8535DEF.INC" ;Declaracion archivo include
		.EQU ROJO1 = 0
		.EQU AMBAR1 = 1
		.EQU VERDE1 = 2
		.EQU VUELTA1 = 3
		.EQU ROJO2 = 4
		.EQU AMBAR2 = 5
		.EQU VERDE2 = 6
		.EQU VUELTA2 = 7

		.ORG $0 ;Origen en 0
		RJMP INICIO
		.ORG $015
INICIO: LDI R16, LOW(RAMEND)	;------------------------
		OUT SPL, R16			;    INICIALIZAMOS EL 
		LDI R16, HIGH(RAMEND)	;	 STACK POINTER
		OUT SPH, R16			;------------------------
		LDI R16, $FF	;ASIGNAMOS EL VALOR DE $FF EN EL REGISTRO 16
		OUT DDRB, R16	;SE ASIGNA R16 EN DDRB Y A SU VEZ LO CONFIGURA COMO SALIDA
		LDI R16, $14	;PRENDE LOS LEDS "VERDE1" Y "ROJO2"
		OUT PORTB, R16	;ESCRIBE DATO EN PORTB "PRENDE LOS FOQUITOS"
		RCALL DELAY2

		SBI PORTB, VUELTA1 ;PRENDE EL LED VUELTA1
		RCALL DELAY1
		CBI PORTB, VUELTA1 ;APAGA EL LED VUELTA1
		RCALL DELAY1
		SBI PORTB, VUELTA1 ;PRENDE EL LED VUELTA1
		RCALL DELAY1
		CBI PORTB, VUELTA1 ;APAGA EL LED VUELTA1
		RCALL DELAY1

		;--------PARPADEO VERDE1: 3 SEGS----------------
		SBI PORTB, VUELTA1;PRENDE EL LED DE VUELTA1
		SBI PORTB, VERDE1 ;PRENDE EL LED VERDE1
		RCALL DELAY1
		CBI PORTB, VERDE1 ;APAGA EL LED VERDE1
		CBI PORTB, VUELTA1 ;APAGA EL LED VUELTA1
		RCALL DELAY1
		SBI PORTB, VERDE1 ;PRENDE EL LED VERDE1
		SBI PORTB, VUELTA1 ;PRENDE EL LED VUELTA1
		RCALL DELAY1
		CBI PORTB, VERDE1 ;APAGA EL LED VERDE1
		CBI PORTB, VUELTA1 ;APAGA EL LED VUELTA1
		RCALL DELAY1
		SBI PORTB, VERDE1 ;PRENDE EL LED VERDE1
		SBI PORTB, VUELTA1 ;PRENDE EL LED VUELTA1
		RCALL DELAY1
		CBI PORTB, VERDE1 ;APAGA EL LED VERDE1
		CBI PORTB, VUELTA1 ;APAGA EL LED VUELTA1
		;----------------------------------------
		
		SBI PORTB, AMBAR1 ;PRENDE EL LED AMBAR1
		RCALL DELAY2
		SBI PORTB, ROJO1 ;PRENDE EL LED ROJO1
		CBI PORTB, AMBAR1	;APAGA EL LED AMBAR1
		CBI	PORTB, ROJO2 ;APAGA EL LED ROJO2
		SBI	PORTB, VERDE2 ; PRENDE EL LED VERDE2
		RCALL DELAY2
		SBI PORTB, VUELTA2 ;PRENDE EL LED VUELTA2
		RCALL DELAY1
		CBI PORTB, VUELTA2 ;APAGA EL LED VUELTA2
		RCALL DELAY1
		SBI PORTB, VUELTA2 ;PRENDE EL LED VUELTA2
		RCALL DELAY1
		CBI PORTB, VUELTA2 ;APAGA EL LED VUELTA2
		RCALL DELAY1
		
		;--------PARPADEO VERDE1: 3 SEGS----------------
		SBI PORTB, VUELTA2;PRENDE EL LED DE VUELTA2
		SBI PORTB, VERDE2 ;PRENDE EL LED VERDE2
		RCALL DELAY1
		CBI PORTB, VERDE2 ;APAGA EL LED VERDE2
		CBI PORTB, VUELTA2 ;APAGA EL LED VUELTA2
		RCALL DELAY1
		SBI PORTB, VERDE2 ;PRENDE EL LED VERDE2
		SBI PORTB, VUELTA2 ;PRENDE EL LED VUELTA2
		RCALL DELAY1
		CBI PORTB, VERDE2 ;APAGA EL LED VERDE2
		CBI PORTB, VUELTA2 ;APAGA EL LED VUELTA2
		RCALL DELAY1
		SBI PORTB, VERDE2 ;PRENDE EL LED VERDE2
		SBI PORTB, VUELTA2 ;PRENDE EL LED VUELTA2
		RCALL DELAY1
		CBI PORTB, VERDE2 ;APAGA EL LED VERDE2
		CBI PORTB, VUELTA2 ;APAGA EL LED VUELTA2
		;----------------------------------------
		SBI PORTB, AMBAR2 ;PRENDE EL LED AMBAR2
		RCALL DELAY2
		CBI PORTB, AMBAR2	;APAGA EL LED AMBAR2

DELAY1: LDI R22, $2F
		RJMP DLY1 
DLY1:	DEC R20
		BRNE DLY1
		DEC R21
		BRNE DLY1
		DEC R22
		BRNE DLY1
		RET

DELAY2: LDI R22, $5E
		RJMP DLY2 
DLY2:	DEC R20
		BRNE DLY2
		DEC R21
		BRNE DLY2
		DEC R22
		BRNE DLY2
		RET

DELAY3: LDI R22, $BC
		RJMP DLY3 
DLY3:	DEC R20
		BRNE DLY3
		DEC R21
		BRNE DLY3
		DEC R22
		BRNE DLY3
		RET
