#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    long idThread;
    short type_of_car;
    short speed;
    short priority;
    long time_limit;
    struct nodo *siguiente;
} *Nodo;


void push(long id, short type_car, short velocity, short priorit, long time);   //agrega al inicio de la lista
void append(long id, short type_car, short velocity, short priorit, long time); //agrega al final de la lista
Nodo pop ();               //saca el primero de la lista
void mostrar_lista();      // muestra el contenido de la lista
void insert(int position, long id, short type_car, short velocity, short priorit, long time); //inserta un elemento en la lista en una posicion especifica

Nodo searchNodo(long id);     // busca un nodo respecto a su dato.
int searchPositionId(long id);  //se busca una posicion con respecto a su id 

int searchPositionSpeed(short velocity);  //se busca una posicion con respecto a la velocidad.
int searchPositionTimeLim(long time);      //retorna una posicion con respecto a el tiempo limite
int searchPositionPriority(short priorit); //retorna una posicion con respecto a la prioridad
