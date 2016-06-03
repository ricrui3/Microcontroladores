

	.INCLUDE "M8535DEF.INC"	
									;;;;;tiempo;;;;;	
									;;;;;;;de;;;;;;;
									;;ejecución;;;;;
	.CSEG							;;;;		;;;;
	.ORG	$0						;;;;		;;;;
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
DELAY:								;;;;		;;;;
	DEC		R20						;;;;(1+2)*255;;;					
	BRNE	DELAY					;;;;	1+1	;;;;
	RJMP	LOOP					;;;;	2	;;;;
									;;;;;;;;;;;;;;;;

;;tiempo de ejecución = 779 ciclos
;;; 779/ 12 Megas
;;Tej= 64.91 Microsegundos
