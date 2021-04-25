#include "Circulo.h"

const float Circulo::PI = 3.1416;

Circulo::Circulo(){
}

Circulo::Circulo(float radio) : Circulo(){
    this->radio = radio;
    return;
}

void Circulo::calcularArea(){
    this->area = PI * (this->radio * this->radio);
    return;
}

void Circulo::calcularPerimetro(){
    this->perimetro = (2 * PI) * radio;
    return;
}

void Circulo::mostrarFigura(){
    cout << "El radio es: " << radio << endl;
    this->calcularArea();
    this->calcularPerimetro();
    cout << "El area del circulo es: " << this->area << endl;
    cout << "El perimetro del circulo es: " << this->perimetro << endl;
    FiguraGeometrica::mostrarFigura();
    return;
}

float Circulo::getRadio() const{
    return this->radio;
}

void Circulo::setRadio(float radio){
    this->radio = radio;
    return;
}