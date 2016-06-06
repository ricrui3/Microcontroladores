; Author : Ricardo Ruiz Maldonado
; Practica 4: PWM C/Timer2 (Minidip)
		.INCLUDE	"M8535DEF.INC"              
        .CSEG		
        .ORG	$0					
      	RJMP	INICIO		;SALTA VECTORES DE INTERRUPCIÓN			
        .ORG	$015				

INICIO:	LDI		R16,	LOW(RAMEND)	 ;------------------------
     	OUT		SPL,	R16			 ;    INICIALIZAMOS EL 
     	LDI		R16,	HIGH(RAMEND) ;	 STACK POINTER
      	OUT		SPH,	R16			 ;------------------------ 
      	LDI		R16, 	$80
		OUT		DDRD,	R16		;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
		SER		R16	    		;R16 <- $FF
      	OUT		PORTA,	R16	    ;ACTIVA PULL-UP EN PUERTO A
		OUT		DDRB,	R16		;CONFIGURA PUERTO B COMO SALIDA
		LDI		R16,	$62		;SE HABILITA MODO PWM EN TIMER2
		OUT		TCCR2,	R16		;;;;;;;;;;;;;;;
			
LOOP:	IN		R16,	PINA	;;SE LEE DATO DEL MINIDIP DEL PUERTO A
		OUT		PORTB,	R16		;;SE ESCRIBE DATO EN LOS LEDS
		OUT		OCR2,	R16		;;ESCRIBO FACTOR DE MODULACIÓN PARA PWM
								;;OCR2 COMPARADOR 	
		RJMP	LOOP
