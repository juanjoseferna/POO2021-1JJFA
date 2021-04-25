#include "Triangulo.h"

Triangulo::Triangulo() {}

Triangulo::Triangulo(float base, float altura){
    this->base = base;
    this->altura = altura;
}

void Triangulo::calcularArea(){
    area = (base * altura) / 2;
    return;
}

void Triangulo::calcularPerimetro(){
    float temp;
    temp = base / 2;
    perimetro = 2 * ((sqrt((temp * temp)) + (altura * altura))) + base;
    return;
}

void Triangulo::mostrarFigura(){
    this->calcularArea();
    this->calcularPerimetro();
    cout << "AlturaxBase: " << altura << "x" << base << endl;
    cout << "El area del triangulo es: " << area << endl;
    cout << "El perimetro del triagulo es: " << perimetro << endl;
    FiguraGeometrica::mostrarFigura();
    return;
}