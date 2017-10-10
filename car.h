#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include "bridge.h"
#include <string.h>

#define SECOND 1000000

#define TIME_LIMIT_AMBULANCE SECOND/2
#define TIME_LIMIT_RADIOACTIVE SECOND/1
#define TIME_LIMIT_NORMAL SECOND/3

#define NUM_LEDS 10

int* datosGUI1;
int* datosGUI2;
int* datosGUI3;
int* datosGUI4;

#define RADIOACTIVE 0
#define AMBULANCE   1
#define NORMAL      2



void* advance(void* car_attr);

int* getDataBridge(int bridge);
