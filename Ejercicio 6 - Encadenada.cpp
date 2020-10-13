#include <iostream>
#include <stdlib.h>
using namespace std;

class Celda{
	public:
		int item;
		Celda *next;
	public:
		int getItem(void){
			return(item);
		}
		void setItem(int xitem){
			item=xitem;
		}
		void setNext(Celda *xcelda){
			next=xcelda;
		}
		Celda* getNext(void){
			return(next);
		}
};

class Cola{
	private:
		int size;
		Celda *first;
		Celda *latest;	//no se para que hace falta tener al ultimo de la cola
						//si en definitiva no hay un método que lo muestre
						//y tampoco lo puedo eliminar sin recorrer la lista!
	public:
		Cola(Celda* xfirst=NULL,Celda* xlatest=NULL, int xsize=0):first(xfirst), latest(xlatest),size(xsize){ }
		bool getEmpty(void);
		int insert(int dat);
		int suppress();
		void toShow();
		~Cola();
};

bool Cola::getEmpty(){
	return (size == 0);
}

int Cola::insert(int dat){
	Celda *ps1;
	ps1=new(Celda);
	ps1->setItem(dat);
	ps1->setNext(NULL);
	if (getEmpty()){
		first=ps1;
		latest=ps1;
		size++;
	}
	else{
		latest->setNext(ps1);
		latest=ps1;
		size++;
	}
	return (latest->getItem());
}

int Cola::suppress(){
	Celda *aux;
	int item;
	
	if (getEmpty()){
		puts("La cola esta vacia");
		return (0);
	}
	else{
		item=first->getItem();
		aux=first;
		first=first->getNext();
		free(aux);
		size--;
		if (getEmpty()){
			first=NULL;
			latest=NULL;
		}
		return(item);
	}
}

void Cola::toShow(){
	Celda *aux=first;
	bool flag=1;
	
	if (!getEmpty()){
		while (aux != NULL && flag){
			printf("%d\n", aux->getItem());
			if (aux->getNext() == NULL){
				flag = 0;
			}
			else{
				aux=aux->getNext();
			}
		}	
	}
	else{
		puts("La cola esta vacia");
	}
}

Cola::~Cola(){
	Celda *aux;
	
	aux=first;
	while(first->getNext() != NULL){
		first=first->getNext();
		free(aux);
		aux=first;
	}
}

void test(Cola &unaCola){
	unaCola.insert(10);
	unaCola.insert(20);
	unaCola.insert(30);
	unaCola.insert(40);
	printf("\nElementos de la cola\n");
	printf("---------------------\n");
	unaCola.toShow();
	printf("---------------------\n");
	
	printf("\n%d Eliminado\n", unaCola.suppress());
	printf("%d Eliminado\n", unaCola.suppress());
	
	printf("\nElementos de la cola\n");
	printf("---------------------\n");
	unaCola.toShow();
	printf("---------------------\n");
	
	unaCola.insert(50);
	unaCola.insert(60);
	printf("\nElementos de la cola\n");
	printf("---------------------\n");
	unaCola.toShow();
	printf("---------------------\n");
	
	printf("\n%d Eliminado\n", unaCola.suppress());
	printf("%d Eliminado\n", unaCola.suppress());
	
	printf("\nElementos de la cola\n");
	printf("---------------------\n");
	unaCola.toShow();
	printf("---------------------\n");
	
	printf("\n%d Eliminado\n", unaCola.suppress());
	printf("%d Eliminado\n", unaCola.suppress());
	
	printf("\nElementos de la cola\n");
	printf("---------------------\n");
	unaCola.toShow();
	printf("---------------------\n");
}

int main(){
	Cola unaCola;
	test(unaCola);
}
