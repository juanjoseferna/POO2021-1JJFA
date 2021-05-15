//
// Created by criska on 13/05/2021.
//

#ifndef CASINO_SACATRES_H
#define CASINO_SACATRES_H

#include "Juego.h"
#include<cstdlib>
#include<ctime>


class sacaTres : public Juego {

protected:
    int serTres;
    virtual float calcularResultado(float gonzosApostar) override;
public:
    virtual ~sacaTres();
    virtual float jugar(float gonzosApostar) override;

};


#endif //CASINO_SACATRES_H
