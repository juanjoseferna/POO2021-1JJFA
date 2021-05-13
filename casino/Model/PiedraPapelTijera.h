//
// Created by finch on 13/05/2021.
//

#ifndef CASINO_PIEDRAPAPELTIJERA_H
#define CASINO_PIEDRAPAPELTIJERA_H

#include "Juego.h"
#include<cstdlib>
#include<ctime>


enum PPT{ //PPT: Piedra, Papel y Tijera
    PIEDRA = 1, PAPEL, TIJERA
};

class PiedraPapelTijera : public Juego{
protected:
    PPT pptCasino, pptJugador;
    float calcularResultado(float gonzosApostar) override;
public:
    float jugar(float gonzosApostar) override;
    virtual ~PiedraPapelTijera();
};

#endif //CASINO_PIEDRAPAPELTIJERA_H
