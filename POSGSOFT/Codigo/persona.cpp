#include <iostream>
#include "persona.h"

Persona::Persona(){ //Constructor vacio de persona
}

void Persona::crearPersona(int opcion1){ //Rellena de datos para persona
    int opc, salida=1;
    cout << " Digite el nombre: " << endl;
    fflush(stdin);
    getline(cin, nombre);
    fflush(stdin);
    cout << " Digite el email: " << endl;
    fflush(stdin);
    getline(cin, email);
    fflush(stdin);
    cout << " Digite el codigo de identificacion (5 digitos): " << endl;
    cin >> codigo;
    cout << " Digite el telefono: " << endl;
    cin >> telefono;
    if(opcion1 == 1){
        rol = "Director";
    } else if (opcion1 == 2){
        rol = "Codirector";
    }else if (opcion1 == 4){
        rol = "Estudiante";
    }
    else if (opcion1 == 3){
        do{
            cout << " 1. Jurado Interno" << endl;
            cout << " 2. Jurado Externo" <<endl;
            cin >> opc;
            if (opc == 1){
                rol = "JuradoInterno";
                salida = 0;
            } else if (opc == 2){
                rol = "JuradoExterno";
                salida = 0;
            }
        }while(salida == 1);
      }
    return;
}

string Persona::getNombre(){//retorna el nombre de la persona
    return nombre;
}

string Persona::getEmail(){//retorna el email de la persona
    return email;
}

string Persona::getRol(){//retorna el rol de la persona
    return rol;
}

int Persona::getCodigo(){//retorna el codigo de la persona
    return codigo;
}

int Persona::getTelefono(){//retorna el telefono de la persona
    return telefono;
}

void Persona::verPersona(){//Imprime la informacion de la persona
    cout << " Nombre y cargo: " << nombre << " - " << rol << endl;
    cout << " Email y telefono: " << email << " - " << telefono << endl;
    cout << " CI: " << codigo << endl; //CI significa codigo de identificacion
    return;
}
