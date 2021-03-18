#include <iostream>
#include "persona.h"

using std::cout;
using std::cin;
using std::endl;

Persona::Persona(){
}

void Persona::crearPersona(){
     int opc;
    cout << " Digite su nombre: " << endl;
    getline(cin, nombre);
    cout << " Digite su email: " << endl;
    getline(cin, email);
    cout << " Digite su CC: " << endl;
    cin >> cedula;
    cout << " Digite su telefono (7 digitos max): " << endl;
    cin >> telefono;
    cout << " Digite su rol: \n 1. Director\n 2. Codirector\n 3. Jurado Interno\n 4 Jurado Externo\n" << endl;
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
