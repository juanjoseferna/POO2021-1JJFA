#include "Cuadrado.h"

Cuadrado::Cuadrado(){
}

Cuadrado::Cuadrado( float lado ){
    this->lado = lado;
}

void Cuadrado::calcularArea(){
    int area =  lado * lado;
    this->area = area;
    return;
}

void Cuadrado::calcularPerimetro(){
    int perimetro = lado * 4;
    this->perimetro = perimetro;
    return;
}

void Cuadrado::mostrarFigura(){
    this->calcularArea();
    this->calcularPerimetro();
    cout << "Dimensiones cuadrado: " << lado << "x" << lado << endl;
    cout << "El area del cuadrado es: " << area << endl;
    cout << "El perimetro del cuadrado es: " << perimetro << endl;
    FiguraGeometrica::mostrarFigura();
    return;
}