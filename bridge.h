#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


//DEFINE BRIDGES FLAGS

int* flag_bridge1;
int* flag_bridge2;
int* flag_bridge3;
int* flag_bridge4;



//---------------------Bridge 1
 int  type_bridgeControl1;
 int  timeSemaphore1;
 int  kOfficer1;
 int  type_sched1;
 int  largeBridge1;
 int  mediaExponential1;
 int  averageSpeed1;
 int  procAmbulances1;
 int  procRadioactive1;
 //---------------------Bridge 2
 int  type_bridgeControl2;
 int  timeSemaphore2;
 int  kOfficer2;
 int  type_sched2;
 int  largeBridge2;
 int  mediaExponential2;
 int  averageSpeed2;
 int  procAmbulances2;
 int  procRadioactive2;
//---------------------Bridge 3
 int  type_bridgeControl3;
 int  timeSemaphore3;
 int  kOfficer3;
 int  type_sched3;
 int  largeBridge3;
 int  mediaExponential3;
 int  averageSpeed3;
 int  procAmbulances3;
 int  procRadioactive3;
//---------------------Bridge 4
 int  type_bridgeControl4;
 int  timeSemaphore4;
 int  kOfficer4;
 int  type_sched4;
 int  largeBridge4;
 int  mediaExponential4;
 int  averageSpeed4;
 int  procAmbulances4;
 int  procRadioactive4;

void* runSemaphore(void* flag);

void* runOfficer(void* flag);

void* runJungleLaw(void* flag);

