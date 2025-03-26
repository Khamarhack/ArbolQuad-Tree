/*******************************************
Fecha: 26 marzo 2025
Autor: Santiago Camargo
Tema: Taller Arboles
Estructuras de datos
******************************************/
/*******************************************
Fecha: 26 marzo 2025  
Autor: Santiago Camargo  
Tema: Taller Árboles - QuadTree  
Estructuras de datos  
******************************************/

#include <bits/stdc++.h>
#include "quadtree.h"

using namespace std;

/**
 * @brief Constructor por defecto. Inicializa un árbol vacío.
 */
template<class T>
Arbol<T>::Arbol() {
    this->raiz = nullptr;
}

/**
 * @brief Constructor que inicializa el árbol con un nodo raíz.
 * @param val Par de valores (x, y) para la raíz del QuadTree.
 */
template<class T>
Arbol<T>::Arbol(pair<T, T> val) {
    this->raiz = new Nodo<T>(val);
}

/**
 * @brief Destructor de la clase Arbol.  
 * Libera la memoria de todos los nodos del árbol para evitar fugas de memoria.
 */
template<class T>
Arbol<T>::~Arbol() {
    eliminarTodo(this->raiz);
}

/**
 * @brief Función auxiliar para eliminar nodos recursivamente.
 * @param nodo Nodo actual a eliminar.
 */
template<class T>
void Arbol<T>::eliminarTodo(Nodo<T>* nodo) {
    if (nodo == nullptr) return;

    // Eliminar recursivamente los hijos en cada cuadrante
    eliminarTodo(nodo->NW);
    eliminarTodo(nodo->NE);
    eliminarTodo(nodo->SW);
    eliminarTodo(nodo->SE);

    // Eliminar el nodo actual
    delete nodo;
}

/**
 * @brief Verifica si el árbol está vacío.
 * @return `true` si el árbol no tiene nodos, `false` en caso contrario.
 */
template<class T>
bool Arbol<T>::esVacio() {
    return this->raiz == nullptr;
}

/**
 * @brief Obtiene el valor almacenado en la raíz del árbol.
 * @return Un `pair<T, T>` con el valor de la raíz.
 * @throws `runtime_error` si el árbol está vacío.
 */
template<class T>
pair<T, T> Arbol<T>::obtenerRaiz() {
    if (this->raiz != nullptr)
        return this->raiz->obtenerDato();
    throw runtime_error("Error: El árbol está vacío.");
}

/**
 * @brief Establece un nuevo nodo como la raíz del árbol.
 * @param root Puntero al nuevo nodo raíz.
 */
template<class T>
void Arbol<T>::fijarRaiz(Nodo<T>* root) {
    this->raiz = root;
}

/**
 * @brief Calcula la altura del árbol.
 * @return Altura del árbol. Si está vacío, retorna 0.
 */
template<class T>
int Arbol<T>::altura() {
    return this->raiz ? this->raiz->altura() : 0;
}

/**
 * @brief Calcula el número total de nodos en el árbol.
 * @return Cantidad de nodos en el árbol. Si está vacío, retorna 0.
 */
template<class T>
int Arbol<T>::tamano() {
    return this->raiz ? this->raiz->tamano() : 0;
}

/**
 * @brief Inserta un nuevo nodo en el árbol con el valor especificado.
 * @param val Par de valores (x, y) a insertar en el QuadTree.
 */
template<class T>
void Arbol<T>::insertar(pair<T, T> val) {
    if (this->raiz)
        this->raiz->insertar(val);
    else
        this->raiz = new Nodo<T>(val); // Si el árbol está vacío, crea la raíz
}

/**
 * @brief Busca un nodo en el árbol.
 * @param val Par de valores (x, y) a buscar.
 * @return Puntero al nodo encontrado, o `nullptr` si no está en el árbol.
 */
template<class T>
Nodo<T>* Arbol<T>::buscar(pair<T, T> val) {
    return this->raiz ? this->raiz->buscar(val) : nullptr;
}

/**
 * @brief Realiza un recorrido preorden del árbol (raíz → hijos).
 * Imprime los valores en consola.
 */
template<class T>
void Arbol<T>::preOrden() {
    if (this->raiz)
        this->raiz->preOrden();
    else
        cout << "El árbol está vacío." << endl;
}

/**
 * @brief Realiza un recorrido posorden del árbol (hijos → raíz).
 * Imprime los valores en consola.
 */
template<class T>
void Arbol<T>::posOrden() {
    if (this->raiz)
        this->raiz->posOrden();
    else
        cout << "El árbol está vacío." << endl;
}
