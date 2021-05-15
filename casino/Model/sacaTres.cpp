//
// Created by criska on 13/05/2021.
//

#include "sacaTres.h"

float sacaTres::jugar(float gonzosApostar) {
    float gonzosResultado;
    srand(time(nullptr));
    numeroJugador = 1+rand()%3;// numeros de 1 a 2
    numeroCasino = 1+rand()%3;// numeros de 1 a 2
    cout << "Tu primer numero aleatorio es: "<< numeroJugador << endl;
    cout << "Tu segundo numero aleatorio es: "<< numeroCasino << endl;
    serTres = numeroJugador + numeroCasino;
    gonzosResultado = calcularResultado(gonzosApostar);
    return gonzosResultado;
}


float sacaTres::calcularResultado(float gonzosApostar) {
    if ( serTres == 3 ) {
        gonzosApostar = gonzosApostar * 5;
        cout << "Felicidades! ganas " << gonzosApostar << endl;
    } else {
        cout << "Perdiste! pierdes " << gonzosApostar << endl;
        gonzosApostar = 0;
    }
    return gonzosApostar;
}

sacaTres::~sacaTres() {

}


