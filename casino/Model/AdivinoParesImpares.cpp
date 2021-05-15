//
// Created by jeanz on 12/05/2021.
//

#include "AdivinoParesImpares.h"


float AdivinoParesImpares::jugar(float gonzosApostar) {
    float gonzosResultado;
    int opc;
    srand(time(nullptr));
    numeroCasino= 1+rand()%10;// numeros de 1 a 10
    cout << "su numero sera par o impar? \n 1.Par \n 2.Impar" << endl;
    cin >> opc;
    if ( opc == 1){
        cout << "Tu numero aleatorio es: "<< numeroCasino << endl;
        par = true;
        gonzosResultado = calcularResultado(gonzosApostar);
        return gonzosResultado;
    } else {
        cout << "Tu numero aleatorio es: "<< numeroCasino << endl;
        par = false;
        gonzosResultado = calcularResultado(gonzosApostar);
        return gonzosResultado;
    }
}


float AdivinoParesImpares::calcularResultado(float gonzosApostar){
    if (numeroCasino % 2 == 0 && par) {
        gonzosApostar = gonzosApostar * 4;
        cout << "Felicidades! acertaste " << gonzosApostar << endl;
    }
    else if(numeroCasino % 2 == 1 && !par){
        gonzosApostar = gonzosApostar * 4;
        cout << "Felicidades! acertaste " << gonzosApostar << endl;
    }
    else{
        cout << "Lo sentimos, perdiste " << gonzosApostar << endl;
        gonzosApostar = 0;
    }
    return gonzosApostar;
}

AdivinoParesImpares::~AdivinoParesImpares(){

}




