/*******************************************
Fecha: 26 marzo 2025
Autor: Santiago Camargo
Tema: Taller Arboles
Estructuras de datos
******************************************/
#include "Nodo.h"

/**
 * @brief Constructor por defecto de la clase Nodo.
 * Inicializa los punteros a hijos en nullptr.
 */
template<class T>
Nodo<T>::Nodo() {
    this->NW = nullptr;
    this->NE = nullptr;
    this->SW = nullptr;
    this->SE = nullptr;
}

/**
 * @brief Constructor que inicializa un nodo con un valor.
 * @param val Par de valores que representa el dato del nodo.
 */
template<class T>
Nodo<T>::Nodo(pair<T, T> val) {
    this->dato = val;
    this->NW = nullptr;
    this->NE = nullptr;
    this->SW = nullptr;
    this->SE = nullptr;
}

/**
 * @brief Obtiene el dato almacenado en el nodo.
 * @return Par de valores almacenado en el nodo.
 */
template<class T>
pair<T, T> Nodo<T>::obtenerDato() {
    return this->dato;
}

/**
 * @brief Establece un nuevo valor en el nodo.
 * @param val Par de valores a almacenar en el nodo.
 */
template<class T>
void Nodo<T>::fijarDato(pair<T, T> val) {
    this->dato = val;
}

/**
 * @brief Calcula la altura del árbol a partir del nodo actual.
 * @return Altura del árbol.
 */
template<class T>
int Nodo<T>::altura() {
    if (NW == nullptr && NE == nullptr && SW == nullptr && SE == nullptr)
        return 1; // Un nodo sin hijos tiene altura 1

    int mayor = 0, actual;
    
    // Se verifica cada subárbol y se determina el de mayor altura
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

/**
 * @brief Calcula el tamaño del árbol a partir del nodo actual.
 * @return Número total de nodos en el árbol.
 */
template<class T>
int Nodo<T>::tamano() {
    if (NW == nullptr && NE == nullptr && SW == nullptr && SE == nullptr)
        return 1; // Un nodo sin hijos cuenta como 1

    int cont = 1;  // Contamos el nodo actual
    
    // Se suman los tamaños de los subárboles si existen
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

/**
 * @brief Inserta un nuevo nodo en la estructura del árbol cuaternario.
 * @param val Par de valores a insertar.
 */
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

/**
 * @brief Busca un nodo con el valor especificado en el árbol.
 * @param val Par de valores a buscar.
 * @return Puntero al nodo encontrado o nullptr si no existe.
 */
template<class T>
Nodo<T>* Nodo<T>::buscar(pair<T, T> val) {
    if (this->dato == val)
        return this; // Nodo encontrado

    if (NW == nullptr && NE == nullptr && SW == nullptr && SE == nullptr)
        return nullptr; // No hay más nodos donde buscar

    if (this->dato.first < val.first) {
        if (this->dato.second < val.second) {
            if (this->NE != nullptr)
                return this->NE->buscar(val);
        } else {
            if (this->SE != nullptr)
                return this->SE->buscar(val);
        }
    }

    if (this->dato.first > val.first) {
        if (this->dato.second < val.second) {
            if (this->NW != nullptr)
                return this->NW->buscar(val);
        } else {
            if (this->SW != nullptr)
                return this->SW->buscar(val);
        }
    }

    return nullptr; // Nodo no encontrado
}

/**
 * @brief Realiza un recorrido en preorden e imprime los valores.
 * Imprime el nodo actual, seguido de sus hijos en orden NW, NE, SW, SE.
 */
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

/**
 * @brief Realiza un recorrido en posorden e imprime los valores.
 * Recorre primero los hijos en orden NW, NE, SW, SE, y luego imprime el nodo actual.
 */
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




