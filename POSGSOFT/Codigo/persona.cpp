#include <iostream>
#include "persona.h"

Persona::Persona(){
}

void Persona::crearPersona(){
    int opc;
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
    cout << " Digite el rol: \n 1. Director\n 2. Codirector\n 3. Jurado Interno\n 4. Jurado Externo" << endl;
    cin >> opc;
    if(opc == 1){
        rol = "Director";
    } else if (opc == 2){
        rol = "Codirector";
    } else if (opc == 3){
        rol = " JuradoInterno";
    } else if (opc == 4){
        rol = " JuradoExterno";
    } else if (opc == 5){
        rol = "Estudiante";
    }
    
}
