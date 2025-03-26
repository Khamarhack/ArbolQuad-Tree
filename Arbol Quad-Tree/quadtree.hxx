/*******************************************
Fecha: 26 marzo 2025
Autor: Santiago Camargo
Tema: Taller Arboles
Estructuras de datos
******************************************/
#include <bits/stdc++.h>
#include "quadtree.h"

using namespace std;

template<class T>
Arbol<T>::Arbol() {
    this->raiz = nullptr;
}

template<class T>
Arbol<T>::Arbol(pair<T, T> val) {
    this->raiz = new Nodo<T>(val);
}

// Destructor para liberar memoria
template<class T>
Arbol<T>::~Arbol() {
    eliminarTodo(this->raiz);
}

// Función auxiliar para eliminar nodos recursivamente
template<class T>
void Arbol<T>::eliminarTodo(Nodo<T>* nodo) {
    if (nodo == nullptr) return;
    eliminarTodo(nodo->NW);
    eliminarTodo(nodo->NE);
    eliminarTodo(nodo->SW);
    eliminarTodo(nodo->SE);
    delete nodo;
}

template<class T>
bool Arbol<T>::esVacio() {
    return this->raiz == nullptr;
}

template<class T>
pair<T, T> Arbol<T>::obtenerRaiz() {
    if (this->raiz != nullptr)
        return this->raiz->obtenerDato();
    throw runtime_error("El árbol está vacío.");
}

template<class T>
void Arbol<T>::fijarRaiz(Nodo<T>* root) {
    this->raiz = root;
}

template<class T>
int Arbol<T>::altura() {
    return this->raiz ? this->raiz->altura() : 0;
}

template<class T>
int Arbol<T>::tamano() {
    return this->raiz ? this->raiz->tamano() : 0;
}

template<class T>
void Arbol<T>::insertar(pair<T, T> val) {
    if (this->raiz)
        this->raiz->insertar(val);
    else
        this->raiz = new Nodo<T>(val);
}

template<class T>
Nodo<T>* Arbol<T>::buscar(pair<T, T> val) {
    return this->raiz ? this->raiz->buscar(val) : nullptr;
}

template<class T>
void Arbol<T>::preOrden() {
    if (this->raiz)
        this->raiz->preOrden();
    else
        cout << "El árbol está vacío." << endl;
}

template<class T>
void Arbol<T>::posOrden() {
    if (this->raiz)
        this->raiz->posOrden();
    else
        cout << "El árbol está vacío." << endl;
}

