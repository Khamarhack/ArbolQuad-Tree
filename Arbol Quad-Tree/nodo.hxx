/*******************************************
Fecha: 26 marzo 2025
Autor: Santiago Camargo
Tema: Taller Arboles
Estructuras de datos
******************************************/
#include "Nodo.h"

// Constructor por defecto
template<class T>
Nodo<T>::Nodo() {
    this->NW = nullptr;
    this->NE = nullptr;
    this->SW = nullptr;
    this->SE = nullptr;
}

// Constructor con dato inicial
template<class T>
Nodo<T>::Nodo(pair<T, T> val) {
    this->dato = val;
    this->NW = nullptr;
    this->NE = nullptr;
    this->SW = nullptr;
    this->SE = nullptr;
}

// Destructor para liberar memoria
template<class T>
Nodo<T>::~Nodo() {
    delete NW;
    delete NE;
    delete SW;
    delete SE;
}

// Obtener el dato almacenado en el nodo
template<class T>
pair<T, T> Nodo<T>::obtenerDato() {
    return this->dato;
}

// Asignar un nuevo dato al nodo
template<class T>
void Nodo<T>::fijarDato(pair<T, T> val) {
    this->dato = val;
}

// Calcular la altura del árbol desde este nodo
template<class T>
int Nodo<T>::altura() {
    int alturaNW = (NW != nullptr) ? NW->altura() : 0;
    int alturaNE = (NE != nullptr) ? NE->altura() : 0;
    int alturaSW = (SW != nullptr) ? SW->altura() : 0;
    int alturaSE = (SE != nullptr) ? SE->altura() : 0;
    return 1 + std::max({alturaNW, alturaNE, alturaSW, alturaSE});
}

// Calcular el tamaño del árbol desde este nodo
template<class T>
int Nodo<T>::tamano() {
    int cont = 1; // Contamos el nodo actual
    if (NW != nullptr) cont += NW->tamano();
    if (NE != nullptr) cont += NE->tamano();
    if (SW != nullptr) cont += SW->tamano();
    if (SE != nullptr) cont += SE->tamano();
    return cont;
}

// Insertar un nuevo nodo en la estructura
template<class T>
void Nodo<T>::insertar(pair<T, T> val) {
    if (this->dato == val) {
        return; // Evitar duplicados
    }
    
    // Determinar el cuadrante adecuado para insertar
    if (this->dato.first < val.first) {
        if (this->dato.second < val.second) {
            if (this->NE != nullptr) {
                this->NE->insertar(val);
            } else {
                this->NE = new Nodo(val);
            }
        } else {
            if (this->SE != nullptr) {
                this->SE->insertar(val);
            } else {
                this->SE = new Nodo(val);
            }
        }
    } else {
        if (this->dato.second < val.second) {
            if (this->NW != nullptr) {
                this->NW->insertar(val);
            } else {
                this->NW = new Nodo(val);
            }
        } else {
            if (this->SW != nullptr) {
                this->SW->insertar(val);
            } else {
                this->SW = new Nodo(val);
            }
        }
    }
}

// Buscar un nodo en la estructura
template<class T>
Nodo<T>* Nodo<T>::buscar(pair<T, T> val) {
    if (this->dato == val)
        return this;
    
    if (this->dato.first < val.first) {
        if (this->dato.second < val.second) {
            if (this->NE != nullptr) {
                return this->NE->buscar(val);
            } else {
                return nullptr;
            }
        } else {
            if (this->SE != nullptr) {
                return this->SE->buscar(val);
            } else {
                return nullptr;
            }
        }
    } else {
        if (this->dato.second < val.second) {
            if (this->NW != nullptr) {
                return this->NW->buscar(val);
            } else {
                return nullptr;
            }
        } else {
            if (this->SW != nullptr) {
                return this->SW->buscar(val);
            } else {
                return nullptr;
            }
        }
    }
    return nullptr;
}

// Recorrido en preorden
template<class T>
void Nodo<T>::preOrden() {
    cout << "(" << this->dato.first << ',' << this->dato.second << ")\n";
    if (this->NW != nullptr) this->NW->preOrden();
    if (this->NE != nullptr) this->NE->preOrden();
    if (this->SW != nullptr) this->SW->preOrden();
    if (this->SE != nullptr) this->SE->preOrden();
}

// Recorrido en postorden
template<class T>
void Nodo<T>::posOrden() {
    if (this->NW != nullptr) this->NW->posOrden();
    if (this->NE != nullptr) this->NE->posOrden();
    if (this->SW != nullptr) this->SW->posOrden();
    if (this->SE != nullptr) this->SE->posOrden();
    cout << "(" << this->dato.first << ',' << this->dato.second << ")\n";
}




