//#ifndef RECTANGULO_H
// Guardas
//#define RECTANGULO_H

//CLASE RECTANGULO
#include <iostream>
#include <cstdlib>

#include "FiguraGeometrica.h"

using std::cin;
using std::cout;
using std::endl;

class Rectangulo : public FiguraGeometrica
{
private:
    float ancho, largo;

public:
    Rectangulo(); //no olvidar
    Rectangulo(float, float);
    virtual void calcularArea() override;
    virtual void calcularPerimetro() override;
    virtual void mostrarFigura() override; // sobreescritura
    float getLargo();
    float getAncho();
    void setLargo(float);
    void setAncho(float);
};

//#endif /* !RECTANGULO_H */