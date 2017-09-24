#include "managerThread.h"

struct nodo *_primero, *_ultimo;

void append(int elemento) {
     struct nodo *_nuevo;
 	
    /* se reserva memoria para el nuevo elemento */
    _nuevo = (struct nodo *) malloc (sizeof(struct nodo));
    if (_nuevo==NULL) printf( "No hay memoria disponible!\n");
 
    //printf("\nNuevo elemento:\n");
    //printf("el valor id: "); fflush(stdout);
    //gets(nuevo->idThread);
    _nuevo->idThread = elemento;
    _nuevo->siguiente = NULL;
 
    if (_primero==NULL) {
    	//printf( "Primer elemento\n");
        _primero = _nuevo;
        _ultimo = _nuevo;
        }
    else {
        _ultimo->siguiente = _nuevo;
        _ultimo = _nuevo;
      }
 }

void push(int elemento){
	struct nodo *_nuevo;
 	
    /* se reserva memoria para el nuevo elemento */
    _nuevo = (struct nodo *) malloc (sizeof(struct nodo));
    if (_nuevo==NULL) printf( "No hay memoria disponible!\n");
 
    //printf("\nNuevo elemento:\n");
    //printf("el valor id: "); fflush(stdout);
    //gets(nuevo->idThread);
    _nuevo->idThread = elemento;
    _nuevo->siguiente = NULL;
 
    if (_primero==NULL) {
    	//printf( "Primer elemento\n");
        _primero = _nuevo;
        _ultimo = _nuevo;
        }
    else {
        _nuevo->siguiente = _primero;
        _primero = _nuevo;
      }
}

Nodo pop (){
	struct nodo *_temporal; /* lo usamos para recorrer la lista */
	_temporal = _primero;
	_primero = _temporal->siguiente;
	_temporal->siguiente = NULL;
	return _temporal;
}

void mostrar_lista() {
      struct nodo *_auxiliar; /* lo usamos para recorrer la lista */
      int i;
 
      i=0;
      _auxiliar = _primero;
      printf("\nMostrando la lista completa:\n");
      while (_auxiliar!=NULL) {
            printf( "idTread: %d\n", _auxiliar->idThread);
            _auxiliar = _auxiliar->siguiente;
            i++;
      }
      if (i==0) printf( "\nLa lista está vacía!!\n" );
 }