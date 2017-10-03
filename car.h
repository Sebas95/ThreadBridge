#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include "bridge.h"


#define NUM_LEDS 10

int* datosGUI1;
int* datosGUI2;
int* datosGUI3;
int* datosGUI4;



void* advance(void* car_attr);

int* getDataBridge(int bridge);