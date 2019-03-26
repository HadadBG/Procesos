#include"dato.h"
#include<stdio.h>
void dato::copia(dato* nval){
	nombre=nval->nombre;
	dur=nval->dur;
	lleg=nval->lleg;
	t_ej=nval->t_ej;
}
void dato::imprime(){
	printf("Proceso %s,H_lleg:%d,Duracion:%d\n",nombre,lleg,dur);
}
bool dato::ismenor(dato* a){
	return(lleg<a->lleg);
}
