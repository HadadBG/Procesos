#ifndef DATO_H
#define DATO_H
class proceso{
	public:
		int dur,lleg,t_ej;
		char*nombre;
		void copia(proceso* val);
		void imprime();
		proceso(char*nombre,int dur,int lleg){
			this->nombre=nombre;this->dur=dur;this->lleg=lleg;t_ej=0;}
		proceso(char*nombre){dur=0;lleg=0;this->nombre=nombre;t_ej=0;}
		proceso(){t_ej=0;}
		bool ismenor(proceso*a);
};
typedef proceso dato;

#endif
