#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>



typedef struct bridge{
	char schBridge [50];
	int timeSemaphore;
	int kOfficer;
	char schThreads [50];
	int largeBridge;
	int mediaExponential;
	int averageSpeed;
	int procAmbulances;
	int procRadioactive;
} *Bridge;

char** strSplit(char* a_str, const char a_delim);
void assignedVarBridge(char line[100]);
void chooseBridge(char line[100]);
void getDataConfig();
Bridge getVarBridge(int bridge);
void assignedSpace();
int getGuiOn();
int getFisicOn();