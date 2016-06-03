
;;;;;CONTADOR BINARIO CON RETARDO 3 BUCLES;;;;;;;;;;;;;;

	.INCLUDE "M8535DEF.INC"	;;;;tiempo
							;;;;;de
							;;;ejecucíón;;;;;;
	.CSEG		
	.ORG	$0									
	RJMP	INICIO			;;;;;   2  ;;;;;;	
	.org	$015						
 INICIO:							;;;;		;;;;
	LDI		R16,	LOW(RAMEND)		;;;;	1	;;;;
	OUT		SPL,	R16				;;;;	1	;;;;
	LDI		R16,	HIGH(RAMEND)	;;;;	1	;;;;
	OUT		SPL,	R16		
	LDI		R16,	$FF				;;;;;   1  ;;;;;;	
	OUT		DDRB,R16				;;;;;   1  ;;;;;;				

LOOP:
	OUT		PORTB,	R16			
	INC		R16
DELAY:
	DEC		R20					
	BRNE	DELAY
	DEC		R21
	BRNE	DELAY
	DEC		R22
	BRNE	DELAY
	RJMP	LOOP
