#include "bridge.h"

void forceSignal(int * flag, int id_cola)
{
	int auxDirection = 0;
	if((id_cola == 11) | (id_cola == 21) | (id_cola == 31) | (id_cola == 41)) auxDirection = 1;
	else auxDirection = 2;
	printf("----------------------------------------");
	if(flag_bridge1      == (int*)flag)
	{
		*flag = auxDirection;
		forceBridge[0] = 1;
		printf("Puente 1 Bloqueado\n");
	}
	else if(flag_bridge2 == (int*)flag)
	{
		*flag = auxDirection;
		forceBridge[1] = 1;
		printf("Puente 2 Bloqueado\n");
	}
	else if(flag_bridge3 == (int*)flag)
	{
		*flag = auxDirection;
		forceBridge[2] = 1;
		printf("Puente 3 Bloqueado\n");
	}
	else
	{
		*flag = auxDirection;
		forceBridge[3] = 1;
		printf("Puente 4 Bloqueado\n");
	}

}

int* getLockedBridge(void* flag)
{
	int* flagAux = (int*)malloc(sizeof(int));
	if(flag_bridge1 == (int*)flag)
	{
		 *flagAux = forceBridge[0];
	}
	else if(flag_bridge2 == (int*)flag)
	{
		*flagAux = forceBridge[1];
	}
	else if(flag_bridge3 == (int*)flag)
	{
		*flagAux = forceBridge[2];
	}
	else
	{
		*flagAux = forceBridge[3];
	}
	return flagAux;

}


void* runSemaphore(void* flag)
{
	while(1)
	{
		short indexBridge = 0;
		int time = 1;
		if(flag_bridge1 == (int*)flag)
		{
			 time = timeSemaphore1;
			 indexBridge = 1;
		}
		else if(flag_bridge2 == (int*)flag)
		{
			time = timeSemaphore2;
			indexBridge = 2;
		}
		else if(flag_bridge3 == (int*)flag)
		{
			time = timeSemaphore3;
			indexBridge = 3;
		}
		else
		{
			time = timeSemaphore4;
			indexBridge = 4;
		}
		short locked = forceBridge[indexBridge - 1];
		if(locked == 0)
		{
			if(*(int*)flag == 1)
				*(int*)flag = 2;
			else// (*(int*)flag == 2)
				*(int*)flag = 1;
			//printf("semaphore flag %d\n",*(int*)flag  );

			//printf("tiempo delay : %d\n" ,1000000*time );
			usleep(SECOND*time);
		}
	}

}


void* runOfficer(void* flag)
{
	Cola _cola = (Cola)malloc(sizeof(struct cola));
	Cola _colaVecina = (Cola)malloc(sizeof(struct cola));
	int* actualCarK = (int*)malloc(sizeof(int));
	int* sincronizacionActual = (int*)malloc(sizeof(int));
	int* sincronizacionActualSch = (int*)malloc(sizeof(int));
	while(1)
	{
		actualCarK = getActualCarPassedByFlag(flag);
		_cola = getCola(flag);
		_colaVecina = getColaVecina(_cola);
		sincronizacionActualSch = getActualSincronizacionOfficialSch(flag);
		sincronizacionActual = getActualSincronizacionOfficial(flag);
		int* lockedBridgeActual = (int*)malloc(sizeof(int));
		lockedBridgeActual = getLockedBridge(flag);
		if(*lockedBridgeActual == 0) //If not blocked
		{
				if(flag_bridge1 == (int*)flag && *carrosPasados1 >= kOfficer1)
				{
					printf("Official puente 1 paso de ");
					changePass(flag, carrosPasados1,sincronizacionActualSch);
					*flagSincronizacionOfficial1 = 1;
				}
		    else if(flag_bridge2 == (int*)flag && *carrosPasados2 >= kOfficer2)
		    {
		    	printf("Official puente 2 paso de ");
		    	changePass(flag, carrosPasados2,sincronizacionActualSch);
		    	*flagSincronizacionOfficial2 = 1;
		    }
				else if(flag_bridge3 == (int*)flag && *carrosPasados3 >= kOfficer3)
				{
					printf("Official puente 3 paso de ");
					changePass(flag,carrosPasados3,sincronizacionActualSch);
					*flagSincronizacionOfficial3 = 1;
				}
				else if(flag_bridge4== (int*)flag && *carrosPasados4 >= kOfficer4)
				{
					printf("Official puente 4 paso de ");
					changePass(flag,carrosPasados4,sincronizacionActualSch);
					*flagSincronizacionOfficial4 = 1;
				}
				else
				{
					if(listaVacia(_cola)  == 1 && listaVacia(_colaVecina) == 0 && *sincronizacionActual == 0){
						//printf("Cola mia");

						mostrar_lista(_cola);
						printf("\n");
						//printf("Cola vecina");
						mostrar_lista(_colaVecina);
						printf("\n");
						changePass(flag,actualCarK,sincronizacionActualSch);
					}
					else{
						if(*sincronizacionActualSch == 1)
							*sincronizacionActualSch = 0;
						else
							usleep(1);
					}
				}
		}
		else
		{//If blocked
			usleep(1);
			//*sincronizacionActualSch = 0;
			//int bridgeForPrint = getNumberBridgeActual(flag);
			//if(bridgeForPrint == 1)	printf("Puente 1 bloqueado\n");
			//if(bridgeForPrint == 2)	printf("Puente 2 bloqueado\n");
			//if(bridgeForPrint == 3)	printf("Puente 3 bloqueado\n");
			//if(bridgeForPrint == 4)	printf("Puente 4 bloqueado\n");
		}

	}
}

int getNumberBridgeActual(void* flag)
{
	int* flagAux = (int*)malloc(sizeof(int));
	if(flag_bridge1 == (int*)flag)
	{
		 *flagAux = 1;
	}
	else if(flag_bridge2 == (int*)flag)
	{
		*flagAux = 2;
	}
	else if(flag_bridge3 == (int*)flag)
	{
		*flagAux = 3;
	}
	else
	{
		*flagAux = 4;
	}
	return *flagAux;
}

void changePass(void* flag, int* carrosPasados,int* sincSch){
	if(*(int*)flag == 1){
		*(int*)flag = 2;
		*carrosPasados = 0;
		printf("De dereecha a izquierda\n");
	}
	else{// (*(int*)flag == 2)
		*(int*)flag = 1;
		*carrosPasados = 0;
		printf("De izquierda a derechas\n");
	}
	*sincSch = 0;
}


Cola getCola(void* flag){

	if(flag_bridge1 == (int*)flag)
	{
		if(*(int*) flag == 1) return cola11;
		else return cola12;
	}
    else if(flag_bridge2 == (int*)flag)
    {
    	if(*(int*) flag == 1) return cola21;
		else return cola22;
    }
	else if(flag_bridge3 == (int*)flag)
	{
		if(*(int*) flag == 1) return cola31;
		else return cola32;
	}
	else if(flag_bridge4== (int*)flag)
	{
		if(*(int*) flag == 1) return cola41;
		else return cola42;
	}
	else
	{
		return cola42;
	}

}


Cola getColaVecina(Cola cola){

	if     (cola == cola11) return cola12;
    else if(cola == cola12) return cola11;
	else if(cola == cola22) return cola21;
	else if(cola == cola21) return cola22;
	else if(cola == cola31) return cola32;
    else if(cola == cola32) return cola31;
	else if(cola == cola41) return cola42;
	else                    return cola41;
}





int* getActualCarPassed(int numberBridge){
	if     (numberBridge == 1) return carrosPasados1;
	else if(numberBridge == 2) return carrosPasados2;
	else if(numberBridge == 3) return carrosPasados3;
	else return carrosPasados4;
}

int* getActualCarPassedByFlag(void* flag){
	if     ((int*)flag == flag_bridge1) return carrosPasados1;
	else if((int*)flag == flag_bridge2) return carrosPasados2;
	else if((int*)flag == flag_bridge3) return carrosPasados3;
	else return carrosPasados4;
}


int* getActualSincronizacionOfficial(void* flag){
	if     ((int*)flag == flag_bridge1) return flagSincronizacionOfficial1;
	else if((int*)flag == flag_bridge2) return flagSincronizacionOfficial2;
	else if((int*)flag == flag_bridge3) return flagSincronizacionOfficial3;
	else return flagSincronizacionOfficial4;
}


int* getActualSincronizacionOfficialSch(void* flag){
	if     ((int*)flag == flag_bridge1) return flagSincronizacionOfficialScheduler1;
	else if((int*)flag == flag_bridge2) return flagSincronizacionOfficialScheduler2;
	else if((int*)flag == flag_bridge3) return flagSincronizacionOfficialScheduler3;
	else return flagSincronizacionOfficialScheduler4;
}


void* runJungleLaw(void* flag)
{
	while(1)
	{

		if(*(int*)flag == 1)
			*(int*)flag = 2;
		else if(*(int*)flag == 2)
			*(int*)flag = 1;
		//printf("jungleLaw flag in %d\n",*(int*)flag  );
		usleep(1000000);

	}
}
