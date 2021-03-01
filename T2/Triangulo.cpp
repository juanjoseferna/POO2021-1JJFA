#include <iostream>
#include "Triangulo.h"

Triangulo::Triangulo( float ladoA, float ladoB, float base, float altura){
    this->ladoA = ladoA;
    this->ladoB = ladoB;
    this->base = base;
    this->altura = altura;
}

Triangulo::Triangulo(){
    this->ladoA = 0;
    this->ladoB = 0;
    this->base = 0;
    this->altura = 0;
}

void Triangulo::calcularAreaTri(){
    std::cout << "El area del triangulo es: " << ( base * altura )/2 << std::endl;
    return;
}

void Triangulo::calcularPerimetroTri(){
    std::cout << "El perimetro del triangulo es: " << ladoA + ladoB + base << std::endl;
}

void Triangulo::setLadoA( float ladoA ){
    this->ladoA = ladoA;
    return;
}

void Triangulo::setLadoB( float ladoB ){
    this->ladoB = ladoB;
    return;
}

void Triangulo::setBase( float base ){
    this->base = base;
    return;
}

void Triangulo::setAltura( float altura ){
    this->altura = altura;
    return;
}
