#ifndef _NODO_H
#define _NODO_H

#include <iostream>
using namespace std;

template<typename T=int>
using Dato = T;

class Nodo{
    protected:
        Dato<> dato;
        Nodo* enlace;
    public:
        Nodo(Dato<> t){
            dato = t;
            enlace = nullptr;
        }

        Nodo(Dato<> p, Nodo *n){
            dato = p;
            enlace = n;
        }

        Dato<> datoNodo() const{
            return dato;
        }

        Nodo* enlaceNodo() const{
            return enlace;
        }

        void ponerEnlace(Nodo* sgte){
            enlace = sgte;
        }
};

#endif
