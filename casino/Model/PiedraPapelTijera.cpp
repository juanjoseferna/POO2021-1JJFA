//
// Created by finch on 13/05/2021.
//

#include "PiedraPapelTijera.h"

PPT retornaPPT(int opc){
    if (opc == 1) {
        return PIEDRA;
    }
    if (opc == 2) {
        return PAPEL;
    }
    if (opc == 3) {
        return TIJERA;
    }
}

float PiedraPapelTijera::jugar(float gonzosApostar){
    srand(time(nullptr));
    numeroCasino = 1+rand()%(4-1); //numero random entre 1 y 3
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
    }
    if (pptJugador == PIEDRA && pptCasino == PAPEL){
        cout << "Pierdes! Papel le gana a piedra, perdiste " << gonzosApostar << endl;
        gonzosApostar = 0;
    }
    if (pptJugador == PIEDRA && pptCasino== TIJERA){
        gonzosApostar += gonzosApostar;
        cout << "Ganaste! Piedra le gana a Tijera, ganas " << gonzosApostar << endl;
    }
    if (pptJugador == PAPEL && pptCasino == PAPEL){
        cout << "Empate!" << endl;
    }
    if (pptJugador == PAPEL && pptCasino == TIJERA){
        cout << "Pierdes! tijera le gana a papel, pierdes " << gonzosApostar << endl;
        gonzosApostar = 0;
    }
    if (pptJugador == PAPEL && pptCasino== PIEDRA){
        gonzosApostar += gonzosApostar;
        cout << "Ganaste! papel le gana a piedra, ganas "<< gonzosApostar << endl;
    }
    if (pptJugador == TIJERA && pptCasino == TIJERA){
        cout << "Empate!" << endl;
    }
    if (pptJugador == TIJERA && pptCasino == PIEDRA){
        cout << "Pierdes! Piedra le gana a Tijera, pierdes " << gonzosApostar << endl;
        gonzosApostar = 0;
    }
    if (pptJugador == TIJERA && pptCasino== PAPEL){
        gonzosApostar += gonzosApostar;
        cout << "Ganaste! Tijera le gana a Papel, ganas " << gonzosApostar << endl;
    }
    return gonzosApostar;
}

PiedraPapelTijera::~PiedraPapelTijera(){

}