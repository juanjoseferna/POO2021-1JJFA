//
// Created by jeanz on 12/05/2021.
//

#ifndef CASINO_ADIVINOPARESIMPARES_H
#define CASINO_ADIVINOPARESIMPARES_H

#include "Juego.h"
#include<cstdlib>
#include<ctime>

class AdivinoParesImpares : public Juego {
protected:
    bool mayorCinco;
    bool par;
    bool impar;
    virtual float calcularResultado(float gonzosApostar) override;
public:
    virtual ~AdivinoParesImpares();
    virtual float jugar(float gonzosApostar) override;
};


#endif //CASINO_ADIVINOPARESIMPARES_H
