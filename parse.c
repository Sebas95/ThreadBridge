#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

bool bridge1 = false;
bool bridge2 = false;
bool bridge3 = false;
bool bridge4 = false;

int GUIon;
int fisicPartON;

char schBridge1 [50];
int timeSemaphore1;
int kOfficer1;
char schThreads1 [50];
int largeBridge1;
int mediaExponential1;
int averageSpeed1;
int procAmbulances1;
int procRadioactive1;

char schBridge2 [50];
int timeSemaphore2;
int kOfficer2;
char schThreads2 [50];
int largeBridge2;
int mediaExponential2;
int averageSpeed2;
int procAmbulances2;
int procRadioactive2;

char schBridge3 [50];
int timeSemaphore3;
int kOfficer3;
char schThreads3 [50];
int largeBridge3;
int mediaExponential3;
int averageSpeed3;
int procAmbulances3;
int procRadioactive3;

char schBridge4 [50];
int timeSemaphore4;
int kOfficer4;
char schThreads4 [50];
int largeBridge4;
int mediaExponential4;
int averageSpeed4;
int procAmbulances4;
int procRadioactive4;

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

void asignedVarBridge1(char line[100]){
	char** tokens;

    
	if (strncmp(line, "	schBridge", 10) == 0)
	{
		//printf(line);
		tokens = strSplit(line, ' ');
		strcpy(schBridge1,*(tokens + 3));
    	printf("1: %s\n",schBridge1);
	}
	if (strncmp(line, "	timeSemaphore", 14) == 0)
	{
		//printf(line);
		tokens = strSplit(line, ' ');
		timeSemaphore1 = atoi(*(tokens + 2));
    	printf("2: %d\n",timeSemaphore1);
	}
	if (strncmp(line, "	kOfficer", 9) == 0)
	{
		//printf(line);
		tokens = strSplit(line, ' ');
		kOfficer1 = atoi(*(tokens + 2));
    	printf("3: %d\n",kOfficer1);
	}
	if (strncmp(line, "	schThreads", 11) == 0)
	{
		//printf(line);
		tokens = strSplit(line, ' ');
		strcpy(schThreads1,*(tokens + 3));
    	printf("4: %s\n",schThreads1);
	}
	if (strncmp(line, "	largeBridge", 12) == 0)
	{
		//printf(line);
		tokens = strSplit(line, ' ');
		largeBridge1 = atoi(*(tokens + 2));
    	printf("5: %d\n",largeBridge1);
	}
	if (strncmp(line, "	mediaExponential", 17) == 0)
	{
		//printf(line);
		tokens = strSplit(line, ' ');
		mediaExponential1 = atoi(*(tokens + 2));
    	printf("6: %d\n",mediaExponential1);
	}
	if (strncmp(line, "	averageSpeed", 13) == 0)
	{
		//printf(line);
		tokens = strSplit(line, ' ');
		averageSpeed1 = atoi(*(tokens + 2));
    	printf("7: %d\n",averageSpeed1);
	}
	if (strncmp(line, "	procAmbulances", 15) == 0)
	{
		//printf(line);
		tokens = strSplit(line, ' ');
		procAmbulances1 = atoi(*(tokens + 2));
    	printf("8: %d\n",procAmbulances1);
	}
	if (strncmp(line, "	procRadioactive", 16) == 0)
	{
		//printf(line);
		tokens = strSplit(line, ' ');
		procRadioactive1 = atoi(*(tokens + 2));
    	printf("9: %d\n",procRadioactive1);
	}
}

void asignedVarBridge2(char line[100]){
	char** tokens;

    
	if (strncmp(line, "	schBridge", 10) == 0)
	{
		//printf(line);
		tokens = strSplit(line, ' ');
		strcpy(schBridge2,*(tokens + 3));
    	printf("1: %s\n",schBridge2);
	}
	if (strncmp(line, "	timeSemaphore", 14) == 0)
	{
		//printf(line);
		tokens = strSplit(line, ' ');
		timeSemaphore2 = atoi(*(tokens + 2));
    	printf("2: %d\n",timeSemaphore2);
	}
	if (strncmp(line, "	kOfficer", 9) == 0)
	{
		//printf(line);
		tokens = strSplit(line, ' ');
		kOfficer2 = atoi(*(tokens + 2));
    	printf("3: %d\n",kOfficer2);
	}
	if (strncmp(line, "	schThreads", 11) == 0)
	{
		//printf(line);
		tokens = strSplit(line, ' ');
		strcpy(schThreads2,*(tokens + 3));
    	printf("4: %s\n",schThreads2);
	}
	if (strncmp(line, "	largeBridge", 12) == 0)
	{
		//printf(line);
		tokens = strSplit(line, ' ');
		largeBridge2 = atoi(*(tokens + 2));
    	printf("5: %d\n",largeBridge2);
	}
	if (strncmp(line, "	mediaExponential", 17) == 0)
	{
		//printf(line);
		tokens = strSplit(line, ' ');
		mediaExponential2 = atoi(*(tokens + 2));
    	printf("6: %d\n",mediaExponential2);
	}
	if (strncmp(line, "	averageSpeed", 13) == 0)
	{
		//printf(line);
		tokens = strSplit(line, ' ');
		averageSpeed2 = atoi(*(tokens + 2));
    	printf("7: %d\n",averageSpeed2);
	}
	if (strncmp(line, "	procAmbulances", 15) == 0)
	{
		//printf(line);
		tokens = strSplit(line, ' ');
		procAmbulances2 = atoi(*(tokens + 2));
    	printf("8: %d\n",procAmbulances2);
	}
	if (strncmp(line, "	procRadioactive", 16) == 0)
	{
		//printf(line);
		tokens = strSplit(line, ' ');
		procRadioactive2 = atoi(*(tokens + 2));
    	printf("9: %d\n",procRadioactive2);
	}
}

void asignedVarBridge3(char line[100]){
	char** tokens;

    
	if (strncmp(line, "	schBridge", 10) == 0)
	{
		//printf(line);
		tokens = strSplit(line, ' ');
		strcpy(schBridge3,*(tokens + 3));
    	printf("1: %s\n",schBridge3);
	}
	if (strncmp(line, "	timeSemaphore", 14) == 0)
	{
		//printf(line);
		tokens = strSplit(line, ' ');
		timeSemaphore3 = atoi(*(tokens + 2));
    	printf("2: %d\n",timeSemaphore3);
	}
	if (strncmp(line, "	kOfficer", 9) == 0)
	{
		//printf(line);
		tokens = strSplit(line, ' ');
		kOfficer3 = atoi(*(tokens + 2));
    	printf("3: %d\n",kOfficer3);
	}
	if (strncmp(line, "	schThreads", 11) == 0)
	{
		//printf(line);
		tokens = strSplit(line, ' ');
		strcpy(schThreads3,*(tokens + 3));
    	printf("4: %s\n",schThreads3);
	}
	if (strncmp(line, "	largeBridge", 12) == 0)
	{
		//printf(line);
		tokens = strSplit(line, ' ');
		largeBridge3 = atoi(*(tokens + 2));
    	printf("5: %d\n",largeBridge3);
	}
	if (strncmp(line, "	mediaExponential", 17) == 0)
	{
		//printf(line);
		tokens = strSplit(line, ' ');
		mediaExponential3 = atoi(*(tokens + 2));
    	printf("6: %d\n",mediaExponential3);
	}
	if (strncmp(line, "	averageSpeed", 13) == 0)
	{
		//printf(line);
		tokens = strSplit(line, ' ');
		averageSpeed3 = atoi(*(tokens + 2));
    	printf("7: %d\n",averageSpeed3);
	}
	if (strncmp(line, "	procAmbulances", 15) == 0)
	{
		//printf(line);
		tokens = strSplit(line, ' ');
		procAmbulances3 = atoi(*(tokens + 2));
    	printf("8: %d\n",procAmbulances3);
	}
	if (strncmp(line, "	procRadioactive", 16) == 0)
	{
		//printf(line);
		tokens = strSplit(line, ' ');
		procRadioactive3 = atoi(*(tokens + 2));
    	printf("9: %d\n",procRadioactive3);
	}
}

void asignedVarBridge4(char line[100]){
	char** tokens;

    
	if (strncmp(line, "	schBridge", 10) == 0)
	{
		//printf(line);
		tokens = strSplit(line, ' ');
		strcpy(schBridge4,*(tokens + 3));
    	printf("1: %s\n",schBridge4);
	}
	if (strncmp(line, "	timeSemaphore", 14) == 0)
	{
		//printf(line);
		tokens = strSplit(line, ' ');
		timeSemaphore4 = atoi(*(tokens + 2));
    	printf("2: %d\n",timeSemaphore4);
	}
	if (strncmp(line, "	kOfficer", 9) == 0)
	{
		//printf(line);
		tokens = strSplit(line, ' ');
		kOfficer4 = atoi(*(tokens + 2));
    	printf("3: %d\n",kOfficer4);
	}
	if (strncmp(line, "	schThreads", 11) == 0)
	{
		//printf(line);
		tokens = strSplit(line, ' ');
		strcpy(schThreads4,*(tokens + 3));
    	printf("4: %s\n",schThreads4);
	}
	if (strncmp(line, "	largeBridge", 12) == 0)
	{
		//printf(line);
		tokens = strSplit(line, ' ');
		largeBridge4 = atoi(*(tokens + 2));
    	printf("5: %d\n",largeBridge4);
	}
	if (strncmp(line, "	mediaExponential", 17) == 0)
	{
		//printf(line);
		tokens = strSplit(line, ' ');
		mediaExponential4 = atoi(*(tokens + 2));
    	printf("6: %d\n",mediaExponential4);
	}
	if (strncmp(line, "	averageSpeed", 13) == 0)
	{
		//printf(line);
		tokens = strSplit(line, ' ');
		averageSpeed4 = atoi(*(tokens + 2));
    	printf("7: %d\n",averageSpeed4);
	}
	if (strncmp(line, "	procAmbulances", 15) == 0)
	{
		//printf(line);
		tokens = strSplit(line, ' ');
		procAmbulances4 = atoi(*(tokens + 2));
    	printf("8: %d\n",procAmbulances4);
	}
	if (strncmp(line, "	procRadioactive", 16) == 0)
	{
		//printf(line);
		tokens = strSplit(line, ' ');
		procRadioactive4 = atoi(*(tokens + 2));
    	printf("9: %d\n",procRadioactive4);
	}
}

void chooseBridge(char line[100]){
	//printf("cambio de linea%s\n");       line == "bridge1 ="
	char** tokens;
	if (strncmp(line, "bridge1 =", 9) == 0 || bridge1 == true)
	{	
		bridge1 = true;
		asignedVarBridge1(line);
	}
	else if (strncmp(line, "bridge2 =", 9) == 0 || bridge2 == true)
	{
		bridge2 = true;
		asignedVarBridge2(line);
	}
	else if (strncmp(line, "bridge3 =", 9) == 0 || bridge3 == true)
	{
		bridge3 = true;
		asignedVarBridge3(line);
	}
	else if (strncmp(line, "bridge4 =", 9) == 0 || bridge4 == true)
	{
		bridge4 = true;
		asignedVarBridge4(line);
	}
	else if (strncmp(line, "GUIon :", 7) == 0)
	{
		tokens = strSplit(line, ' ');
		GUIon = atoi(*(tokens + 2));
    	printf("Gui encendida: %d\n",GUIon);
	}
	else if (strncmp(line, "fisicPartON :", 13) == 0)
	{
		tokens = strSplit(line, ' ');
		fisicPartON = atoi(*(tokens + 2));
    	printf("parte fisica encendida: %d\n",fisicPartON);
	} 

	if(strncmp(line, "},", 2) == 0){
		printf("\n");
		bridge1 =false;
		bridge2 =false;
		bridge3 =false;
		bridge4 =false;
	}
}


void getDataConfig(){
	FILE *archivo;
 	
 	char caracteres[100];
 	
 	archivo = fopen("configuracion.txt","r+");
 	
 	if (archivo == NULL)
 		exit(1);
 	
 	//printf("\nEl contenido del archivo de prueba es \n\n");
 	while (feof(archivo) == 0)
 	{
 		fgets(caracteres,100,archivo);

 		//printf("%s",caracteres);
 		chooseBridge(caracteres);
 	}

    fclose(archivo);
}
 
int main()
{
 	getDataConfig();
	return 0;
}