#include"dato.h"
#ifndef LISTA_H
#define LISTA_H


class nodo {
	
	public:
	dato* val;
	nodo(){val=new dato();}
	nodo *ant;
	nodo *sig;
};

typedef nodo *apu_nodo;

/*tipos:
	pila
	lista
	cola
*/


class listadob{
	public:
	const char * tipo;
	apu_nodo finl,iniciol,auxl,aux1,apun;
	listadob(const char *tipop){iniciol=NULL;finl=NULL;tipo=tipop;apun=NULL;}
	void insertar(dato*);
	dato* muestra();
	void muestrap();
	void extraer(int pos);
	void extraer();
	void recorre();
	void ordena(int ini,int fin);
	apu_nodo get(int n);
	void interc(apu_nodo a,apu_nodo b);
};
#endif

