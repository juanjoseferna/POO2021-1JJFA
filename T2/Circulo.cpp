#include <iostream>
#include "Circulo.h"

Circulo::Circulo(){
    this->radio = 0;
}

Circulo :: Circulo ( float radio ){
    this->radio = radio;
}

void Circulo::calcularAreaCir(){
    float area = PI * ( radio * radio );
    std::cout << "El area del circulo es: " << area << std::endl;
    return;
}

void Circulo::calcularPerimetroCir(){
    float perimetro = 2 * radio * PI;
    std::cout << "El perimetro del circulo es: " << perimetro << std::endl;
    return;
}

int Circulo::getRadio(){
    return this->radio;
}

void Circulo::setRadio( float radio ){
    this->radio = radio;
    return;
}