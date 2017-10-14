#include <stdlib.h>
#include "parser.h"
#include "scheduler.h"
#include "arduino-serial-lib.h"
#include <time.h>
#include <SDL.h>
#include <SDL_image.h>

#include <string.h>
#include <stdio.h>



#define SCREEN_WIDTH 1564
#define SCREEN_HEIGHT 881
#define X_BASE 40
#define Y_BASE 20
#define WIDTH_BRIDGE 190
#define SPACE_BETWEEN_BRIDGE 30
#define HEIGHT_CAR 120
#define HEIGHT_RADIO 150
#define WIDTH_CAR 70
#define OFFSET_CAR 45
#define HEIGHT_SEMAPHORE 30
#define WIDTH_SEMPAHORE 70
#define X_SEMAPHORE X_BASE - HEIGHT_SEMAPHORE
#define Y_SEMAPHORE_OFFSET 50
#define WIDTH_OFFICER 90
#define HEIGHT_OFFICER 70


int largeBridge1 = 0;
int largeBridge2 = 0;
int largeBridge3 = 0;
int largeBridge4 = 0;

int type_bridgeControl1 = 0;
int type_bridgeControl2 = 0;
int type_bridgeControl3 = 0;
int type_bridgeControl4 = 0;



void * nullptr = NULL;


void* runPhysique(void* unused){
 	while(true){
 	int* dataBridge1;
	int* dataBridge2;
	int* dataBridge3;
	//int* dataBridge4;

	dataBridge1 = getDataBridge(1);
	dataBridge2 = getDataBridge(2);
	dataBridge3 = getDataBridge(3);
	//dataBridge4 = getDataBridge(4);

	int fd = 0;
	char puertoUSB[12]  = "/dev/ttyACM0";

    fd = serialport_init(puertoUSB, 9600);
    if( fd==-1 ) printf("couldn't open port");

    //printf("\nla lista es: %s\n", dataBridge1[0]);
    char type1 = dataBridge1[0];
    char orientacion1 [2];// (char *)dataBridge1[1];
    int primero = dataBridge1[1]%10;
    int resultado = dataBridge1[1]/10;
    int segundo = resultado%10;
    orientacion1[0] = (char)segundo;
    orientacion1[1] = (char)primero;
	char paso1 = (char)dataBridge1[2];

    char type2 = (char)dataBridge2[0];
    char orientacion2 [2]; //= (char *)dataBridge2[1];

    primero = dataBridge2[1]%10;
    resultado = dataBridge2[1]/10;
    segundo = resultado%10;
    orientacion2[0] = (char)segundo;
    orientacion2[1] = (char)primero;
    //sprintf(orientacion2, "%d", dataBridge2[1]);
    char paso2 = (char)dataBridge2[2];

    char type3 = (char)dataBridge3[0];
    char orientacion3[2];// = (char *)dataBridge3[1];
    primero = dataBridge3[1]%10;
    resultado = dataBridge3[1]/10;
    segundo = resultado%10;
    orientacion3[0] = (char)segundo;
    orientacion3[1] = (char)primero;
    //sprintf(orientacion3, "%d", dataBridge3[1]);
    char paso3 = (char)dataBridge3[2];


    char lista[33];
    if(largeBridge1<10){
    	lista[0] = type1 + '0';
	    lista[1] = ';';
	    lista[2] = paso1 + '0';
	    lista[3] = ';';
	    lista[4] = largeBridge1+ '0';
	    lista[5] = ';';
	    lista[6] = orientacion1[0] + '0';
	    lista[7] = orientacion1[1] + '0';
	    lista[8] = ';';

	    lista[9] = type2 + '0';
	    lista[10] = ';';
	    lista[11] = paso2 + '0';
	    lista[12] = ';';
	    lista[13] = largeBridge2 + '0';
	    lista[14] = ';';
	    lista[15] = orientacion2[0] + '0';
	    lista[16] = orientacion2[1] + '0';
	    lista[17] = ';';

	    lista[18] = type3 + '0';
	    lista[19] = ';';
	    lista[20] = paso3 + '0';
	    lista[21] = ';';
	    lista[22] = largeBridge3 + '0';
	    lista[23] = ';';
	    lista[24] = orientacion3[0] + '0';
	    lista[25] = orientacion3[1] + '0';
	    lista[26] = ';';
    } else{
    	char largo1[2];// = (char *) largeBridge1;
    	primero = largeBridge1%10;
    	resultado = largeBridge1/10;
    	segundo = resultado%10;
    	largo1[0] = (char)segundo;
    	largo1[1] = (char)primero;
    	//sprintf(largo1, "%d", largeBridge1);
    	char largo2[2];// = (char *) largeBridge2;
    	primero = largeBridge2%10;
    	resultado = largeBridge2/10;
    	segundo = resultado%10;
    	largo2[0] = (char)segundo;
    	largo2[1] = (char)primero;
    	//sprintf(largo2, "%d", largeBridge2);
    	char largo3[2];//= (char *) largeBridge3;
    	primero = largeBridge3%10;
    	resultado = largeBridge3/10;
    	segundo = resultado%10;
    	largo3[0] = (char)segundo;
    	largo3[1] = (char)primero;
    	//sprintf(largo3, "%d", largeBridge3);
    	lista[0] = type1 + '0';
	    lista[1] = ';';
	    lista[2] = paso1 + '0';
	    lista[3] = ';';
	    lista[4] = largo1[0] + '0';
	    lista[5] = largo1[1] + '0';
	    lista[6] = ';';
	    lista[7] = orientacion1[0] + '0';
	    lista[8] = orientacion1[1] + '0';
	    lista[9] = ';';

	    lista[10] = type2 + '0';
	    lista[11] = ';';
	    lista[12] = paso2 + '0';
	    lista[13] = ';';
	    lista[14] = largo2[0] + '0';
	    lista[15] = largo2[1] + '0';
	    lista[16] = ';';
	    lista[17] = orientacion2[0] + '0';
	    lista[18] = orientacion2[1] + '0';
	    lista[19] = ';';

	    lista[20] = type3 + '0';
	    lista[21] = ';';
	    lista[22] = paso3 + '0';
	    lista[23] = ';';
	    lista[24] = largo3[0] + '0';
	    lista[25] = largo3[1] + '0';
	    lista[26] = ';';
	    lista[27] = orientacion3[0] + '0';
	    lista[28] = orientacion3[1] + '0';
	    lista[29] = ';';
    }

    //printf("\n***************************\n");
    //printf("\nla lista es: %s\n", lista);
    //printf("\n---------------------------\n");

    serialport_write(fd, lista);  //mando el tipo de carro
    serialport_flush(fd);
}
    //serialport_write(fd, "1;5;8;12;2;3;6;22;0;6;10;31;");  //mando el tipo de carro
    //serialport_flush(fd);
    //serialport_write(fd, "1;6;8;12;2;4;6;22;0;5;10;31;");  //mando el tipo de carro
    //serialport_flush(fd);
    //serialport_write(fd, "1;7;8;12;2;5;6;22;0;4;10;31;");  //mando el tipo de carro
    //serialport_flush(fd);
    return 0;
}
/**
*  Sends the parser configurations variables to scheduler programs
*
*/
void configure()
{

	int* type_sched = malloc(sizeof(int));
	getDataConfig();

 	for (int i = 1; i < NUM_BRIDGES+1 ; ++i)
 	{
 		Bridge _puente;
 		_puente = getVarBridge(i);
 		int* attr = malloc(sizeof(int)*9);
	 	int type_bridgeControl;

	 	char* schThreads = _puente->schThreads;
	 	char* schBridge = _puente->schBridge;
	 	int timeSemaphore = _puente->timeSemaphore;
	 	int kOfficer = _puente->kOfficer;
	 	int largeBridge = _puente->largeBridge;
	 	if (i == 1)
	 		largeBridge1 = largeBridge;
	 	else if (i == 2)
	 		largeBridge2 = largeBridge;
	 	else if (i == 3)
	 		largeBridge3 = largeBridge;
	 	else if (i == 4)
	 		largeBridge4 = largeBridge;
	 	int mediaExponential = _puente->mediaExponential;
		int averageSpeed = _puente->averageSpeed;
		int procAmbulances = _puente->procAmbulances;
		int procRadioactive = _puente->procRadioactive;

	 	if (strncmp(schBridge, "Official", 8) == 0)
	 		type_bridgeControl = Official;
	 	else if (strncmp(schBridge, "Jungle", 6) == 0)
	 		type_bridgeControl = Jungle;
	 	else if (strncmp(schBridge, "Semaphore", 9) == 0)
	 		type_bridgeControl = Semaphore;

	 	if (i == 1)
	 		type_bridgeControl1 = type_bridgeControl;
	 	else if (i == 2)
	 		type_bridgeControl2 = type_bridgeControl;
	 	else if (i == 3)
	 		type_bridgeControl3 = type_bridgeControl;
	 	else if (i == 4)
	 		type_bridgeControl4 = type_bridgeControl;

	 	if (strncmp(schThreads, "SJF", 3) == 0)
	 		*type_sched = SJF;
	 	else if (strncmp(schThreads, "Round_Robin", 11) == 0)
	 		*type_sched = ROUND_ROBIN;
	 	else if (strncmp(schThreads, "Real_time", 9) == 0)
	 		*type_sched = REAL_TIME;
	 	else if (strncmp(schThreads, "FIFO", 4) == 0)
	 		*type_sched = FIFO;
	 	else if (strncmp(schThreads, "Priority", 8) == 0)
	 		*type_sched = PRIORITY_QUEUE;

			/*printf("\n%d: schBridge: %s\n", i, _puente->schBridge);
 			printf("%d: timeSemaphore: %d\n", i, _puente->timeSemaphore);
 			printf("%d: kOfficer: %d\n", i, _puente->kOfficer);
 			printf("%d: schThreads: %s\n", i, _puente->schThreads);
 			printf("%d: largeBridge: %d\n", i, _puente->largeBridge);
 			printf("%d: mediaExponential: %d\n", i, _puente->mediaExponential);
 			printf("%d: averageSpeed: %d\n", i, _puente->averageSpeed);
 			printf("%d: procAmbulances: %d\n", i, _puente->procAmbulances);
 			printf("%d: procRadioactive: %d\n", i, _puente->procRadioactive);
 			*/
	 	attr[0] = type_bridgeControl;
	 	attr[1] = timeSemaphore;
	 	attr[2] = kOfficer;
	 	attr[3] = *type_sched;
	 	attr[4] = largeBridge;
	 	attr[5] = mediaExponential;
	 	attr[6] = averageSpeed;
	 	attr[7] = procAmbulances;
	 	attr[8] = procRadioactive;

	 	setParam(attr,i); //send configuration to scheduler
 	}
}

/**
*   Create threads for bridges' controls e.g officer, jungle law, semaphore
*
*/
void configure_bridges()
{
	//init flags
	flag_bridge1 = (int*)malloc(sizeof(int));
	flag_bridge2 = (int*)malloc(sizeof(int));
	flag_bridge3 = (int*)malloc(sizeof(int));
	flag_bridge4 = (int*)malloc(sizeof(int));
	*flag_bridge1 = 1;
	*flag_bridge2 = 1;
	*flag_bridge3 = 1;
	*flag_bridge4 = 1;

	 bridge_1_in_use = (int*)malloc(sizeof(int));
     bridge_2_in_use = (int*)malloc(sizeof(int));
     bridge_3_in_use = (int*)malloc(sizeof(int));
     bridge_4_in_use = (int*)malloc(sizeof(int));
     *bridge_1_in_use = 0;
     *bridge_2_in_use = 0;
     *bridge_3_in_use = 0;
     *bridge_4_in_use = 0;

     carrosPasados1 = (int*)malloc(sizeof(int));
     carrosPasados2 = (int*)malloc(sizeof(int));
     carrosPasados3 = (int*)malloc(sizeof(int));
     carrosPasados4 = (int*)malloc(sizeof(int));
     *carrosPasados1 = 0;
     *carrosPasados2 = 0;
     *carrosPasados3 = 0;
     *carrosPasados4 = 0;

     flagSincronizacionOfficial1 = (int*)malloc(sizeof(int));
     flagSincronizacionOfficial2 = (int*)malloc(sizeof(int));
     flagSincronizacionOfficial3 = (int*)malloc(sizeof(int));
     flagSincronizacionOfficial4 = (int*)malloc(sizeof(int));

     *flagSincronizacionOfficial1 = 1;
     *flagSincronizacionOfficial2 = 1;
     *flagSincronizacionOfficial3 = 1;
     *flagSincronizacionOfficial4 = 1;

     flagSincronizacionOfficialScheduler1 = (int*)malloc(sizeof(int));
     flagSincronizacionOfficialScheduler2 = (int*)malloc(sizeof(int));
     flagSincronizacionOfficialScheduler3 = (int*)malloc(sizeof(int));
     flagSincronizacionOfficialScheduler4 = (int*)malloc(sizeof(int));

     *flagSincronizacionOfficialScheduler1 = 0;
     *flagSincronizacionOfficialScheduler2 = 0;
     *flagSincronizacionOfficialScheduler3 = 0;
     *flagSincronizacionOfficialScheduler4 = 0;

	for (int i = 1; i < NUM_BRIDGES + 1; ++i)
 	{
		Bridge _puente;
	 	_puente = getVarBridge(i);
	 	char* schBridge = _puente->schBridge;
	 	pthread_t* temp_b_control = malloc(sizeof(pthread_t));


	 	if      (strncmp(schBridge, "Official", 8) == 0)
	 	{
	 		if(i==1) pthread_create(temp_b_control, NULL, runOfficer, (void *)flag_bridge1);
	 		if(i==2) pthread_create(temp_b_control, NULL, runOfficer, (void *)flag_bridge2);
	 		if(i==3) pthread_create(temp_b_control, NULL, runOfficer, (void *)flag_bridge3);
	 		if(i==4) pthread_create(temp_b_control, NULL, runOfficer, (void *)flag_bridge4);

	 	}
		else if (strncmp(schBridge, "Jungle", 6) == 0)
		{
			if(i==1) pthread_create(temp_b_control, NULL, runJungleLaw, (void *)flag_bridge1);
	 		if(i==2) pthread_create(temp_b_control, NULL, runJungleLaw, (void *)flag_bridge2);
	 		if(i==3) pthread_create(temp_b_control, NULL, runJungleLaw, (void *)flag_bridge3);
	 		if(i==4) pthread_create(temp_b_control, NULL, runJungleLaw, (void *)flag_bridge4);
		}
		else if (strncmp(schBridge, "Semaphore", 9) == 0)
		{
			if(i==1) pthread_create(temp_b_control, NULL, runSemaphore, (void *)flag_bridge1);
	 		if(i==2) pthread_create(temp_b_control, NULL, runSemaphore, (void *)flag_bridge2);
	 		if(i==3) pthread_create(temp_b_control, NULL, runSemaphore, (void *)flag_bridge3);
	 		if(i==4) pthread_create(temp_b_control, NULL, runSemaphore, (void *)flag_bridge4);
 		}
    }
}




/*
 * Loads an bridge into a texture on the rendering device
 * @param file The bridge file to load
 * @param ren The renderer to load the texture onto
 * @return the loaded texture, or nullptr if something went wrong.
 */
SDL_Texture* loadTexture(const char* file, SDL_Renderer *ren){
	SDL_Texture *texture = IMG_LoadTexture(ren, file);
	if (texture == nullptr){
		printf("Error in loadTexture\n");
	}
	return texture;
}
/*
 * Draw an SDL_Texture to an SDL_Renderer at position x, y, with some desired
 * width and height
 * @param tex The source texture we want to draw
 * @param rend The renderer we want to draw too
 * @param x The x coordinate to draw too
 * @param y The y coordinate to draw too
 * @param w The width of the texture to draw
 * @param h The height of the texture to draw
 */
void renderTextureFull(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, int w, int h){
	//Setup the destination rectangle to be at the position we want
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	dst.w = w;
	dst.h = h;
	SDL_RenderCopy(ren, tex, NULL, &dst);
}
/*
 * Draw an SDL_Texture to an SDL_Renderer at position x, y, preserving
 * the texture's width and height
 * @param tex The source texture we want to draw
 * @param rend The renderer we want to draw too
 * @param x The x coordinate to draw too
 * @param y The y coordinate to draw too
 */
void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y){
	int w, h;
	SDL_QueryTexture(tex, NULL, NULL, &w, &h);
	renderTextureFull(tex, ren, x, y, w, h);
}


void* runGUI(void* unused)
{
	 datosGUI1 = (int*)malloc(3*sizeof(int));
     datosGUI2= (int*)malloc(3*sizeof(int));
     datosGUI3= (int*)malloc(3*sizeof(int));
     datosGUI4= (int*)malloc(3*sizeof(int));
	//Start up SDL and make sure it went ok
	if (SDL_Init(SDL_INIT_VIDEO) != 0){
		printf("Error in SDL_Init\n");
		return (void*)1;
	}

	//Setup our window and renderer
	SDL_Window *window = SDL_CreateWindow("Main Window", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == nullptr){
		printf("Error in CreateWindow\n");
		SDL_Quit();
		return (void*)1;
	}
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr){
		printf("Error in CreateRenderer\n");
		//cleanup(window);
		SDL_Quit();
		return (void*)1;
	}

	//The textures we'll be using
	const char* resPathBack = "./img/background.png";
	const char* resPathBridge = "./img/bridge.png";
	const char* resPathCarRight = "./img/carRight.png";
	const char* resPathCarLeft = "./img/carLeft.png";
	const char* resPathAmbulanceRight = "./img/ambulanceRight.png";
	const char* resPathAmbulanceLeft = "./img/ambulanceLeft.png";
	const char* resPathRadioactiveRight = "./img/radioactiveRight.png";
	const char* resPathRadioactiveLeft = "./img/radioactiveLeft.png";
	const char* resPathSemaphoreGreen = "./img/semaphoreGreen.png";
	const char* resPathSemaphoreRed = "./img/semaphoreRed.png";
	const char* resPathOfficerGoRight = "./img/officerGoRight.png";
	const char* resPathOfficerGoLeft = "./img/officerGoLeft.png";
	const char* resPathOfficerStopRight = "./img/officerStopRight.png";
	const char* resPathOfficerStopLeft = "./img/officerStopLeft.png";

	SDL_Texture *background = loadTexture(resPathBack, renderer);
	SDL_Texture *bridge = loadTexture(resPathBridge, renderer);
	SDL_Texture *carRight = loadTexture(resPathCarRight, renderer);
	SDL_Texture *carLeft = loadTexture(resPathCarLeft, renderer);
	SDL_Texture *ambulanceRight = loadTexture(resPathAmbulanceRight, renderer);
	SDL_Texture *ambulanceLeft = loadTexture(resPathAmbulanceLeft, renderer);
	SDL_Texture *radioactiveRight = loadTexture(resPathRadioactiveRight, renderer);
	SDL_Texture *radioactiveLeft = loadTexture(resPathRadioactiveLeft, renderer);
	SDL_Texture *semaphoreGreen = loadTexture(resPathSemaphoreGreen, renderer);
	SDL_Texture *semaphoreRed = loadTexture(resPathSemaphoreRed, renderer);
	SDL_Texture *officerGoRight = loadTexture(resPathOfficerGoRight, renderer);
	SDL_Texture *officerGoLeft = loadTexture(resPathOfficerGoLeft, renderer);
	SDL_Texture *officerStopRight = loadTexture(resPathOfficerStopRight, renderer);
	SDL_Texture *officerStopLeft = loadTexture(resPathOfficerStopLeft, renderer);
	//Make sure they both loaded ok
	if (background == nullptr || bridge == nullptr){
		//cleanup(background, bridge, renderer, window);
		SDL_Quit();
		return (void*)1;
	}
	int* dataBridge1;
	int* dataBridge2;
	int* dataBridge3;
	int* dataBridge4;

	int xBridgeControl11;
	int yBridgeControl11;
	int xBridgeControl12;
	int yBridgeControl12;

	int xBridgeControl21;
	int yBridgeControl21;
	int xBridgeControl22;
	int yBridgeControl22;

	int xBridgeControl31;
	int yBridgeControl31;
	int xBridgeControl32;
	int yBridgeControl32;

	int xBridgeControl41;
	int yBridgeControl41;
	int xBridgeControl42;
	int yBridgeControl42;

	//A sleepy rendering loop
	while (true) {
		//Clear the window
		SDL_RenderClear(renderer);

		renderTexture(background, renderer, 0, 0);

		//Draw our bridge in the center of the window
		//We need the foreground bridge's width to properly compute the position
		//of it's top left corner so that the bridge will be centered
		int x1 = X_BASE;
		int y1 = Y_BASE;
		int largeBridgeLocal1 = 500 + 100*largeBridge1;
		renderTextureFull(bridge, renderer, x1, y1, largeBridgeLocal1, WIDTH_BRIDGE);

		int x2 = X_BASE;
		int y2 = y1 + WIDTH_BRIDGE + SPACE_BETWEEN_BRIDGE;
		int largeBridgeLocal2 = 500 + 100*largeBridge2;
		renderTextureFull(bridge, renderer, x2, y2, largeBridgeLocal2, WIDTH_BRIDGE);

		int x3 = X_BASE;
		int y3 = y2 + WIDTH_BRIDGE + SPACE_BETWEEN_BRIDGE;
		int largeBridgeLocal3 = 500 + 100*largeBridge3;
		renderTextureFull(bridge, renderer, x3, y3, largeBridgeLocal3, WIDTH_BRIDGE);

		int x4 = X_BASE;
		int y4 = y3 + WIDTH_BRIDGE + SPACE_BETWEEN_BRIDGE;
		int largeBridgeLocal4 = 500 + 100*largeBridge4;
		renderTextureFull(bridge, renderer, x4, y4, largeBridgeLocal4, WIDTH_BRIDGE);


		dataBridge1 = getDataBridge(1);
		dataBridge2 = getDataBridge(2);
		dataBridge3 = getDataBridge(3);
		dataBridge4 = getDataBridge(4);


		//////////// PARA PUENTE 1 ///////////
		int xCar1 = x1 + dataBridge1[2]*(largeBridgeLocal1/largeBridge1);
		if (dataBridge1[1] == 12)
		{
			xCar1 = largeBridgeLocal1 - xCar1;
		}
		int yCar1 = y1 + OFFSET_CAR;

		xBridgeControl11 = X_SEMAPHORE;
		yBridgeControl11 = y1 + Y_SEMAPHORE_OFFSET;
		xBridgeControl12 = x1 + largeBridgeLocal1 + X_SEMAPHORE;
		yBridgeControl12 = y1 + Y_SEMAPHORE_OFFSET;
		if (type_bridgeControl1 == 12)
		{
			if (dataBridge1[1] == 11)
			{
				renderTextureFull(semaphoreGreen, renderer, xBridgeControl11, yBridgeControl11, HEIGHT_SEMAPHORE, WIDTH_SEMPAHORE);
				renderTextureFull(semaphoreRed, renderer, xBridgeControl12, yBridgeControl12, HEIGHT_SEMAPHORE, WIDTH_SEMPAHORE);
			} else if (dataBridge1[1] == 12)
			{
				renderTextureFull(semaphoreRed, renderer, xBridgeControl11, yBridgeControl11, HEIGHT_SEMAPHORE, WIDTH_SEMPAHORE);
				renderTextureFull(semaphoreGreen, renderer, xBridgeControl12, yBridgeControl12, HEIGHT_SEMAPHORE, WIDTH_SEMPAHORE);
			}
		} else if (type_bridgeControl1 == 10)
		{
			if (dataBridge1[1] == 11)
			{
				renderTextureFull(officerGoRight, renderer, xBridgeControl11, yBridgeControl11, HEIGHT_OFFICER, WIDTH_OFFICER);
				renderTextureFull(officerStopLeft, renderer, xBridgeControl12, yBridgeControl12, HEIGHT_OFFICER, WIDTH_OFFICER);
			} else if (dataBridge1[1] == 12)
			{
				renderTextureFull(officerStopRight, renderer, xBridgeControl11, yBridgeControl11, HEIGHT_OFFICER, WIDTH_OFFICER);
				renderTextureFull(officerGoLeft, renderer, xBridgeControl12, yBridgeControl12, HEIGHT_OFFICER, WIDTH_OFFICER);
			}
		}

		if (dataBridge1[0] == 0 && dataBridge1[1] == 11)
		{
			renderTextureFull(radioactiveRight, renderer, xCar1, yCar1, HEIGHT_RADIO, WIDTH_CAR);
		} else if (dataBridge1[0] == 0 && dataBridge1[1] == 12)
		{
			renderTextureFull(radioactiveLeft, renderer, xCar1, yCar1, HEIGHT_RADIO, WIDTH_CAR);
		} else if (dataBridge1[0] == 1 && dataBridge1[1] == 11)
		{
			renderTextureFull(ambulanceRight, renderer, xCar1, yCar1, HEIGHT_CAR, WIDTH_CAR);
		} else if (dataBridge1[0] == 1 && dataBridge1[1] == 12)
		{
			renderTextureFull(ambulanceLeft, renderer, xCar1, yCar1, HEIGHT_CAR, WIDTH_CAR);
		} else if (dataBridge1[0] == 2 && dataBridge1[1] == 11)
		{
			renderTextureFull(carRight, renderer, xCar1, yCar1, HEIGHT_CAR, WIDTH_CAR);
		} else if (dataBridge1[0] == 2 && dataBridge1[1] == 12)
		{
			renderTextureFull(carLeft, renderer, xCar1, yCar1, HEIGHT_CAR, WIDTH_CAR);
		}
		//////////// FIN PUENTE 1 /////////////

		//////////// PARA PUENTE 2 ///////////
		int xCar2 = x2 + dataBridge2[2]*(largeBridgeLocal2/largeBridge2);
		if (dataBridge2[1] == 22)
		{
			xCar2 = largeBridgeLocal2 - xCar2;
		}
		int yCar2 = y2 + OFFSET_CAR;

		xBridgeControl21 = X_SEMAPHORE;
		yBridgeControl21 = y2 + Y_SEMAPHORE_OFFSET;
		xBridgeControl22 = x2 + largeBridgeLocal2 + X_SEMAPHORE;
		yBridgeControl22 = y2 + Y_SEMAPHORE_OFFSET;
		if (type_bridgeControl2 == 12)
		{
			if (dataBridge2[1] == 21)
			{
				renderTextureFull(semaphoreGreen, renderer, xBridgeControl21, yBridgeControl21, HEIGHT_SEMAPHORE, WIDTH_SEMPAHORE);
				renderTextureFull(semaphoreRed, renderer, xBridgeControl22, yBridgeControl22, HEIGHT_SEMAPHORE, WIDTH_SEMPAHORE);
			} else if (dataBridge2[1] == 22)
			{
				renderTextureFull(semaphoreRed, renderer, xBridgeControl21, yBridgeControl21, HEIGHT_SEMAPHORE, WIDTH_SEMPAHORE);
				renderTextureFull(semaphoreGreen, renderer, xBridgeControl22, yBridgeControl22, HEIGHT_SEMAPHORE, WIDTH_SEMPAHORE);
			}
		} else if (type_bridgeControl2 == 10)
		{
			if (dataBridge2[1] == 21)
			{
				renderTextureFull(officerGoRight, renderer, xBridgeControl21, yBridgeControl21, HEIGHT_OFFICER, WIDTH_OFFICER);
				renderTextureFull(officerStopLeft, renderer, xBridgeControl22, yBridgeControl22, HEIGHT_OFFICER, WIDTH_OFFICER);
			} else if (dataBridge2[1] == 22)
			{
				renderTextureFull(officerStopRight, renderer, xBridgeControl21, yBridgeControl21, HEIGHT_OFFICER, WIDTH_OFFICER);
				renderTextureFull(officerGoLeft, renderer, xBridgeControl22, yBridgeControl22, HEIGHT_OFFICER, WIDTH_OFFICER);
			}
		}


		if (dataBridge2[0] == 0 && dataBridge2[1] == 21)
		{
			renderTextureFull(radioactiveRight, renderer, xCar2, yCar2, HEIGHT_RADIO, WIDTH_CAR);
		} else if (dataBridge2[0] == 0 && dataBridge2[1] == 22)
		{
			renderTextureFull(radioactiveLeft, renderer, xCar2, yCar2, HEIGHT_RADIO, WIDTH_CAR);
		} else if (dataBridge2[0] == 1 && dataBridge2[1] == 21)
		{
			renderTextureFull(ambulanceRight, renderer, xCar2, yCar2, HEIGHT_CAR, WIDTH_CAR);
		} else if (dataBridge2[0] == 1 && dataBridge2[1] == 22)
		{
			renderTextureFull(ambulanceLeft, renderer, xCar2, yCar2, HEIGHT_CAR, WIDTH_CAR);
		} else if (dataBridge2[0] == 2 && dataBridge2[1] == 21)
		{
			renderTextureFull(carRight, renderer, xCar2, yCar2, HEIGHT_CAR, WIDTH_CAR);
		} else if (dataBridge2[0] == 2 && dataBridge2[1] == 22)
		{
			renderTextureFull(carLeft, renderer, xCar2, yCar2, HEIGHT_CAR, WIDTH_CAR);
		}
		//////////// FIN PUENTE 2 /////////////

		//////////// PARA PUENTE 3 ///////////
		int xCar3 = x3 + dataBridge3[2]*(largeBridgeLocal3/largeBridge3);
		if (dataBridge3[1] == 32)
		{
			xCar3 = largeBridgeLocal3 - xCar3;
		}
		int yCar3 = y3 + OFFSET_CAR;

		xBridgeControl31 = X_SEMAPHORE;
		yBridgeControl31 = y3 + Y_SEMAPHORE_OFFSET;
		xBridgeControl32 = x3 + largeBridgeLocal3 + X_SEMAPHORE;
		yBridgeControl32 = y3 + Y_SEMAPHORE_OFFSET;
		if (type_bridgeControl3 == 12)
		{
			if (dataBridge3[1] == 31)
			{
				renderTextureFull(semaphoreGreen, renderer, xBridgeControl31, yBridgeControl31, HEIGHT_SEMAPHORE, WIDTH_SEMPAHORE);
				renderTextureFull(semaphoreRed, renderer, xBridgeControl32, yBridgeControl32, HEIGHT_SEMAPHORE, WIDTH_SEMPAHORE);
			} else if (dataBridge3[1] == 32)
			{
				renderTextureFull(semaphoreRed, renderer, xBridgeControl31, yBridgeControl31, HEIGHT_SEMAPHORE, WIDTH_SEMPAHORE);
				renderTextureFull(semaphoreGreen, renderer, xBridgeControl32, yBridgeControl32, HEIGHT_SEMAPHORE, WIDTH_SEMPAHORE);
			}
		} else if (type_bridgeControl3 == 10)
		{
			if (dataBridge3[1] == 31)
			{
				renderTextureFull(officerGoRight, renderer, xBridgeControl31, yBridgeControl31, HEIGHT_OFFICER, WIDTH_OFFICER);
				renderTextureFull(officerStopLeft, renderer, xBridgeControl32, yBridgeControl32, HEIGHT_OFFICER, WIDTH_OFFICER);
			} else if (dataBridge3[1] == 32)
			{
				renderTextureFull(officerStopRight, renderer, xBridgeControl31, yBridgeControl31, HEIGHT_OFFICER, WIDTH_OFFICER);
				renderTextureFull(officerGoLeft, renderer, xBridgeControl32, yBridgeControl32, HEIGHT_OFFICER, WIDTH_OFFICER);
			}
		}


		if (dataBridge3[0] == 0 && dataBridge3[1] == 31)
		{
			renderTextureFull(radioactiveRight, renderer, xCar3, yCar3, HEIGHT_RADIO, WIDTH_CAR);
		} else if (dataBridge3[0] == 0 && dataBridge3[1] == 32)
		{
			renderTextureFull(radioactiveLeft, renderer, xCar3, yCar3, HEIGHT_RADIO, WIDTH_CAR);
		} else if (dataBridge3[0] == 1 && dataBridge3[1] == 31)
		{
			renderTextureFull(ambulanceRight, renderer, xCar3, yCar3, HEIGHT_CAR, WIDTH_CAR);
		} else if (dataBridge3[0] == 1 && dataBridge3[1] == 32)
		{
			renderTextureFull(ambulanceLeft, renderer, xCar3, yCar3, HEIGHT_CAR, WIDTH_CAR);
		} else if (dataBridge3[0] == 2 && dataBridge3[1] == 31)
		{
			renderTextureFull(carRight, renderer, xCar3, yCar3, HEIGHT_CAR, WIDTH_CAR);
		} else if (dataBridge3[0] == 2 && dataBridge3[1] == 32)
		{
			renderTextureFull(carLeft, renderer, xCar3, yCar3, HEIGHT_CAR, WIDTH_CAR);
		}
		//////////// FIN PUENTE 3 /////////////

		//////////// PARA PUENTE 4 ///////////
		int xCar4 = x4 + dataBridge4[2]*(largeBridgeLocal4/largeBridge4);
		if (dataBridge4[1] == 42)
		{
			xCar4 = largeBridgeLocal4 - xCar4;
		}
		int yCar4 = y4 + OFFSET_CAR;

		xBridgeControl41 = X_SEMAPHORE;
		yBridgeControl41 = y4 + Y_SEMAPHORE_OFFSET;
		xBridgeControl42 = x4 + largeBridgeLocal4 + X_SEMAPHORE;
		yBridgeControl42 = y4 + Y_SEMAPHORE_OFFSET;
		if (type_bridgeControl4 == 12)
		{
			if (dataBridge4[1] == 41)
			{
				renderTextureFull(semaphoreGreen, renderer, xBridgeControl41, yBridgeControl41, HEIGHT_SEMAPHORE, WIDTH_SEMPAHORE);
				renderTextureFull(semaphoreRed, renderer, xBridgeControl42, yBridgeControl42, HEIGHT_SEMAPHORE, WIDTH_SEMPAHORE);
			} else if (dataBridge4[1] == 42)
			{
				renderTextureFull(semaphoreRed, renderer, xBridgeControl41, yBridgeControl41, HEIGHT_SEMAPHORE, WIDTH_SEMPAHORE);
				renderTextureFull(semaphoreGreen, renderer, xBridgeControl42, yBridgeControl42, HEIGHT_SEMAPHORE, WIDTH_SEMPAHORE);
			}
		} else if (type_bridgeControl4 == 10)
		{
			if (dataBridge4[1] == 41)
			{
				renderTextureFull(officerGoRight, renderer, xBridgeControl41, yBridgeControl41, HEIGHT_OFFICER, WIDTH_OFFICER);
				renderTextureFull(officerStopLeft, renderer, xBridgeControl42, yBridgeControl42, HEIGHT_OFFICER, WIDTH_OFFICER);
			} else if (dataBridge4[1] == 42)
			{
				renderTextureFull(officerStopRight, renderer, xBridgeControl41, yBridgeControl41, HEIGHT_OFFICER, WIDTH_OFFICER);
				renderTextureFull(officerGoLeft, renderer, xBridgeControl42, yBridgeControl42, HEIGHT_OFFICER, WIDTH_OFFICER);
			}
		}


		if (dataBridge4[0] == 0 && dataBridge4[1] == 41)
		{
			renderTextureFull(radioactiveRight, renderer, xCar4, yCar4, HEIGHT_RADIO, WIDTH_CAR);
		} else if (dataBridge4[0] == 0 && dataBridge4[1] == 42)
		{
			renderTextureFull(radioactiveLeft, renderer, xCar4, yCar4, HEIGHT_RADIO, WIDTH_CAR);
		} else if (dataBridge4[0] == 1 && dataBridge4[1] == 41)
		{
			renderTextureFull(ambulanceRight, renderer, xCar4, yCar4, HEIGHT_CAR, WIDTH_CAR);
		} else if (dataBridge4[0] == 1 && dataBridge4[1] == 42)
		{
			renderTextureFull(ambulanceLeft, renderer, xCar4, yCar4, HEIGHT_CAR, WIDTH_CAR);
		} else if (dataBridge4[0] == 2 && dataBridge4[1] == 41)
		{
			renderTextureFull(carRight, renderer, xCar4, yCar4, HEIGHT_CAR, WIDTH_CAR);
		} else if (dataBridge4[0] == 2 && dataBridge4[1] == 42)
		{
			renderTextureFull(carLeft, renderer, xCar4, yCar4, HEIGHT_CAR, WIDTH_CAR);
		}
		//////////// FIN PUENTE 4 /////////////



		//Update the screen
		SDL_RenderPresent(renderer);
		//Take a quick break after all that hard work
		SDL_Delay(10);
	}

	//Destroy the various items
	//cleanup(background, bridge, renderer, window);
	IMG_Quit();
	SDL_Quit();
	return 0;
}











int main(int argc, char const *argv[])
{
  
	struct thread_data *td1Left = malloc(sizeof(struct thread_data));
	struct thread_data *td2Left = malloc(sizeof(struct thread_data));
	struct thread_data *td3Left = malloc(sizeof(struct thread_data));
	struct thread_data *td4Left = malloc(sizeof(struct thread_data));

	struct thread_data *td1Right = malloc(sizeof(struct thread_data));
	struct thread_data *td2Right = malloc(sizeof(struct thread_data));
	struct thread_data *td3Right = malloc(sizeof(struct thread_data));
	struct thread_data *td4Right = malloc(sizeof(struct thread_data));


	td1Left->thread_initial_id = 0*NUM_CARS;
	td2Left->thread_initial_id = 1*NUM_CARS;
	td3Left->thread_initial_id = 2*NUM_CARS;
	td4Left->thread_initial_id = 3*NUM_CARS;

	td1Right->thread_initial_id = 4*NUM_CARS;
	td2Right->thread_initial_id = 5*NUM_CARS;
	td3Right->thread_initial_id = 6*NUM_CARS;
	td4Right->thread_initial_id = 7*NUM_CARS;

	td1Left->numberBridge = 11;
	td2Left->numberBridge = 21;
	td3Left->numberBridge = 31;
	td4Left->numberBridge = 41;

	td1Right->numberBridge = 12;
	td2Right->numberBridge = 22;
	td3Right->numberBridge = 32;
	td4Right->numberBridge = 42;


	forceBridge = (int*)calloc(4,sizeof(int));
	forceBridge[0] = 0;
	forceBridge[1] = 0;
	forceBridge[2] = 0;
	forceBridge[3] = 0;

	//int type_sched = configure();
	initColas();
	srand(time(NULL));
	configure();
	configure_bridges();

	//long* t = (long*)malloc( sizeof(long));
	//*t = 0;
	pthread_t generator_izq1;
	pthread_t generator_izq2;
	pthread_t generator_izq3;
	pthread_t generator_izq4;

	pthread_t generator_der1;
	pthread_t generator_der2;
	pthread_t generator_der3;
	pthread_t generator_der4;



	mythread_create(&generator_izq1, NULL, generateCars, (void *)td1Left,0);
	usleep(100);
	mythread_create(&generator_izq2, NULL, generateCars, (void *)td2Left,0);
	usleep(100);
	mythread_create(&generator_izq3, NULL, generateCars, (void *)td3Left,0);
	usleep(100);
	mythread_create(&generator_izq4, NULL, generateCars, (void *)td4Left,0);
	usleep(100);

	mythread_create(&generator_der1, NULL, generateCars, (void *)td1Right,0);
	usleep(100);
	mythread_create(&generator_der2, NULL, generateCars, (void *)td2Right,0);
	usleep(100);
	mythread_create(&generator_der3, NULL, generateCars, (void *)td3Right,0);
	usleep(100);
	mythread_create(&generator_der4, NULL, generateCars, (void *)td4Right,0);
	usleep(100);

	//create thread of scheduler
	pthread_t thread_scheduler;
	int* unused = (int*)malloc(sizeof(int));
	*unused = 0;
	mythread_create(&thread_scheduler, NULL, run_sched, (void*)unused,0);

	//dataBridge1 = getDataBridge(1);
	//dataBridge2 = getDataBridge(2);
	//dataBridge3 = getDataBridge(3);
	//dataBridge4 = getDataBridge(4);
	if (getFisicOn())
	{
		printf("Parte Fisica ejecutando...\n");
		pthread_t thread_physique;
		int* unused3 = (int*)malloc(sizeof(int));
		*unused3 = 0;
	}
	//create thread of the GUI
	if (getGuiOn())
	{
		pthread_t thread_GUI;
		int* unused2 = (int*)malloc(sizeof(int));
		*unused2 = 0;
		mythread_create(&thread_GUI, NULL, runGUI, (void*)unused2,0);
	  	mythread_create(&thread_physique, NULL, runPhysique, (void*)unused3,0);
	}
	//runPhysique(dataBridge1, dataBridge2, dataBridge3);

	pthread_exit(NULL); //the last this main should do
	return 0;
}



//https://www.xmple.com/wallpaper/blue-white-stripes-lines-streaks-1800x2880-c2-0000cd-ffffff-l2-265-530-a-270-f-1.svg
