//
// Created by lufe0 on 8/05/2021.
//

#include "DosColores.h"

float DosColores::jugar(float gonzosApostar) {
    srand(time(nullptr));
    // para calcular numero aleatorio variable = limite_inferior + rand() % (limite_superior +1 - limite_inferior) ;
    numeroJugador = 1+rand()%(14-1);// numeros de 1 a 13
    numeroCasino = 1+rand()%(14-1);// numeros de 1 a 13

    colorJugador = rand()%2; // Numero entre 0 y 1
    colorCasino = rand()%2; // Numero entre 0 y 1
    cout << "Tu numero aleatorio es: "<< numeroJugador << "Tu color: " <<colorJugador << "\n";
    cout << "Numero casino: "<< numeroCasino << "Color casino: " <<colorCasino << "\n";
    float gonzosResultado = calcularResultado(gonzosApostar);
    return gonzosResultado;
}

float DosColores::calcularResultado(float gonzosApostar){
    if (colorCasino == colorJugador && numeroCasino == numeroJugador){
        // Si coincide tanto el valor del dado como el color, el usuario ganará 4 veces lo apostado
        gonzosApostar = gonzosApostar * 4;
        cout << "Felicidades! ganaste " << gonzosApostar << endl;
    }else if ( numeroCasino == numeroJugador ){
    // coincide sólo con el valor del dado ganará 0.5 veces lo apostado
        gonzosApostar = gonzosApostar * 0.5;
        cout << "Felicidades! ganaste " << gonzosApostar << endl;
    }else if( colorCasino == colorJugador ){
    // no gana ni pierde
        gonzosApostar = gonzosApostar;
        cout << "Empate! no ganaste ni perdiste " << endl;
    }else{ // pierde all lo apostado
        cout << "Pierdes! perdiste " << gonzosApostar << endl;
        gonzosApostar = 0;
   }
   return gonzosApostar;
}

DosColores::~DosColores() {
}
