//
// Created by lufe0 on 7/05/2021.
//

#include "Mayor13.h"

float Mayor13::jugar(float gonzosApostar) {
    int opc;
    float gonzosResultado;
    srand(time(nullptr));
    numeroJugador = 1+rand()%14;// numeros de 1 a 13
    numeroCasino = 1+rand()%14;// numeros de 1 a 13
    cout << "Tu numero aleatorio es: "<< numeroJugador << endl;
    cout << "Desea rendirse? \n 1.Si \n 2.No" << endl;
    cin >> opc;
    if ( opc == 1){
        gonzosResultado = gonzosApostar / 2;
        return gonzosResultado;
    } else {
        gonzosResultado = calcularResultado(gonzosApostar);
        return gonzosResultado;
    }
}


float Mayor13::calcularResultado(float gonzosApostar) {
    if ( numeroJugador <= numeroCasino ) {
        gonzosApostar = 0;
    } else {
        gonzosApostar = gonzosApostar * 2;
    }
    return gonzosApostar;
}

Mayor13::~Mayor13() {

}
