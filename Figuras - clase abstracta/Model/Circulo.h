#ifndef CIRCULO_H
#define CIRCULO_H

#include <iostream>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;

#include "FiguraGeometrica.h"

//CLASE CIRCULO

class Circulo : public FiguraGeometrica
{
private: //atributos
    float radio;
    const static float PI;

public:
    Circulo();
    Circulo(float);
    virtual void calcularArea() override;
    virtual void calcularPerimetro() override;
    virtual void mostrarFigura() override;
    float getRadio() const;
    void setRadio(float);
};

#endif /* !CIRCULO_H */