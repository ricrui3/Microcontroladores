
;;;;;CONTADOR BINARIO CON RETARDO DE 2 BUCLES;;;;;;;;;;;;;;;


	.INCLUDE "M8535DEF.INC"			;;tiempo;;;;;;;;	
	.CSEG							;;;;;;;de;;;;;;;
	.ORG	$0						;;ejecución;;;;;								
	RJMP	INICIO					;;;;	2	;;;;
	.ORG	$015					;;;;		;;;;
									;;;;		;;;;	
 INICIO:							;;;;		;;;;
	LDI		R16,	LOW(RAMEND)		;;;;	1	;;;;
	OUT		SPL,	R16				;;;;	1	;;;;
	LDI		R16,	HIGH(RAMEND)	;;;;	1	;;;;
	OUT		SPL,	R16				;;;;	1	;;;;	
	LDI		R16,	$FF				;;;;	1	;;;;
	OUT		DDRB,R16				;;;;	1	;;;;
									;;;;		;;;;
LOOP:								;;;;		;;;;
	OUT		PORTB,	R16				;;;;	1	;;;;
	INC		R16						;;;;	1	;;;;
DELAY:								;;;;		;;;;;;;;;;;;;;;;
	DEC		R20						;[(1+2)*255+1+1+1+2]*255;;;;
	BRNE	DELAY					;;;;		;;;;;;;;;;;;;;;;
	DEC		R21						;(1+2)*255+1+1+1+2;;;;;;;;;;
	BRNE	DELAY					;;;;		;;;;;;;;;;;;;;;;
	RJMP	LOOP					;;;;	2	;;;;
									;;;;;;;;;;;;;;;;



