//
// Created by finch on 13/05/2021.
//

#include "PiedraPapelTijera.h"

PPT retornaPPT(int opc){
    switch (opc){
        case 1:
            return PIEDRA;
        case 2:
            return PAPEL;
        case 3:
            return TIJERA;
    }
}

float PiedraPapelTijera::jugar(float gonzosApostar){
    srand(time(nullptr));
    numeroCasino = 1+rand()%4; //numero random entre 1 y 3
    cout << "Elija su opcion" << endl;
    cout << " 1. Piedra" << endl;
    cout << " 2. Papel" << endl;
    cout << " 3. Tijera" << endl;
    cin >> numeroJugador;
    pptCasino = retornaPPT(numeroCasino);
    pptJugador = retornaPPT(numeroJugador);
    float gonzosResultado = calcularResultado(gonzosApostar);
    return gonzosResultado;
}

float PiedraPapelTijera::calcularResultado(float gonzosApostar) {
    if (pptJugador == PIEDRA && pptCasino == PIEDRA){
        cout << "Empate!" << endl;
    } else if (pptJugador == PIEDRA && pptCasino == PAPEL){
        cout << "Pierdes! Papel le gana a piedra";
        gonzosApostar = 0;
    } else if (pptJugador == PIEDRA && pptCasino== TIJERA){
        cout << "Ganaste! Piedra le gana a Tijera";
        gonzosApostar += gonzosApostar;
    } else if (pptJugador == PAPEL && pptCasino == PAPEL){
        cout << "Empate!" << endl;
    } else if (pptJugador == PAPEL && pptCasino == TIJERA){
        cout << "Pierdes! tijera le gana a papel";
        gonzosApostar = 0;
    } else if (pptJugador == PAPEL && pptCasino== PIEDRA){
        cout << "Ganaste! papel le gana a piedra";
        gonzosApostar += gonzosApostar;
    } else if (pptJugador == TIJERA && pptCasino == TIJERA){
        cout << "Empate!" << endl;
    } else if (pptJugador == TIJERA && pptCasino == PIEDRA){
        cout << "Pierdes! Piedra le gana a Tijera";
        gonzosApostar = 0;
    } else if (pptJugador == TIJERA && pptCasino== PAPEL){
        cout << "Ganaste! Tijera le gana a Papel";
        gonzosApostar += gonzosApostar;
    }
    return gonzosApostar;
}

PiedraPapelTijera::~PiedraPapelTijera(){

}