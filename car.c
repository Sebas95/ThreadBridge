#include <stdlib.h>


/*
* Fucion que moviliza los carros 
* Recibe un arreglo de 4 int
* car_attr[0] = id_car
* car_attr[1] = velocidad
* car_attr[2] = izquiera= 1 | derecha = 0
* car_attr[3] = numero de puente en el que esta {1,2,3,4}
*/

void* advance(void* car_attr)//66$$$$$$$$$$$$$$$$$$
{
	int id_car = (int)car_attr[0];
	int velocidad = (int)car_attr[1];
	int izquierda = (int)car_attr[2];
	int id_puente = (int)car_attr[3];
	int* flag_bridge1;

	if(id_puente == 1) *bridge_1_in_use = 1; 
	if(id_puente == 2) *bridge_2_in_use = 1;
	if(id_puente == 3) *bridge_3_in_use = 1;
	if(id_puente == 4) *bridge_4_in_use = 1;
	int pasos;
	for (pasos = 0 ;  pasos < NUM_LEDS ; pasos++)
	{
		
		if(velocidad == 0 || velocidad < 0) printf("%s\n","Error velocidad 0" );
		else
		{

			printf(" Carro  %d está en: %d avanzando a velocidad %d\n puente %d\n ", id_car,pasos ,velocidad, id_puente );
			usleep(100000/velocidad);
		}
		
	}
	if(id_puente == 1) *bridge_1_in_use = 0; 
	if(id_puente == 2) *bridge_2_in_use = 0;
	if(id_puente == 3) *bridge_3_in_use = 0;
	if(id_puente == 4) *bridge_4_in_use = 0;

}