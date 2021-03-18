#include <iostream>
#include "acta.h"

Acta::Acta (){}

void Acta::crearActa(int idActa){
    int opc, salida;
    Persona jurado1, jurado2, autor, director,codirector;
    this->idActa = idActa;
    cout << "Ingrese el nombre del trabajo" << endl;
    getline(cin, nombreTrabajo);
    estado = "Abierta";
    cout << "Ingrese el tipo del trabajo" << endl;
    cout << " 1. Investigacion" << endl;
    cout << " 2. Aplicado" << endl;
    cin >> opc;
    do{
        if (opc == 1){
            tipoTrabajo = "Investigacion";
            salida = 1;
        } else if (opc == 2){
            tipoTrabajo = "Aplicado";
            salida = 1;
        }
    } while(salida == 0);
    salida = 0;
    cout << "Ingrese la fecha " << endl;
    getline(cin, fecha);
    cout << "Ingrese los datos del primer autor" << endl;
    autor.crearPersona();
    this->autor = autor;
    cout << "Ingrese los datos del primer jurado" << endl;
    jurado1.crearPersona();
    this->jurado1 = jurado1;
    cout << "Ingrese los datos del segundo jurado" << endl;
    jurado2.crearPersona();
    this->jurado2 = jurado2;
    cout << "Ingrese los datos del director" << endl;
    director.crearPersona();
    this->director = director;
    cout << "¿Existe codirector?" <<endl;
    cout << " 1. Si" << endl;
    cout << " 2. No" << endl;
    cin >> opc;
    do{
        if (opc == 1){
            cout << "Ingrese los datos del codirector" << endl;
            director.crearPersona();
            this->codirector = codirector;
            salida = 1;
        } else if (opc == 2){
            cout << "Listo!" << endl;
            salida = 1;
        }
    } while(salida == 0);
}