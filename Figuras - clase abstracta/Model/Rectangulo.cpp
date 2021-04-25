#include "Rectangulo.h"

Rectangulo::Rectangulo() {}

Rectangulo::Rectangulo(float ancho, float largo){
    this->ancho = ancho;
    this->largo = largo;
}

void Rectangulo::calcularArea(){
    this->area = this->largo * this->ancho;
    return;
}

void Rectangulo::calcularPerimetro(){
    this->perimetro = (2 * this->largo) + (2 * this->ancho);
    return;
}

void Rectangulo::mostrarFigura(){
    cout << "El ancho: " << ancho << " -- " << "el largo: " << largo << endl;
    this->calcularArea();
    this->calcularPerimetro();
    cout << "El area del rectangulo es: " << area << endl;
    cout << "El perimetro del rectangulo es : " << perimetro << endl;
    FiguraGeometrica::mostrarFigura();
    return;
}

float Rectangulo::getAncho(){
    return this->ancho;
}

float Rectangulo::getLargo(){
    return this->largo;
}

void Rectangulo::setAncho(float ancho){
    this->ancho = ancho;
    return;
}
void Rectangulo::setLargo(float largo){
    this->largo = largo;
    return;
}
