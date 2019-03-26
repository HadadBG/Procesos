#include<stdio.h>
#include"lista.h"
#include<stdlib.h>
#include<string.h>
void cuenta(FILE* arch,int *np,int *t_chunk,listadob* tiempos);
void llena(FILE *arch,listadob* tiempos,int np,int* t_max);
int T_BUFFER=80;
int main(){
	listadob *tiempos=new listadob("cola");
	FILE *aa=fopen("src/datos","r");
	if(aa==NULL){
		printf("Archivo de datos no encontrado\n");
		return 0;
}
	int t_chunk,np=0;
	int t_actual=0;
	int t_max=0;
	int f=0;
	cuenta(aa,&np,&t_chunk,tiempos);
	llena(aa,tiempos,np,&t_max);
	printf("Datos Ingresados:\n");
	tiempos->muestra();
	tiempos->ordena(0,np-1);
	//tiempos->muestra();
	tiempos->apun=tiempos->iniciol;
	dato* auxi=tiempos->apun->val;
	t_max=t_max+tiempos->apun->val->lleg;
	listadob * lista_proc=new listadob("cola");
	tiempos->apun=tiempos->iniciol;
	
	for(t_actual=0;t_actual<= t_max;t_actual++){
		if(tiempos->apun!= NULL && tiempos->apun->val->lleg <= t_actual){	
			lista_proc->insertar(tiempos->apun->val);
			tiempos->apun=tiempos->apun->sig;
		}
		if(f==0){
			printf("\n\nLista de Procesos(tiempo=%d):\n",t_actual);
			lista_proc->muestrap();
			printf("\n\n");
			if(lista_proc->iniciol!=NULL){
				if(lista_proc->iniciol->val->t_ej == 0){
				printf("%s Aqui estoy\n",lista_proc->iniciol->val->nombre);					
				}
				else{
					printf("Soy el proceso %s \n",lista_proc->iniciol->val->nombre);
					
				}
				lista_proc->iniciol->val->t_ej++;
				f=1;
			}
		}
		
		else if(f==t_chunk){
			if(lista_proc->iniciol->val->t_ej >= lista_proc->iniciol->val->dur ){
				lista_proc->extraer();
			}
			else{
			lista_proc->insertar(lista_proc->iniciol->val);
			lista_proc->extraer();
			f=0;
			}
			printf("\n\nLista de Procesos(tiempo=%d):\n",t_actual);
			lista_proc->muestrap();
			printf("\n\n");
			if(lista_proc->iniciol!=NULL){
				if(lista_proc->iniciol->val->t_ej == 0){
					printf("%s Aqui estoy\n",lista_proc->iniciol->val->nombre);
					
				}
				else{
					printf("Soy el proceso %s \n",lista_proc->iniciol->val->nombre);
				}
					f=1;
					lista_proc->iniciol->val->t_ej++;
			}
			
		}
		else{
			printf("Soy el proceso %s \n",lista_proc->iniciol->val->nombre);
			f++;
			lista_proc->iniciol->val->t_ej++;
			if(lista_proc->iniciol->val->t_ej>= lista_proc->iniciol->val->dur){
				f=t_chunk;
			}
		}
		
			
		}

	printf("\n\nFin de la ejecucion de los procesos(tiempo=%d)",t_actual);
	printf("\n\n");
	return 0;
	
}
void cuenta(FILE* arch,int *np,int *t_chunk,listadob* tiempos){
	char c;
	char *buffer=(char*)malloc(T_BUFFER*sizeof(char));
	dato *aux;
	c=fgetc(arch);
	while (c != ':')
		c=fgetc(arch);
	fscanf(arch,"%s",buffer);
	*t_chunk=atoi(buffer);
	fscanf(arch,"%s",buffer);
	while(strcmp("H_lleg:",buffer)){
		aux=new dato(buffer);
		buffer=(char*)malloc(T_BUFFER*sizeof(char));
		fscanf(arch,"%s",buffer);

		*np=*np+1;
		
		tiempos->insertar(aux);
	}
	free(buffer);
}


void llena(FILE *arch,listadob* tiempos,int np,int *tmax){
	int aux;
	char *buffer=(char*)malloc(T_BUFFER*sizeof(char));
	fscanf(arch,"%s",buffer);
	
	while(strcmp("Dur:",buffer)){

		tiempos->apun->val->lleg=atoi(buffer);
		tiempos->recorre();
		fscanf(arch,"%s",buffer);
	}
	fscanf(arch,"%s",buffer);
	while(!feof(arch)){
		tiempos->apun->val->dur=atoi(buffer);
		tiempos->recorre();
		fscanf(arch,"%s",buffer);
	}
		tiempos->apun->val->dur=atoi(buffer);
		tiempos->recorre();
	while(tiempos->apun!=NULL){
		aux=tiempos->apun->val->dur;
		*tmax=*tmax+aux;
		tiempos->apun=tiempos->apun->sig;
	}
	tiempos->apun=tiempos->iniciol;
	
}


