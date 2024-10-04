/*******************************************
Fecha: 1 octubre 2024
Autor: Santiago Camargo
Tema: Taller Arboles
Estructuras de datos
******************************************/
#include "Nodo.h"

template<class T>
Nodo<T>::Nodo() {
    this->NW = nullptr;
    this->NE = nullptr;
    this->SW = nullptr;
    this->SE = nullptr;
}

template<class T>
Nodo<T>::Nodo(pair<T, T> val) {
    this->dato = val;
    this->NW = nullptr;
    this->NE = nullptr;
    this->SW = nullptr;
    this->SE = nullptr;
}

template<class T>
pair<T, T> Nodo<T>::obtenerDato() {
    return this->dato;
}

template<class T>
void Nodo<T>::fijarDato(pair<T, T> val) {
    this->dato = val;
}

template<class T>
int Nodo<T>::altura() {
    if (NW == nullptr && NE == nullptr && SW == nullptr && SE == nullptr)
        return 1;

    int mayor = 0, actual;
    if (NW != nullptr) {
        actual = this->NW->altura() + 1;
        if (actual > mayor)
            mayor = actual;
    }
    if (NE != nullptr) {
        actual = this->NE->altura() + 1;
        if (actual > mayor)
            mayor = actual;
    }
    if (SW != nullptr) {
        actual = this->SW->altura() + 1;
        if (actual > mayor)
            mayor = actual;
    }
    if (SE != nullptr) {
        actual = this->SE->altura() + 1;
        if (actual > mayor)
            mayor = actual;
    }

    return mayor;
}

template<class T>
int Nodo<T>::tamano() {
    if (NW == nullptr && NE == nullptr && SW == nullptr && SE == nullptr)
        return 1;

    int cont = 1;  // Contamos el nodo actual
    if (NW != nullptr)
        cont += this->NW->tamano();
    if (NE != nullptr)
        cont += this->NE->tamano();
    if (SW != nullptr)
        cont += this->SW->tamano();
    if (SE != nullptr)
        cont += this->SE->tamano();

    return cont;
}

template<class T>
void Nodo<T>::insertar(pair<T, T> val) {
    /* Norte */
    if (this->dato.first < val.first) {
        if (this->dato.second < val.second) {
            if (this->NE != nullptr) {
                this->NE->insertar(val);
            } else {
                Nodo<T>* nuevo = new Nodo();
                nuevo->fijarDato(val);
                this->NE = nuevo;
            }
        } else {
            if (this->SE != nullptr) {
                this->SE->insertar(val);
            } else {
                Nodo<T>* nuevo = new Nodo();
                nuevo->fijarDato(val);
                this->SE = nuevo;
            }
        }
    }
    
    /* Sur */
    if (this->dato.first > val.first) {
        if (this->dato.second < val.second) {
            if (this->NW != nullptr) {
                this->NW->insertar(val);
            } else {
                Nodo<T>* nuevo = new Nodo();
                nuevo->fijarDato(val);
                this->NW = nuevo;
            }
        } else {
            if (this->SW != nullptr) {
                this->SW->insertar(val);
            } else {
                Nodo<T>* nuevo = new Nodo();
                nuevo->fijarDato(val);
                this->SW = nuevo;
            }
        }
    }
}

template<class T>
Nodo<T>* Nodo<T>::buscar(pair<T, T> val) {
    if (this->dato == val)
        return this;
    if (NW == nullptr && NE == nullptr && SW == nullptr && SE == nullptr)
        return nullptr;

    if (this->dato.first < val.first) {
        if (this->dato.second < val.second) {
            if (this->NE != nullptr)
                return this->NE->buscar(val);
            else
                return nullptr;
        } else {
            if (this->SE != nullptr)
                return this->SE->buscar(val);
            else
                return nullptr;
        }
    }

    if (this->dato.first > val.first) {
        if (this->dato.second < val.second) {
            if (this->NW != nullptr)
                return this->NW->buscar(val);
            else
                return nullptr;
        } else {
            if (this->SW != nullptr)
                return this->SW->buscar(val);
            else
                return nullptr;
        }
    }

    return nullptr;
}

template<class T>
void Nodo<T>::preOrden() {
    cout << "(" << this->dato.first << ',' << this->dato.second << ")" << endl;
    if (this->NW != nullptr)
        this->NW->preOrden();
    if (this->NE != nullptr)
        this->NE->preOrden();
    if (this->SW != nullptr)
        this->SW->preOrden();
    if (this->SE != nullptr)
        this->SE->preOrden();
}

template<class T>
void Nodo<T>::posOrden() {
    if (this->NW != nullptr)
        this->NW->posOrden();
    if (this->NE != nullptr)
        this->NE->posOrden();
    if (this->SW != nullptr)
        this->SW->posOrden();
    if (this->SE != nullptr)
        this->SE->posOrden();

    cout << "(" << this->dato.first << ',' << this->dato.second << ")" << endl;
}



