/*******************************************
Fecha: 26 marzo 2025
Autor: Santiago Camargo
Tema: Taller Arboles
Estructuras de datos
******************************************/
#ifndef __NODO__H__
#define __NODO__H__

#include <utility>  // Para std::pair

using namespace std;

/**
 * @class Nodo
 * @brief Representa un nodo en una estructura de árbol cuaternario (QuadTree).
 * 
 * @tparam T Tipo de datos que almacena el nodo (se espera que sea un tipo numérico o comparable).
 */
template<class T>
class Nodo {
protected:
    pair<T, T> dato; ///< Par de valores almacenado en el nodo (puede representar coordenadas en 2D).
    Nodo<T>* NW; ///< Puntero al nodo hijo en la dirección Noroeste.
    Nodo<T>* NE; ///< Puntero al nodo hijo en la dirección Noreste.
    Nodo<T>* SW; ///< Puntero al nodo hijo en la dirección Suroeste.
    Nodo<T>* SE; ///< Puntero al nodo hijo en la dirección Sureste.

public:
    /**
     * @brief Constructor por defecto del nodo.
     * Inicializa los punteros hijos en nullptr.
     */
    Nodo();

    /**
     * @brief Constructor con valor inicial.
     * @param val Par de valores que se almacenarán en el nodo.
     */
    Nodo(pair<T, T> val);

    /**
     * @brief Calcula la altura del árbol desde este nodo.
     * @return Altura del árbol.
     */
    int altura();

    /**
     * @brief Calcula el tamaño del árbol desde este nodo.
     * @return Número de nodos en el árbol.
     */
    int tamano();

    /**
     * @brief Obtiene el dato almacenado en el nodo.
     * @return Par de valores almacenado en el nodo.
     */
    pair<T, T> obtenerDato();

    /**
     * @brief Asigna un nuevo valor al nodo.
     * @param val Nuevo par de valores a almacenar en el nodo.
     */
    void fijarDato(pair<T, T> val);

    /**
     * @brief Inserta un nuevo valor en la estructura de árbol cuaternario.
     * @param val Par de valores a insertar.
     */
    void insertar(pair<T, T> val);

    /**
     * @brief Busca un valor dentro de la estructura del árbol.
     * @param val Par de valores a buscar.
     * @return Puntero al nodo encontrado, o nullptr si el valor no existe en el árbol.
     */
    Nodo* buscar(pair<T, T> val);

    /**
     * @brief Realiza un recorrido en preorden del árbol.
     * Imprime o procesa los nodos en el orden: raíz → hijos.
     */
    void preOrden();

    /**
     * @brief Realiza un recorrido en posorden del árbol.
     * Imprime o procesa los nodos en el orden: hijos → raíz.
     */
    void posOrden();
};

#endif // __NODO__H__


#include "Nodo.hxx"
#endif
