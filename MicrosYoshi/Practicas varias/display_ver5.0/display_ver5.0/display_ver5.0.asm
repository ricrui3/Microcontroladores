/*
 * display_ver5.asm
 *
 *  Created: 24/02/2014 02:09:46 p.m.
 *   Author: edescom
 */ 


 

 

		.INCLUDE	"M8535DEF.INC"
                 
        .CSEG		
        .ORG	$0					
      	RJMP	INICIO				
                 	.ORG	$015				
INICIO:
      	LDI		R16,	LOW(RAMEND)	
     	OUT		SPL,	R16			
     	LDI		R16,	HIGH(RAMEND)
      	OUT		SPL,	R16		 
      	LDI		R16,	$FF			
      	OUT		DDRB,	R16		
      		
LOOP:
		LDI		R16,	$73	
		OUT		PORTB,	R16	
		RCALL	DELAY
		LDI		R16,	$3F
		OUT		PORTB,	R16	
		RCALL	DELAY
		LDI		R16,	$38
		OUT		PORTB,	R16	
		RCALL	DELAY
		LDI		R16,	$06
		OUT		PORTB,	R16	
		RCALL	DELAY
		RJMP	LOOP
				
DELAY:
     	DEC		R20					
    	BRNE	DELAY
    	DEC		R21					
     	BRNE	DELAY				
      	RET						
