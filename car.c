#include <stdlib.h>



void* advance(void* car_attr)//66$$$$
{
	int pasos ;
	for (pasos = 0 ;  pasos < NUM_LEDS ; pasos++)
	{
		int velocidad = *(int*)(car_attr+4);
		int id_car = *(int*)car_attr ;
		if(velocidad == 0 || velocidad < 0) printf("%s\n","Error velocidad 0" );
		else
		{
			
			printf(" Carro  %d está en: %d avanzando a velocidad %d\n", id_car,pasos ,velocidad );
			usleep(100000/velocidad);
		}
		
	}
}