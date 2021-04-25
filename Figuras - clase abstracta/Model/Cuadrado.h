#ifndef CUADRADRO_H
#define CUADRADRO_H

#include <iostream>
#include <stdlib.h>
#include <string>
#include "FiguraGeometrica.h"

class Cuadrado : public FiguraGeometrica{
private:
    float lado;
public:
    Cuadrado();
    Cuadrado( float );
    virtual void calcularArea() override;
    virtual void calcularPerimetro() override;
    virtual void mostrarFigura() override;
};





#endif //CUADRADO_H