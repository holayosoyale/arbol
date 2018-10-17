#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

struct Nodo{
	int dato;
	Nodo *izquierdo;
	Nodo *derecho;	
};

//Prototipo de la funcion 
void menu();
Nodo *crea_nodo(int);
void insertarNodo(Nodo *&,int);

Nodo *arbol = NULL;


int main(int argc, char** argv) {
	menu();

	
	return 0;
}
//Funcion de menu
void menu(){
	int dato, opcion;
	do{
		cout<<"\t.:Menu:.\n\n"<<endl;
		cout<<" 1. Insertar un nuevo nodo\n";
		cout<<" 2. Salir\n\n";
		cout<<"Opcion: ";
		cin>>opcion;
		
		switch(opcion) {
			case 1: cout<<"Dijite un numero: ";
					cin>>dato;
					insertarNodo(arbol,dato);//insertamos un nuevo nodo
					cout<<"\n";
					system("pause");
					break;
		}system("cls");
	}while(opcion!=2);
}
//Funcion para crear un nodo
Nodo *crearNodo (int n){
	Nodo *nuevo_nodo= new Nodo();
	
	nuevo_nodo->dato=n;
	nuevo_nodo->derecho=NULL;
	nuevo_nodo->izquierdo=NULL;
	
	return nuevo_nodo;
}

//funcion para insertar elementos en el nodo
void insertarNodo(Nodo *&arbol, int n){
	
	if(arbol==NULL){//SI EL ARBOL ESTA VACIO
	Nodo *nuevo_nodo = crearNodo(n);
	arbol = nuevo_nodo;
	}
	
	else {//Si el arbol tiene un nodo o mas
		int valorRaiz= arbol->dato; //obtenemos el valor de la raiz
			
			if(n< valorRaiz){//Si el elemnto es menor a la raiz, insertamos en izq
				insertarNodo(arbol->izquierdo,n);
			}
			else{//Si el elemento es mayor a la raiz, insertamos en derecha
				insertarNodo(arbol->derecho,n);
			}
	}	
}


