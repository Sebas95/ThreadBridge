#include <stdlib.h>
#include "car.h"


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
* car_attr[4] = type of car
* car_attr[5] = bridge control
* car_attr[6] = bridge length
*/

void* advance(void* car_attr)
{
	int* attr = (int*)car_attr;
	int id_car = attr[0];
	int velocidad = attr[1];
	int id_cola = attr[2]; // ARREGLAR AQUI, UNUSED VARIABLE
	int id_puente = attr[3];
	int type_scheduler = attr[5];
	int bridge_length = attr[6] ;
	char carName[9];
	int type_car = attr[4];

	if(type_car == RADIOACTIVE) strcpy(carName,"Radioactivo");
	else if(type_car == AMBULANCE) strcpy(carName,"Ambulancia");
	else if(type_car == NORMAL) strcpy(carName,"Normal");

	int* carroPasadoAux = (int*)malloc(sizeof(int));
	int* sincronizacion = (int*)malloc(sizeof(int));
	int* sincronizacionSch = (int*)malloc(sizeof(int));
	//type_car_global= attr[4];



	if(id_puente == 1)
	{
		*bridge_1_in_use = 1;
		datosGUI1[0] = attr[4];
		datosGUI1[1] = id_cola;
		carroPasadoAux = carrosPasados1;
		sincronizacion = flagSincronizacionOfficial1;
		sincronizacionSch = flagSincronizacionOfficialScheduler1;
	}
	if(id_puente == 2)
	{
		*bridge_2_in_use = 1;
		datosGUI2[0] = attr[4];
		datosGUI2[1] = id_cola;
		carroPasadoAux = carrosPasados2;
		sincronizacion = flagSincronizacionOfficial2;
		sincronizacionSch = flagSincronizacionOfficialScheduler2;

	}
	if(id_puente == 3)
	{
		*bridge_3_in_use = 1;
		datosGUI3[0] = attr[4];
		datosGUI3[1] = id_cola;
		carroPasadoAux = carrosPasados3;
		sincronizacion = flagSincronizacionOfficial3;
		sincronizacionSch = flagSincronizacionOfficialScheduler3;
	}
	if(id_puente == 4)
	{
		*bridge_4_in_use = 1;
		datosGUI4[0] = attr[4];
		datosGUI4[1] = id_cola;
		carroPasadoAux = carrosPasados4;
		sincronizacion = flagSincronizacionOfficial4;
		sincronizacionSch = flagSincronizacionOfficialScheduler4;
	}
	int pasos;
	for (pasos = 0 ;  pasos < bridge_length ; pasos++)
	{
		if(id_puente == 1) {datosGUI1[2] = pasos; forceBridge[0] = 0;}
		if(id_puente == 2) {datosGUI2[2] = pasos; forceBridge[1] = 0;}
		if(id_puente == 3) {datosGUI3[2] = pasos; forceBridge[3] = 0;}
		if(id_puente == 4) {datosGUI4[2] = pasos; forceBridge[4] = 0;}
		if(velocidad == 0 || velocidad < 0) printf("%s\n","Error velocidad 0" );
		else
		{

			printf(" Carro  %d está en: %d avanzando a velocidad %d puente %d tipo: %d %s \n", id_car,pasos ,velocidad, id_puente ,attr[4],carName);
			usleep(SECOND/velocidad);
		}

	}

	if(type_scheduler == Official)
	{
		*sincronizacionSch = 1;
		*carroPasadoAux = *carroPasadoAux + 1 ;
		*sincronizacion = 0;
	}

	if(id_puente == 1) *bridge_1_in_use = 0;
	if(id_puente == 2) *bridge_2_in_use = 0;
	if(id_puente == 3) *bridge_3_in_use = 0;
	if(id_puente == 4) *bridge_4_in_use = 0;
	return 0;
}

int* getDataBridge(int bridge)
{
	int* salida = (int*)malloc(4*sizeof(int));

	if(bridge == 1) salida = datosGUI1;
	if(bridge == 2) salida = datosGUI2;
	if(bridge == 3) salida = datosGUI3;
	if(bridge == 4) salida = datosGUI4;

	return salida;
}
