#ifndef FIGURASCONTROLLER_H
#define FIGURASCONTROLLER_H

#include "../Model/FiguraGeometrica.h"
#include "../Model/Circulo.h"
#include "../Model/Triangulo.h"
#include "../Model/Rectangulo.h"
#include "../Model/Cuadrado.h"

#include <iostream>
#include <list>

using std::cin;
using std::cout;
using std::endl;
using std::list;

class FigurasController
{
private: 
    const static int MAX_ITEMS;
    list<Rectangulo> listaRectangulo;
    list<Circulo> listaCirculo;
    list<Cuadrado> listaCuadrado;
    list<Triangulo> listaTriangulo;
    list<FiguraGeometrica *> pListaFiguras; // Debe ser de apuntadores pq las clases abstractas no se pueden instanciar

public:
    void agregarCuadrado(float lado);
    list<Rectangulo> &getListaRectangulo();
    void agregarRectangulo(float largo, float ancho);
    Rectangulo &encontrarMayorAncho();
    list<Circulo> &getListaCirculo();
    void agregarCirculo(float radio);
    list<Triangulo> &getListaTriangulo();
    void agregarTriangulo(float base, float altura);
    list<Cuadrado> &getListaCuadrado();
    list<FiguraGeometrica *> &getListaFiguras();
    void llenarListaTodosDummy();
};

#endif // FIGURASCONTROLLER_H
