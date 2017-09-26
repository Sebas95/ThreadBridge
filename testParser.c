#include "parser.h"

int main()
{
 	getDataConfig();
 	
 	Bridge _puente;
 	_puente = getVarBridge(3);
 	int i;
 	for (i = 1; i <= 9; ++i)
 	{
 		if (i==1)
 		{
 			printf("\n%d: schBridge: %s\n", i, _puente->schBridge);
 		}
 		else if (i==2)
 		{
 			printf("%d: timeSemaphore: %d\n", i, _puente->timeSemaphore);
 		}
 		else if (i==3)
 		{
 			printf("%d: kOfficer: %d\n", i, _puente->kOfficer);
 		}
 		else if (i==4)
 		{
 			printf("%d: schThreads: %s\n", i, _puente->schThreads);
 		}
 		else if (i==5)
 		{
 			printf("%d: largeBridge: %d\n", i, _puente->largeBridge);
 		}
 		else if (i==6)
 		{
 			printf("%d: mediaExponential: %d\n", i, _puente->mediaExponential);
 		}
 		else if (i==7)
 		{
 			printf("%d: averageSpeed: %d\n", i, _puente->averageSpeed);
 		}
 		else if (i==8)
 		{
 			printf("%d: procAmbulances: %d\n", i, _puente->procAmbulances);
 		}
 		else if (i==9)
 		{
 			printf("%d: procRadioactive: %d\n", i, _puente->procRadioactive);
 		}
 	}

 	int fisic = getFisicOn();
 	int gui = getGuiOn();

 	printf("\nGui on: %d\n",gui);
 	printf("\nFisica on: %d\n",fisic);
	return 0;
}