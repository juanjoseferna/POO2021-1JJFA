#include <iostream>
#include "Rectangulo.h"

Rectangulo::Rectangulo( float a, float b ){
    this->ancho = a;
    this->largo = b;
}

Rectangulo::Rectangulo(){
    this->ancho = 0;
    this->largo = 0;
}

void Rectangulo::calcularAreaRec(){
    std::cout << "El area del rectangulo es: " << ancho * largo << std::endl;
    return;
}

void Rectangulo::calcularPerimetroRec(){
    std::cout << "El perimetro del rectangulo es: " << ancho * 2 + largo * 2 << std::endl;
    return;
}

void Rectangulo::setAncho ( float ancho ){
    this->ancho = ancho;
    return;
}

void Rectangulo::setLargo( float largo ){
    this->largo = largo;
    return;
}
