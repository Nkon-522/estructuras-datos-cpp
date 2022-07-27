#ifndef _LISTA_H
#define _LISTA_H

#include <iostream>
#include "Nodo.h"
using namespace std;

class Lista{
    protected:
        Nodo* primero;
    public:
        Lista(){
            primero = nullptr;
        }
        
        void crearLista();
        void insertarCabezaLista(Dato<> entrada);
        void visualizar();
        void insertarUltimo(Dato<> entrada);
        void insertarLista(Nodo* anterior, Dato<> entrada);

        Nodo* ultimo();
        Nodo* buscarLista(Dato<> destino);
        Nodo* buscarPosicion(int posicion);

        void eliminar(Dato<> entrada);

        ~Lista(){
            Nodo* current = primero;
            while(current != nullptr){    
                Nodo* sgte = current->enlaceNodo();
                delete current;
                current = sgte;
            }
        }
};

void Lista::crearLista(){
    Dato<> x;
    primero = nullptr;
    cout<<"Termina con -1"<<endl;
    do{
        cin>>x;
        if(x!=-1){
            primero = new Nodo(x, primero);
        }
    }while(x != -1);
};

void Lista::insertarCabezaLista(Dato<> entrada){
    Nodo* nuevo;
    nuevo = new Nodo(entrada); 
    nuevo -> ponerEnlace(primero); // enlaza nuevo con primero
    primero = nuevo; // mueve primero y apunta al nuevo nodo
}

void Lista::visualizar(){
    Nodo* n;
    n = primero;
    while (n != nullptr){
        cout<<n->datoNodo()<<" "<<endl;
        n = n->enlaceNodo();
    }
}

void Lista::insertarUltimo(Dato<> entrada){
    Nodo* ultimo = this->ultimo();
    ultimo->ponerEnlace(new Nodo(entrada));
}

void Lista::insertarLista(Nodo *anterior, Dato<> entrada){
    Nodo *nuevo;
    nuevo = new Nodo(entrada);
    nuevo -> ponerEnlace(anterior -> enlaceNodo());
    anterior -> ponerEnlace(nuevo);
}

Nodo* Lista::ultimo(){
    Nodo* p = primero;
    if(p == nullptr){throw "Error, lista vacia";}
    while(p -> enlaceNodo() != nullptr){p = p->enlaceNodo();}
    return p;
}

Nodo* Lista::buscarLista(Dato<> destino){
    Nodo* indice;
    for(indice=primero; indice!=nullptr; indice=indice->enlaceNodo()){
        if(destino==indice->datoNodo()){
            return indice;
        }
    }
    return nullptr;
}

Nodo* Lista::buscarPosicion(int posicion){
    Nodo *indice;
    int i;
    if(0 >= posicion){return nullptr;}
    indice = primero;
    for(i = 1; (i<posicion) && (indice != nullptr); i++){indice = indice->enlaceNodo();}
    return indice;
}

void Lista::eliminar(Dato<> entrada){
    Nodo *actual, *anterior;
    bool encontrado;

    actual = primero;
    anterior = nullptr;
    encontrado = false;

    while((actual != nullptr) && !encontrado){
        encontrado = (actual -> datoNodo() == entrada);
        if(!encontrado){
            anterior = actual;
            actual = actual -> enlaceNodo();
        }
    }

    if (actual != nullptr){
        if(actual == primero){
            primero = actual -> enlaceNodo();
        }else{
            anterior -> ponerEnlace(actual -> enlaceNodo());
        }
        delete actual;
    }
}

#endif
