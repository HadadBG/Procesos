#include<stdio.h>
#include"lista.h"
#include<string.h>


void listadob :: extraer(int pos){
	int i;
	if(iniciol==NULL){
		printf("Error:lista vacia\n");
	}
	else{
		if(pos==-1){
			if(finl==iniciol){
				delete(iniciol);
				iniciol=NULL;
				finl=NULL;
				apun=NULL;
			}
			else {
			
			aux1=finl;
			
			finl=finl->ant;
			delete(auxl);
			
			finl->sig=NULL;
		}
			return;
		}
		aux1=iniciol;
		
		if(aux1->sig == NULL){
			if(pos<1){
			//free(aux1->dato);
			delete (aux1);
			iniciol=NULL;
			apun=NULL;
		}
		else{
			printf("Posicion invalida\n");
			return;
		}
		}
		
		else{
		
		for(i=0;(i!=pos-1) and (aux1->sig->sig!=NULL);i++){
			aux1=aux1->sig;
		}
		if(i+1<pos){
			printf("Posicion invalida\n");
		}
		else{
			if(pos==0){
				aux1=iniciol;
				iniciol=iniciol->sig;
				iniciol->ant=NULL;
				delete (aux1);	
			}
			else{
				
				auxl=aux1->sig->sig;
				auxl->ant=aux1;
				if(finl == aux1->sig){
					finl=aux1->sig->ant;
				}
				delete(aux1->sig);
				aux1->sig=auxl;
			}
		}
		}
	}
	}
	
	void listadob :: extraer(){
	if(!strcasecmp("pila",tipo)){
		extraer(-1);
	}
	else if(!strcasecmp("cola",tipo)){
		extraer(0);
	}

}

dato* listadob::muestra(){

	auxl=iniciol;
	
	if(iniciol==NULL){
		printf("Lista vacia\n");
}

else{
	
	if(!strcasecmp("lista",tipo) || !strcasecmp("cola",tipo)){
	while(auxl != NULL){
	auxl->val->imprime();
	auxl=auxl->sig;
}
	return NULL;
}
/*
	else if(!strcasecmp("cola",tipo)){
		return iniciol->val;
		//iniciol->val->imprime();
	}
	*/
	
	else if(!strcasecmp("pila",tipo)){
	
		
		while(auxl->sig != NULL){
			auxl=auxl->sig;
		}
		return auxl->val;
		//auxl->val->imprime();
	}
	
}
}
void listadob :: insertar(dato* val){
	
	auxl=new nodo();
		
	if(auxl==NULL){
		printf("Hubo un error en la creacion del nodo\n");
		return;
	}	
		auxl->val->copia(val);
	
//	copi(val,auxl->dato);
	if(iniciol==NULL){
		finl=auxl;
		iniciol=auxl;
		apun=auxl;
		auxl->sig=NULL;
		auxl->ant=NULL;
	}
	else{
		finl->sig=auxl;
		auxl->ant=finl;
		auxl->sig=NULL;
		finl=auxl;
	}
	
} 

void listadob::recorre(){
	if(strcasecmp("cola",tipo)){
		printf("Operacion invlaida");
}
	else if(apun==finl){
		apun=iniciol;
	}
	else{
		apun=apun->sig;
}		
}
void listadob::muestrap(){
	int aux=0,i;	
	auxl=iniciol;
	while(auxl != NULL){
		auxl=auxl->sig;
		aux++;
	}

	printf(" _");
	for(i=0;i<aux;i++){
		printf("    ____");
	}
	printf("\n|_|");
	auxl=iniciol;
	while(auxl!= NULL){
		printf("<-| %s |",auxl->val->nombre);
		auxl=auxl->sig;
	}
	printf("\n");
}



apu_nodo listadob::get(int n){
	auxl=iniciol;
	int i;
	
	for(i=0;i<n;i++){
		if(auxl== NULL){
			printf("Error en los limites de la lista");
			return finl;
		}
		auxl=auxl->sig;
	}
	return auxl;
}

void listadob::ordena(int ini,int fin){
	
	int i=ini,j=ini,k;
	dato *p;
	apu_nodo aux;
	p=get(fin)->val;
	while(get(j)->val->ismenor(p)  && j<fin){
		j++;
	}
	if(j!=fin){
	i=j;

	while(i<fin && i<fin){
		
		if(!get(i)->val->ismenor(p)){
			i++;
		}
		else{
			interc(get(j),get(i));
			while(get(j)->val->ismenor(p) && j<fin){
				j++;
	}
		}
	}
}
	if(get(fin)->val->ismenor(get(j)->val)){
			interc(get(fin),get(j));
}
	if(ini<j){
		ordena(ini,j-1);
	}
	if(j<fin){
	
		ordena(j+1,fin);
	}

		
	}
void listadob::interc(apu_nodo a,apu_nodo b){
			apu_nodo aux;
			auxl=a;
			aux=b;
			aux1=auxl->sig;
			if(aux->sig==auxl){
				auxl->sig=aux;
			}
			else{
				auxl->sig=aux->sig;
			}
			if(aux==aux1){
				aux->sig=auxl;
			}
			else{
				aux->sig=aux1;
			}

			aux1=auxl->ant;
			if(aux->ant==auxl){
				auxl->ant=aux;
			}
			else{
				auxl->ant=aux->ant;
			}
			if(aux==aux1){
				aux->ant=auxl;
			}else{
				aux->ant=aux1;
			}
			if(auxl== iniciol)
				iniciol=aux;
			else if(aux==iniciol)
				iniciol=auxl;
			if(auxl==finl)
				finl=aux;
			else if(aux==finl)
				finl=auxl;
			if(aux != iniciol)
				aux->ant->sig=aux;
			if(aux != finl)
				aux->sig->ant=aux;
			if(auxl != iniciol)
				auxl->ant->sig=auxl;
			if(auxl != finl)
				auxl->sig->ant=auxl;
			
}
	



