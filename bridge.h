#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


//DEFINE BRIDGES FLAGS

int* flag_bridge1;
int* flag_bridge2;
int* flag_bridge3;
int* flag_bridge4;

void* runSemaphore(void* flag);

void* runOfficer(void* flag);

void* runJungleLaw(void* flag);

