#include <iostream>
#include <string>
#include "criterio.h"
#include "persona.h"
#include "registro.h"
#include "acta.h"

int menu(){
    int opcion;
    cout << "Menu del sistema de actas de grado\n"<< endl;
    cout << " 1. Crear acta" << endl;
    cin >> opcion;
    return opcion;
} 

int main(){
	Registro actas;
	actas.agregarActa();
	return 0;
}