#include "managerThread.h"


Cola getANewCola(){
    Cola _nuevaCola;    
    struct nodo* _nuevo = (Nodo) malloc (sizeof(Nodo));
    _nuevo->idThread = -1;
    _nuevaCola = (Cola) malloc (sizeof(Cola));
    _nuevaCola->_primero = _nuevo;
    _nuevaCola->_ultimo  = _nuevo;    
    return _nuevaCola;
}

Cola append(long id, short type_car, short velocity, short priorit, long time, Cola cola) 
{
    
    /* se reserva memoria para el nuevo elemento */
    struct nodo*_nuevo = (struct nodo *) malloc (sizeof(struct nodo));
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
 
    if (cola->_primero->idThread == -1) {
    	//printf( "Primer elemento\n");
        cola->_primero = _nuevo;
        cola->_ultimo  = _nuevo;
    }
    else {
       cola->_ultimo->siguiente = _nuevo;
       cola->_ultimo = _nuevo;
    }
    return cola;
}

Cola insert(int position, long id, short type_car, short velocity, short priorit, long time, Cola cola){
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

     if (cola->_primero->idThread==-1) {
    	
        cola->_primero = _nuevo;
        cola->_ultimo = _nuevo;
        }
    else {
    	int i = 0; 
    	_actual = cola->_primero;
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
    return cola;
}

Nodo searchNodo(long id,Cola cola){
	struct nodo* _auxiliar; /* lo usamos para recorrer la lista */
    int i;
 
    i=0;
    _auxiliar = cola->_primero;
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
    return NULL;
}

int searchPositionId(long id, Cola cola){


	struct nodo* _auxiliar; /* lo usamos para recorrer la lista */
    int i;
 
    i=0;
    _auxiliar = cola->_primero;
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
    return 0;
}

int searchPositionSpeed(short velocity, Cola cola){
	Nodo _auxiliar; /* lo usamos para recorrer la lista */
    int i;
 
    i=0;
    _auxiliar = cola->_primero;
    while (_auxiliar!=NULL) {
        printf("Speed auxiliar: %d\n",_auxiliar->speed);
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
    return 0;
}

int searchPositionTimeLim(long time, Cola cola){
	struct nodo* _auxiliar; /* lo usamos para recorrer la lista */
    int i;
 
    i=0;
    _auxiliar = cola->_primero;
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
    return 0;
}

int searchPositionPriority(short priorit, Cola cola){
	struct nodo* _auxiliar; /* lo usamos para recorrer la lista */
    int i;
 
    i=0;
    _auxiliar = cola->_primero;
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
    return 0;
}




Cola push(long id, short type_car, short velocity, short priorit, long time, Cola cola){
	struct nodo* _nuevo;
 	 
    /* se reserva memoria para el nuevo elemento */
    _nuevo = (struct nodo *) malloc (sizeof(struct nodo));
    if (_nuevo==NULL) printf( "No hay memoria disponible!\n");
 
    _nuevo->idThread = id;
    _nuevo->type_of_car = type_car;
    _nuevo->speed = velocity;
    _nuevo->priority = priorit;
    _nuevo->time_limit = time;
    _nuevo->siguiente = NULL;
 
    if (cola->_primero->idThread==-1) {
    	//printf( "Primer elemento\n");
        cola->_primero = _nuevo;
        cola->_ultimo = _nuevo;
        }
    else {
        _nuevo->siguiente = cola->_primero;
        cola->_primero = _nuevo;
      }
    return cola;
}

Nodo pop (Cola cola){

    Nodo _temporal; /* lo usamos para recorrer la lista */

        _temporal = cola->_primero;
        cola->_primero = _temporal->siguiente;
        _temporal->siguiente = NULL;

	return _temporal;
}

void mostrar_lista(Cola cola) {
      struct nodo* _auxiliar; /* lo usamos para recorrer la lista */
      int i;
 
      i=0;
      _auxiliar = cola->_primero;
      printf("\nMostrando la lista completa:\n");
      while (_auxiliar!=NULL) {
            printf("----------------------------------\n");            
            printf( "idTread: %ld\n", _auxiliar->idThread);
            printf( "type_of_car: %d\n",  _auxiliar->type_of_car);
            printf( "speed: %d\n", _auxiliar->speed);
            printf( "priority: %d\n", _auxiliar->priority);
            printf( "time_limit: %ld\n", _auxiliar->time_limit);
            _auxiliar = _auxiliar->siguiente;
            i++;
      }
      if (i==0) printf( "\nLa lista está vacía!!\n" );
 }