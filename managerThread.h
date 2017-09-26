#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int idThread;
    struct nodo *siguiente;
} *Nodo;


void push(int elemento);   //agrega al inicio de la lista
void append(int elemento); //agrega al final de la lista
Nodo pop ();               //saca el primero de la lista
void mostrar_lista();      // muestra el contenido de la lista
void insert(int position, int elemento); //inserta un elemento en la lista en una posicion especifica
Nodo serchNodo(int data);     // busca un nodo respecto a su dato.
int serchNodoPosition(int data);  //se busca una posicion con respecto a su elemento 
int serchNodoPositionHigh(int data);  //se busca una posicion con respecto al elemento
									  //pero esta posicion va a ser la posicion justamente donde sea mayor