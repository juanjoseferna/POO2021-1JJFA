#include <iostream>
#include "persona.h"

Persona::Persona(){ //Constructor vacio de persona
}

void Persona::crearPersona(int opcion1){ //Relleno de datos para persona
    int opc, salida=1;
    cout << " Digite el nombre: " << endl;
    fflush(stdin);
    getline(cin, nombre);
    fflush(stdin);
    cout << " Digite el email: " << endl;
    fflush(stdin);
    getline(cin, email);
    fflush(stdin);
    cout << " Digite el CC: " << endl;
    cin >> cedula;
    cout << " Digite el telefono: " << endl;
    cin >> telefono;
    if(opcion1 == 1){
        rol = "Director";
    } else if (opcion1 == 2){
        rol = "Codirector";
    }
    do{
        if (opcion1 == 3){
            cout << " 1. Jurado Interno" << endl;
            cout << " 2. Jurado Externo" <<endl;
            cin >> opc;
            if (opc == 1){
                rol = " JuradoInterno";
                salida = 0;
            } else if (opc == 2){
                rol = " JuradoExterno";
                salida = 0;
            }
          }
    } while(salida == 1);
    if (opcion1 == 4){
        rol = "Estudiante";
    }
    return;
}

void Persona::verPersona(){
    cout << " Nombre y cargo: " << nombre << " - " << rol << endl;
    cout << " Email y telefono: " << email << " - " << telefono << endl;
    cout << " CC: " << cedula << endl;
    return;
}
