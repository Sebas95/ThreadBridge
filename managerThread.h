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
