#include "bridge.h"

int estado1 = 0;
int estado2 = 0;
int estado3 = 0;
int estado4 = 0;

int getSemaphore()
{
	return 1;
}

int getOfficer()
{
	return 1;
}

int getJungleLaw()
{
	return 1;
}

void initBridge(int number_bridge, int type_bridge) // CAMBIAR
{
	int estado;
	if (type_bridge == 10)
	{
		estado = getOfficer();
	} else if (type_bridge == 11)
	{
		estado = getJungleLaw();
	} else if (type_bridge == 12)
	{
		estado = getSemaphore();
	}
}

int getEstadoBridge(int number_bridge)
{
	int estado_result;
	if (number_bridge == 1)
	{
		estado_result = estado1;
	} else if (number_bridge == 2)
	{
		estado_result = estado2;
	} else if (number_bridge == 3)
	{
		estado_result = estado3;
	} else if (number_bridge == 4)
	{
		estado_result = estado4;
	}	
	return estado_result;
}