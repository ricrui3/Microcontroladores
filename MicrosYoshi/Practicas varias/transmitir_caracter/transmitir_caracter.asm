;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;PROGRAMA PARA LA TRANSMICIÓN DE UN CARACTER;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

	.include "m8535def.inc"
	.cseg		;QUE TODO LO QUE SIGUE VA A LA MEMORIA DE CÓDIGO
	.org $0		;DESDE DIRECCIÓN CERO EMPIEZA
	rjmp INICIO



INICIO: 
	LDI 	R16, 	LOW(RAMEND)		;;;
	OUT 	SPL, 	R16				;;;SE INICIALIZA EL START POINT
	LDI 	R16, 	HIGH(RAMEND)	;;;
	OUT 	SPH, 	R16				;;;

	LDI		R16,	77				;;;SE CONFIGURA LA FRECUENCIA 9600@12MHz	
	OUT 	UBRRL, 	R16				;;;

	SBI		UCSRB,	TXEN			;;;SE ENCIENDE EN MODO DE TRANSMICIÓN
				
	LDI		R16,	$41				;;;VALOR DE CARACTER 'A'
									
DATO:
	OUT		UDR,	R16				;;;SE TRANSMITE CARACTER 'A'

LOOP:
	SBIS	UCSRA,	UDRE			;;SE ESPERA EL FIN DE TRANSMICIÓN DEL CARACTER
	RJMP	LOOP			


DELAY:
	DEC 	R20
	BRNE 	DELAY
	DEC 	R21
	BRNE 	DELAY
	DEC		R22
	BRNE	DELAY
	RJMP	INICIO
