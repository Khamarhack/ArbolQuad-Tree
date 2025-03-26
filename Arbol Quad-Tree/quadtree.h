/*******************************************
Fecha: 26 marzo 2025
Autor: Santiago Camargo
Tema: Taller Árboles
Estructuras de datos
******************************************/
#ifndef __QUADTREE__H__
#define __QUADTREE__H__

#include "Nodo.h"

using namespace std;

template<class T>
class Arbol {
protected:
    Nodo<T>* raiz;

public:
    // Constructores
    Arbol();
    Arbol(pair<T, T> val);

    // Destructor para liberar memoria
    ~Arbol();

    // Métodos de acceso
    bool esVacio();
    Nodo<T>* obtenerRaiz();
    void fijarRaiz(Nodo<T>* root);

    // Operaciones del árbol
    void insertar(pair<T, T> val);
    bool eliminar(pair<T, T> val);
    Nodo<T>* buscar(pair<T, T> val);
    int altura();
    int tamano();

    // Recorridos
    void preOrden();
    void posOrden();
};

#include "quadtree.hxx"
#endif
