#include "managerThread.h"

struct nodo *_primero, *_ultimo;

void append(long id, short type_car, short velocity, short priorit, long time) {
     struct nodo *_nuevo;
 	
    /* se reserva memoria para el nuevo elemento */
    _nuevo = (struct nodo *) malloc (sizeof(struct nodo));
    if (_nuevo==NULL) printf( "No hay memoria disponible!\n");
 
    //printf("\nNuevo elemento:\n");
    //printf("el valor id: "); fflush(stdout);
    //gets(nuevo->idThread);
    _nuevo->idThread = id;
    _nuevo->type_of_car = type_car;
    _nuevo->speed = velocity;
    _nuevo->priority = priorit;
    _nuevo->time_limit = time;
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

void insert(int position, long id, short type_car, short velocity, short priorit, long time){
	struct nodo *_nuevo, *_actual,*_sigNodo;
 	
    /* se reserva memoria para el nuevo elemento */
    _nuevo = (struct nodo *) malloc (sizeof(struct nodo));
    if (_nuevo==NULL) printf( "No hay memoria disponible!\n");

    _nuevo->idThread = id;
    _nuevo->type_of_car = type_car;
    _nuevo->speed = velocity;
    _nuevo->priority = priorit;
    _nuevo->time_limit = time;
    _nuevo->siguiente = NULL;

     if (_primero==NULL) {
    	
        _primero = _nuevo;
        _ultimo = _nuevo;
        }
    else {

    	int i = 0; 
    	_actual = _primero;
    	_sigNodo = _actual->siguiente;
    	while(_sigNodo!=NULL){
    		if (i == (position-1) || position==0)
    		{
    			if (position==0)
    			{
    				_nuevo->siguiente= _actual;
    			}
    			else{
    				_actual->siguiente = _nuevo;
    				_nuevo->siguiente = _sigNodo; 
    			}
    			i++;
    		}
    		else{
    			_actual= _sigNodo;
    			_sigNodo = _actual->siguiente;
    			i++;
    		}

    	}
    }
}

Nodo searchNodo(long id){
	struct nodo *_auxiliar; /* lo usamos para recorrer la lista */
    int i;
 
    i=0;
    _auxiliar = _primero;
    while (_auxiliar!=NULL) {
        if (_auxiliar->idThread == id)
        {
           	return _auxiliar;
        }
        else{
           	_auxiliar = _auxiliar->siguiente;
            i++;
        }
            
    }
    if (i==0) printf( "\nLa lista está vacía!!\n" );
    if (_auxiliar==NULL){
    	printf( "\nNo se encontro el nodo con la informacion\n" );
    	return _auxiliar;
    } 
}

int searchPositionId(long id){
	struct nodo *_auxiliar; /* lo usamos para recorrer la lista */
    int i;
 
    i=0;
    _auxiliar = _primero;
    while (_auxiliar!=NULL) {
        if (_auxiliar->idThread == id)
        {
           	return i;
        }
        else{
           	_auxiliar = _auxiliar->siguiente;
            i++;
        }      
    }
    if (i==0) printf( "\nLa lista está vacía!!\n" );
    if (_auxiliar==NULL){
    	printf( "\nNo se encontro el nodo con la informacion\n" );
    	return 0;
    } 
}

int searchPositionSpeed(short velocity){
	struct nodo *_auxiliar; /* lo usamos para recorrer la lista */
    int i;
 
    i=0;
    _auxiliar = _primero;
    while (_auxiliar!=NULL) {
        if (_auxiliar->speed <= velocity)
        {
           	return i;
        }
        else{
           	_auxiliar = _auxiliar->siguiente;
            i++;
        }      
    }
    if (i==0) {
    	printf( "\nLa lista está vacía!!\n" );
    }
    if (_auxiliar==NULL){
    	printf( "\nNo se encontro el nodo con la informacion\n" );
    	return i;
    } 
}

int searchPositionTimeLim(long time){
	struct nodo *_auxiliar; /* lo usamos para recorrer la lista */
    int i;
 
    i=0;
    _auxiliar = _primero;
    while (_auxiliar!=NULL) {
        if (_auxiliar->time_limit >= time)
        {
           	return i;
        }
        else{
           	_auxiliar = _auxiliar->siguiente;
            i++;
        }      
    }
    if (i==0) {
    	printf( "\nLa lista está vacía!!\n" );
    }
    if (_auxiliar==NULL){
    	printf( "\nNo se encontro el nodo con la informacion\n" );
    	return i;
    } 
}

int searchPositionPriority(short priorit){
	struct nodo *_auxiliar; /* lo usamos para recorrer la lista */
    int i;
 
    i=0;
    _auxiliar = _primero;
    while (_auxiliar!=NULL) {
        if (_auxiliar->priority >= priorit)
        {
           	return i;
        }
        else{
           	_auxiliar = _auxiliar->siguiente;
            i++;
        }      
    }
    if (i==0) {
    	printf( "\nLa lista está vacía!!\n" );
    }
    if (_auxiliar==NULL){
    	printf( "\nNo se encontro el nodo con la informacion\n" );
    	return i;
    } 
}




void push(long id, short type_car, short velocity, short priorit, long time){
	struct nodo *_nuevo;
 	
    /* se reserva memoria para el nuevo elemento */
    _nuevo = (struct nodo *) malloc (sizeof(struct nodo));
    if (_nuevo==NULL) printf( "No hay memoria disponible!\n");
 
    _nuevo->idThread = id;
    _nuevo->type_of_car = type_car;
    _nuevo->speed = velocity;
    _nuevo->priority = priorit;
    _nuevo->time_limit = time;
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
            printf( "type_of_car: %d\n",  _nuevo->type_of_car);
            printf( "speed: %d\n", _auxiliar->speed);
            printf( "priority: %d\n", _auxiliar->priority);
            printf( "time_limit: %d\n", _auxiliar->time_limit);
            _auxiliar = _auxiliar->siguiente;
            i++;
      }
      if (i==0) printf( "\nLa lista está vacía!!\n" );
 }