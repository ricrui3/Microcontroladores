//Practica 1: Contador Binario con Retardo
//Alumno: Ricardo Ruiz Maldonado

#include <avr/io.h>

int main (void)
{	
	//--------Inicializa los valores---------
	DDRB = 0xFF;		//Inicializa PORTB como salida
	int valor = 0x00;	//Valor a mostrar en los LEDS
	//---------------------------------------
	
	while (1)
	{
		for(int counter = 0x00; counter <= 0xFF ; counter++){
			for (int counter2 = 0x00; counter2 <= 0xFF; counter2++)
			{
				for (int counter3 = 0x00; counter3 <=0xFF; counter3++)
				{
					//Los 3 ciclos "for" gastan instrucciones del mP
					//	para generar un retardo 
				}
			}
		}
		PORTB = valor;		//Muestra "valor" en el P 
		if (valor != 0xFF)	//----------------------------------
			valor++;		//    Regresa "valor" a 0x00 si 
		else                //	 	es igual a 0xFF.
			valor = 0x00;	//----------------------------------
	};
}

