; Author : Ricardo Ruiz Maldonado
; Practica 17  - Conversion 1 canal Free run a LEDS y por UART

		.INCLUDE"M8535DEF.INC"
		.CSEG
		.ORG $000
		RJMP INICIO		;salta tabla de vectores de interrupcion
		.ORG $015
INICIO:	LDI R16,LOW(RAMEND)  ;------------------------
		OUT SPL,R16			 ;    INICIALIZAMOS EL 
		LDI R16,HIGH(RAMEND) ;	 STACK POINTER
		OUT SPH,R16			 ;------------------------	
		SER R16				 ;Configuramos puerto B
		OUT DDRB,R16		 ;	como salida

		LDI R16,77			 ;Configuracion baud-rate
		OUT UBRRL,R16		 ;	9600
		
		LDI R16,$20			 ;CONFIGURA PARA CARGAR A LA
							 ;	IZQUIERDA
		OUT ADMUX,R16		 ;	Entrada ADC0

		LDI R16,$A6			 ;HABILITA EL ADC Y EL AUTODISPARO
		OUT ADCSRA,R16		 ;fACTOR DE DIVISION DE 64
BACK:	SBI ADCSRA,6		 ;INICIA LA CONVERSION
LOOP:	SBIS ADCSRA,4		 ;ESPERA A QUE TERMINE LA CONVERSION
		RJMP LOOP 			 ;
		IN R17,ADCL			 ;LEE LOS 2 ULTIMOS BITS DE LA 
							 ;	CONVERSION
		IN R18,ADCH			 ;LEE LOS PRIMEROS 8 BITS DE LA
							 ;	CONVERSION
		SBI UCSRB,TXEN	     ;HABILITA EL MODO TRANSMISION

ENVIA:	OUT UDR,R18			 ;Cargo registro de datos UDR
							 ;	CON LOS PRIMEROS 8 BITS
							 ;	DE LA CONVERSION
LOOP2:	SBIS UCSRA,UDRE	  	 ;Espera fin de transmision
		RJMP LOOP2			 ; 	SIGUE ESPERANDO
		OUT PORTB,R18		 ;MUESTRA EL VALOR DE LOS PRIMEROS
							 ;	8 BITS EN EL PUERTO B (LEDS)

		ldi		r22,$02		 ;
DELAY:	dec		r20			 ;
		brne	DELAY		 ;
		dec		r21			 ; ESTO ES UN DELAY
		brne	DELAY		 ;
		dec		r22			 ;
		brne	DELAY		 ;
		RJMP BACK			