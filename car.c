#include <stdlib.h>
#include "car.h"

int* datosGUI1;
int* datosGUI2;
int* datosGUI3;
int* datosGUI4;

/*
* datosGUI1[0]: type_car
* datosGUI1[1]: id_cola
* datosGUI1[2]: pasos 
*/

/*
* Fucion que moviliza los carros 
* Recibe un arreglo de 4 int
* car_attr[0] = id_car
* car_attr[1] = velocidad
* car_attr[2] = id_cola
* car_attr[3] = numero de puente en el que esta {1,2,3,4}
*/

void* advance(void* car_attr)
{
	int* attr = (int*)car_attr;
	int id_car = attr[0];
	int velocidad = attr[1];
	int id_cola = attr[2]; // ARREGLAR AQUI, UNUSED VARIABLE
	int id_puente = attr[3];
	//type_car_global= attr[4];
	
	//DEFINE BRIDGES FLAGS

	

	if(id_puente == 1)
	{
		*bridge_1_in_use = 1;
		datosGUI1[0] = attr[4];
		datosGUI1[1] = id_cola;
	}
	if(id_puente == 2)
	{
		*bridge_2_in_use = 1;
		datosGUI2[0] = attr[4];
		datosGUI2[1] = id_cola;
	}
	if(id_puente == 3)
	{
		*bridge_3_in_use = 1;
		datosGUI3[0] = attr[4];
		datosGUI3[1] = id_cola;
	} 
	if(id_puente == 4)
	{
		*bridge_4_in_use = 1;
		datosGUI4[0] = attr[4];
		datosGUI4[1] = id_cola;
	}
	int pasos;
	for (pasos = 0 ;  pasos < NUM_LEDS ; pasos++)
	{
		if(id_puente == 1) datosGUI1[2] = pasos; 
		if(id_puente == 2) datosGUI2[2] = pasos;
		if(id_puente == 3) datosGUI3[2] = pasos;
		if(id_puente == 4) datosGUI4[2] = pasos;
		if(velocidad == 0 || velocidad < 0) printf("%s\n","Error velocidad 0" );
		else
		{

			printf(" Carro  %d está en: %d avanzando a velocidad %d puente %d\n", id_car,pasos ,velocidad, id_puente );
			usleep(1000000/velocidad);
		}
		
	}
	if(id_puente == 1) *bridge_1_in_use = 0; 
	if(id_puente == 2) *bridge_2_in_use = 0;
	if(id_puente == 3) *bridge_3_in_use = 0;
	if(id_puente == 4) *bridge_4_in_use = 0;
	return 0;
}

int* getDataBridge(int bridge)
{
	printf("LLego\n");
	int* salida = (int*)malloc(4*sizeof(int));

	if(bridge == 1) salida = datosGUI1; 
	if(bridge == 2) salida = datosGUI2;
	if(bridge == 3) salida = datosGUI3;
	if(bridge == 4) salida = datosGUI4;

	return salida;
}