;CONTADOR BINARIO GENERANDO RETARDOS CON TIMER 0 POR ENCUESTA SE PREGUNTA HASAT QUE SE DESBORDE TIFR
;CUANDO SE DESBORDA SE TERMINA EL PROGRAMA


 

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
		SER		R16						;PONE AL REGISTRO R16 EN $FF TODOS SUS BITS
		OUT		DDRC,	R16					
		OUT		PORTB,	R16				;DA VALOR INICIAL A PUERTO B					
		LDI		R16,	$05				;SE CONFIGURA TIMER CERO CON VALOR DE 5 = 1024 (FRECUENCIA)
		OUT		TCCR0,	R16				
      		
LOOP:
		IN		R16,	TIFR			;SE LEE TIFR COMPLETO Y SE PASA A UN REGISTRO DE PROPOSITO GENERAL R16
		SBRS	R16,	0				;SE CHECA SI EL BIT 0 EST� EN 1	;
		RJMP	LOOP					;FALSO
		INC		R17						;VERDADERO
		OUT		PORTB,	R17				;SE ESCRIBE CONTEO EN PUERTO B
		LDI		R16,	$01				;SE TIENE QUE APAGAR TIFR PARA QUE SE PONGA EN CERO SE BORRA CON 1 = $01
		OUT		TIFR,	R16				;SE BORRA TIFR	
		RJMP	LOOP
				

