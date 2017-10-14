#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct nodo {
	pthread_t* thread;
    long idThread;
    short type_of_car;
    short speed;
    short priority;
    long time_limit;
    struct nodo *siguiente;
} *Nodo;

typedef struct cola {
	Nodo _primero;
	Nodo _ultimo;
} *Cola;

Cola getANewCola();
Cola push(long id, short type_car, short velocity, short priorit, long time, pthread_t* thread, Cola cola);   //agrega al inicio de la lista
Cola append(long id, short type_car, short velocity, short priorit, long time , pthread_t* thread, Cola cola) ; //agrega al final de la lista
Nodo pop (Cola cola);               //saca el primero de la lista
void mostrar_lista(Cola cola);      // muestra el contenido de la lista
Cola insert(int position, long id, short type_car, short velocity, short priorit, long time, pthread_t* thread, Cola cola); //inserta un elemento en la lista en una posicion especifica
int listaVacia(Cola cola);
Nodo searchNodo(long id, Cola cola);     // busca un nodo respecto a su dato.
int searchPositionId(long id, Cola cola);  //se busca una posicion con respecto a su id 

int searchPositionSpeed(short velocity, Cola cola);  //se busca una posicion con respecto a la velocidad.
int searchPositionTimeLim(long time, Cola cola);      //retorna una posicion con respecto a el tiempo limite
int searchPositionPriority(short priorit, Cola cola); //retorna una posicion con respecto a la prioridad
int get_length(Cola cola);
