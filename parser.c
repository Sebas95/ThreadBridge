#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include "parser.h"

bool bridge1 = false;
bool bridge2 = false;
bool bridge3 = false;
bool bridge4 = false;

int GUIon;
int fisicPartON;

struct bridge *_bridge1;
struct bridge *_bridge2;
struct bridge *_bridge3;
struct bridge *_bridge4;


#define LARGO_LINEA 100

char** strSplit(char* a_str, const char a_delim)
{
    char** result    = 0;
    size_t count     = 0;
    char* tmp        = a_str;
    char* last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;

    /* contando los elementos que hay en el string */
    while (*tmp)
    {
        if (a_delim == *tmp)
        {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

    /* agregando un spacio por cada token*/
    count += last_comma < (a_str + strlen(a_str) - 1);

    /* Agregue espacio para terminar la cadena nula de modo que 
    el llamador sepa dónde termina la lista de cadenas devueltas. */
    count++;

    result = malloc(sizeof(char*) * count);

    if (result)
    {
        size_t idx  = 0;
        char* token = strtok(a_str, delim);

        while (token)
        {
            assert(idx < count);
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }
        assert(idx == count - 1);
        *(result + idx) = 0;
    }

    return result;
}

void assignedVarBridge(char line[LARGO_LINEA]){
	char** tokens;

	struct bridge *_bridgeActual = (struct bridge *) malloc (sizeof(struct bridge));
	if (bridge1)
	{
		_bridgeActual = _bridge1;
	} else if (bridge2)
	{
		_bridgeActual = _bridge2;
	} else if (bridge3)
	{
		_bridgeActual = _bridge3;
	} else if (bridge4)
	{
		_bridgeActual = _bridge4;
	}

    
	if (strncmp(line, "	schBridge", 10) == 0)
	{
		//printf(line);
		tokens = strSplit(line, ' ');
		strcpy(_bridgeActual->schBridge,*(tokens + 3));
    	//printf("1: %s\n",_bridgeActual->schBridge);
	}
	if (strncmp(line, "	timeSemaphore", 14) == 0)
	{
		//printf(line);
		tokens = strSplit(line, ' ');
		_bridgeActual->timeSemaphore = atoi(*(tokens + 2));
    	//printf("2: %d\n",_bridgeActual->timeSemaphore);
	}
	if (strncmp(line, "	kOfficer", 9) == 0)
	{
		//printf(line);
		tokens = strSplit(line, ' ');
		_bridgeActual->kOfficer = atoi(*(tokens + 2));
    	//printf("3: %d\n",_bridgeActual->kOfficer);
	}
	if (strncmp(line, "	schThreads", 11) == 0)
	{
		//printf(line);
		tokens = strSplit(line, ' ');
		strcpy(_bridgeActual->schThreads,*(tokens + 3));
    	//printf("4: %s\n",_bridgeActual->schThreads);
	}
	if (strncmp(line, "	largeBridge", 12) == 0)
	{
		//printf(line);
		tokens = strSplit(line, ' ');
		_bridgeActual->largeBridge = atoi(*(tokens + 2));
    	//printf("5: %d\n",_bridgeActual->largeBridge);
	}
	if (strncmp(line, "	mediaExponential", 17) == 0)
	{
		//printf(line);
		tokens = strSplit(line, ' ');
		_bridgeActual->mediaExponential = atoi(*(tokens + 2));
    	//printf("6: %d\n",_bridgeActual->mediaExponential);
	}
	if (strncmp(line, "	averageSpeed", 13) == 0)
	{
		//printf(line);
		tokens = strSplit(line, ' ');
		_bridgeActual->averageSpeed = atoi(*(tokens + 2));
    	//printf("7: %d\n",_bridgeActual->averageSpeed);
	}
	if (strncmp(line, "	procAmbulances", 15) == 0)
	{
		//printf(line);
		tokens = strSplit(line, ' ');
		_bridgeActual->procAmbulances = atoi(*(tokens + 2));
    	//printf("8: %d\n",_bridgeActual->procAmbulances);
	}
	if (strncmp(line, "	procRadioactive", 16) == 0)
	{
		//printf(line);
		tokens = strSplit(line, ' ');
		_bridgeActual->procRadioactive = atoi(*(tokens + 2));
    	//printf("9: %d\n",_bridgeActual->procRadioactive);
	}
	//printf("1: %s\n",_bridgeActual->schBridge);
}

void assignedSpace(){
	_bridge1 = (struct bridge *) malloc (sizeof(struct bridge));
	_bridge2 = (struct bridge *) malloc (sizeof(struct bridge));
	_bridge3 = (struct bridge *) malloc (sizeof(struct bridge));
	_bridge4 = (struct bridge *) malloc (sizeof(struct bridge));
}

void chooseBridge(char line[LARGO_LINEA]){
	//printf("cambio de linea%s\n");       line == "bridge1 ="
	char** tokens;
	if (strncmp(line, "bridge1 =", 9) == 0 || bridge1 == true)
	{	
		bridge1 = true;
	}
	else if (strncmp(line, "bridge2 =", 9) == 0 || bridge2 == true)
	{
		bridge2 = true;
	}
	else if (strncmp(line, "bridge3 =", 9) == 0 || bridge3 == true)
	{
		bridge3 = true;
	}
	else if (strncmp(line, "bridge4 =", 9) == 0 || bridge4 == true)
	{
		bridge4 = true;		
	}
	

	else if (strncmp(line, "GUIon :", 7) == 0)
	{
		tokens = strSplit(line, ' ');
		GUIon = atoi(*(tokens + 2));
    	//printf("Gui encendida: %d\n",GUIon);
	}
	else if (strncmp(line, "fisicPartON :", 13) == 0)
	{
		tokens = strSplit(line, ' ');
		fisicPartON = atoi(*(tokens + 2));
    	//printf("parte fisica encendida: %d\n",fisicPartON);
	}

	if (bridge1 | bridge2 | bridge3 | bridge4)
	{
		assignedVarBridge(line);
	} 

	if(strncmp(line, "},", 2) == 0){
		//printf("\n");
		bridge1 =false;
		bridge2 =false;
		bridge3 =false;
		bridge4 =false;
	}
}


void getDataConfig(){
	FILE *archivo;
 	
 	char caracteres[LARGO_LINEA];
 	
 	archivo = fopen("configuracion.txt","r+");
 	
 	if (archivo == NULL)
 		exit(1);
 	
 	assignedSpace();
 	//printf("\nEl contenido del archivo de prueba es \n\n");
 	while (feof(archivo) == 0)
 	{
 		fgets(caracteres,LARGO_LINEA,archivo);

 		//printf("%s",caracteres);
 		chooseBridge(caracteres);
 	}

    fclose(archivo);
}


Bridge getVarBridge(int bridge){
	if (bridge==1)
	{
		return  _bridge1;
	}
	else if (bridge==2)
	{
		return  _bridge2;
	}
	else if (bridge==3)
	{
		return  _bridge3;
	}
	else if (bridge==4)
	{
		return  _bridge4;
	} 
	else{
		return NULL;
	}
}

int getGuiOn(){
	return GUIon;
}

int getFisicOn(){
	return fisicPartON;
}