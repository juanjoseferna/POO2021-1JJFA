//
// Created by jeanz on 12/05/2021.
//

#include "AdivinoParesImpares.h"


float AdivinoParesImpares::jugar(float gonzosApostar) {
    float gonzosResultado;
    srand(time(nullptr));
    numeroCasino= 1+rand()%11;// numeros de 1 a 10
    cout << "Tu numero aleatorio es: "<< numeroJugador << endl;
    gonzosResultado = calcularResultado(gonzosApostar);
    return gonzosResultado;
}


float AdivinoParesImpares::calcularResultado(float gonzosApostar){
    if (numeroCasino >= 5 && mayorCinco && par && !impar) {
        gonzosApostar = gonzosApostar * 4;
    }
    else if(numeroCasino >= 5 && mayorCinco && !par && impar){
        gonzosApostar = gonzosApostar * 4;
    }
    else if(numeroCasino < 5 && !mayorCinco && !par && impar){
        gonzosApostar = gonzosApostar * 4;
    }
    else if(numeroCasino < 5 && !mayorCinco && !par && impar){
        gonzosApostar = gonzosApostar * 4;
    } else{
        gonzosApostar -= gonzosApostar;
    }
    return gonzosApostar;
}

AdivinoParesImpares::~AdivinoParesImpares(){

}




