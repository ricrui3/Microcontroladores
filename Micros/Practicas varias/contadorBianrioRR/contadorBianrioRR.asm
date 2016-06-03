;;;CONTADOR BINARIO SIN RETARDO;;;
;;;RUTINAS DE RETARDO;;;;;;;;;;;;;
;;;CALCULO DE TIEMPOS DE EJECUCUI�N;;;;

	.INCLUDE "M8535DEF.INC"		;LIBRER�A PARA EL MODELO DEL MICRO
	.CSEG		
	.ORG	$0					;DIRECCI�N DE INICIO DE MEMORIA
	RJMP	INICIO				;SALTA A LA ETIQUETA INICIO
	.ORG	$015
					
 INICIO:
	LDI		R16,	LOW(RAMEND)	;PONE EN BAJO LA ULTIMA DIRECCI�N DE LA MEMORIA RAM
	OUT		SPL,	R16			
	LDI		R16,	HIGH(RAMEND);PONE EN ALTO LA �LTIMA DIRECCI�N DE LA MEMORIA RAM
	OUT		SPL,	R16		 
	LDI		R16,	$FF			;SE LE ASIGNA EL VALOR $FF A R16 = 1111 1111 ESTO QUIERE DECIR QUE SE DEFINIRA TODO EL PUERTO B(8 BITS) COMO SALIDA
	
	OUT		DDRB,	R16			;MANDA EL VALOR DE R16 A DDRB AQU� SE DEFINEN SI LOS PUERTOS SER�N ESTRADAS = 0 O SALIDAS = 1

LOOP:
	OUT		PORTB,	R16			;MANDA EL VALOR DE R16 AL PUERTO B
	INC		R16
	RJMP	LOOP