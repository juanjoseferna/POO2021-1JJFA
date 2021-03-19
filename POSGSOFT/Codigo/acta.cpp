#include <iostream>
#include "acta.h"

Acta::Acta (){//Constructor vacio de Acta
}

void Acta::crearActa(int idActa){//Rellenar datos de acta que este vacia
    int opc, salida;
    Persona jurado1, jurado2, autor, director,codirector;
    this->idActa = idActa;
    cout << "Ingrese el nombre del trabajo" << endl;
    fflush(stdin);
    getline(cin, nombreTrabajo);
    fflush(stdin);
    estado = "Abierta";
    cout << "Ingrese el tipo del trabajo" << endl;
    cout << " 1. Investigacion" << endl;
    cout << " 2. Aplicado" << endl;
    cin >> opc;
    tipoProyecto var = tipoProyecto::INVESTIGACION;
    switch(var){
        case tipoProyecto::INVESTIGACION :
            tipoTrabajo = "Investigacion";
            break;
        case tipoProyecto::APLICADO :
            tipoTrabajo = "Aplicado";
            break;
    }
    salida = 0;
    cout << "Ingrese la fecha " << endl;
    fflush(stdin);
    getline(cin, fecha);
    fflush(stdin);
    cout << "Ingrese los datos del autor" << endl;
    autor.crearPersona(4);
    this->autor = autor;
    fflush(stdin);
    cout << "Ingrese los datos del primer jurado" << endl;
    jurado1.crearPersona(3);
    this->jurado1 = jurado1;
    fflush(stdin);
    cout << "Ingrese los datos del segundo jurado" << endl;
    jurado2.crearPersona(3);
    this->jurado2 = jurado2;
    fflush(stdin);
    cout << "Ingrese los datos del director" << endl;
    director.crearPersona(1);
    this->director = director;
    fflush(stdin);
    cout << "¿Existe codirector?" <<endl;
    cout << " 1. Si" << endl;
    cout << " 2. No" << endl;
    cin >> opc;
    do{
        if (opc == 1){
            cout << "Ingrese los datos del codirector" << endl;
            director.crearPersona(2);
            this->codirector = codirector;
            fflush(stdin);
            salida = 1;
        } else if (opc == 2){
            cout << "Listo!" << endl;
            salida = 1;
        }
    } while(salida == 0);
    return;
}