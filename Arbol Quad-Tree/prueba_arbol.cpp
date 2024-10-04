
/*******************************************
Fecha: 1 octubre 2024
Autor: Santiago Camargo
Tema: Taller Arboles
Estructuras de datos
******************************************/
#include <bits/stdc++.h>
#include "quadtree.h"

using namespace std;
struct Point {
    int x, y;
    Point(int _x, int _y) : x(_x), y(_y) {}
};

// Estructura para representar un límite rectangular
struct Boundary {
    int x_min, x_max, y_min, y_max;
    Boundary(int xmin, int xmax, int ymin, int ymax) : x_min(xmin), x_max(xmax), y_min(ymin), y_max(ymax) {}
};

// Función para probar la inserción de puntos en el QuadTree
void pruebaQuadTree() {
    // Definir el límite del QuadTree (un cuadrado de 100x100)
    Boundary limite(0, 100, 0, 100);
    
    // Crear el QuadTree con el límite
    QuadTree quadtree(limite);

    // Insertar algunos puntos
    quadtree.insert(Point(10, 30));
    quadtree.insert(Point(50, 75));
    quadtree.insert(Point(70, 20));
    quadtree.insert(Point(90, 90));

    // Mostrar resultados
    cout << "Puntos insertados en el QuadTree." << endl;
}

int main() {
    pruebaQuadTree();
    return 0;
}


