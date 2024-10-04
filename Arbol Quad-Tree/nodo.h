/*******************************************
Fecha: 1 octubre 2024
Autor: Santiago Camargo
Tema: Taller Arboles
Estructuras de datos
******************************************/
#ifndef __NODO__H__
#define __NODO__H__

#include <utility>  // Para std::pair

using namespace std;

template<class T>
class Nodo {
protected:
    pair<T, T> dato;
    Nodo<T>* NW;
    Nodo<T>* NE;
    Nodo<T>* SW;
    Nodo<T>* SE;

public:
    Nodo();
    Nodo(pair<T, T> val);

    int altura();
    int tamano();

    pair<T, T> obtenerDato();
    void fijarDato(pair<T, T> val);
    
    void insertar(pair<T, T> val);
    Nodo* buscar(pair<T, T> val);

    void preOrden();
    void posOrden();
};

#include "Nodo.hxx"
#endif
