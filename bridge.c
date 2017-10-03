#include "bridge.h"


void* runSemaphore(void* flag)
{
	while(1)
	{
		if(*(int*)flag == 1)
			*(int*)flag = 2;
		else// (*(int*)flag == 2)
			*(int*)flag = 1;
		//printf("semaphore flag %d\n",*(int*)flag  );
		int time = 1;
		if(flag_bridge1 == (int*)flag)     time = timeSemaphore1; 
        else if(flag_bridge2 == (int*)flag)time = timeSemaphore2;
		else if(flag_bridge3 == (int*)flag)time = timeSemaphore3;
		else 							   time = timeSemaphore4;
		//printf("tiempo delay : %d\n" ,1000000*time );
		usleep(1000000*time);
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
		if(flag_bridge1 == (int*)flag && *carrosPasados1 >= kOfficer1)
		{
			printf("Semaforo puente 1 verde de ");
			changePass(flag, carrosPasados1,sincronizacionActualSch);
			*flagSincronizacionOfficial1 = 1;
		}
        else if(flag_bridge2 == (int*)flag && *carrosPasados2 >= kOfficer2)
        {
        	printf("Semaforo puente 2 verde de ");
        	changePass(flag, carrosPasados2,sincronizacionActualSch);
        	*flagSincronizacionOfficial2 = 1;
        }
		else if(flag_bridge3 == (int*)flag && *carrosPasados3 >= kOfficer3)
		{
			printf("Semaforo puente 3 verde de ");	
			changePass(flag,carrosPasados3,sincronizacionActualSch);			
			*flagSincronizacionOfficial3 = 1;
		}
		else if(flag_bridge4== (int*)flag && *carrosPasados4 >= kOfficer4)
		{
			printf("Semaforo puente 4 verde de ");
			changePass(flag,carrosPasados4,sincronizacionActualSch);
			*flagSincronizacionOfficial4 = 1;
		}
		else
		{	
			if(listaVacia(_cola)  == 1 && listaVacia(_colaVecina) == 0 && *sincronizacionActual == 0){
				printf("Cola mia");
				mostrar_lista(_cola);
				printf("Cola vecina");
				mostrar_lista(_colaVecina);
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

