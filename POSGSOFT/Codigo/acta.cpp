#include <iostream>
#include "acta.h"

Acta::Acta (){//Constructor vacio de Acta
}

void Acta::crearActa(int idActa){//Rellenar datos de acta que este vacia
    int opc, salida;
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
    cout << "Ingrese los datos del primer jurado" << endl;
    jurado1.crearPersona(3);
    cout << "Ingrese los datos del segundo jurado" << endl;
    jurado2.crearPersona(3);
    cout << "Ingrese los datos del director" << endl;
    director.crearPersona(1);
    cout << "¿Existe codirector?" <<endl;
    cout << " 1. Si" << endl;
    cout << " 2. No" << endl;
    cin >> opc;
    do{
        if (opc == 1){
            cout << "Ingrese los datos del codirector" << endl;
            director.crearPersona(2);
            codirectorEstado = true;
            salida = 1;
        } else if (opc == 2){
            cout << "Listo!" << endl;
            salida = 1;
        }
    } while(salida == 0);
    return;
}

void Acta::imprimirActa(){
    cout << " Nombre del trabajo - ID: " << nombreTrabajo << " - " << idActa << endl;
    cout << " Estado: " << estado << endl;
    cout << " Fecha: " << fecha << endl;
    cout << " Tipo de trabajo: " << tipoTrabajo << endl;
    cout << " Estado: " << estado << endl;
    cout << " Nota final (Si es -1 es porque aun faltan calificaciones): " <<  notaFinal << endl;
    cout << "Autor: " << endl;
    autor.verPersona();
    cout << "Primer jurado: " << endl;
    jurado1.verPersona();
    cout << "Segundo jurado: " << endl;
    jurado2.verPersona();
    cout << "Director: " << endl;
    director.verPersona();
    if (codirectorEstado){
        cout << "Codirector: " << endl;
        codirector.verPersona();
    } else {
        cout << "Codirector: " << "No existe" << endl;
    }
    return;
}

int Acta::getId(){
    return idActa;
}

string Acta::getEstado(){
    return estado;
}

void Acta::agregarCalificaciones(){
    if (estado == "Cerrado"){
        cout << "Error_404: La acta ya se encuentra cerrada" << endl;
        return;
    }
    Calificacion calificacion;
    if (CalificacionesJurados.size() == 2){
        cout << "Ya hay suficientes calificaciones!!" << endl;
        return;
    }
    while(CalificacionesJurados.size() < 2){
        calificacion.crearCalificacion(CalificacionesJurados.size());
        CalificacionesJurados.push_back(calificacion);
    }
    return;
}

void Acta::cerrarActa(){
    if (notaFinal == -1){
        cout << "calificacion final no calculada Error_404" << endl;
        return;
    }
    estado = "Cerrado";
    return;
}

void Acta::calcularNotaFinal(){
    float notaFinal = 0, porcentaje;
    if (CalificacionesJurados.size() < 2){
        cout << "No hay suficientes calificaciones!!" << endl;
        return;
    }
    for(list<Calificacion>::iterator calificacion = CalificacionesJurados.begin();calificacion!=CalificacionesJurados.end();calificacion++){
        porcentaje = calificacion->getPorcentajeNota();
        notaFinal += (((calificacion->getNotaJ1() * porcentaje) + (calificacion->getNotaJ2() * porcentaje)));
    }
    this->notaFinal = notaFinal/2;
    cout << "La nota final es de: " << notaFinal << endl;
    return;
}

void Acta::crearArchivoTXT(){
    ofstream File;
    File.open("Actas.txt");
    File << " Nombre del trabajo - ID: " << nombreTrabajo << " - " << idActa << endl;
    File << " Estado: " << estado << endl;
    File << " Fecha: " << fecha << endl;
    File << " Tipo de trabajo: " << tipoTrabajo << endl;
    File << " Estado: " << estado << endl;
    File << " Nota final (Si es -1 es porque aun faltan calificaciones): " <<  notaFinal << endl;
    File << "Autor: " << endl;
    File << " Nombre y cargo: " << autor.getNombre() << " - " << autor.getRol() << endl;
    File << " Email y telefono: " << autor.getEmail() << " - " << autor.getTelefono() << endl;
    File << " CC: " << autor.getCedula() << endl;
    File << "Primer jurado: " << endl;
    File << " Nombre y cargo: " << jurado1.getNombre() << " - " << jurado1.getRol() << endl;
    File << " Email y telefono: " << jurado1.getEmail() << " - " << jurado1.getTelefono() << endl;
    File << " CC: " << jurado1.getCedula() << endl;
    File << "Segundo jurado: " << endl;
    File << " Nombre y cargo: " << jurado2.getNombre() << " - " << jurado2.getRol() << endl;
    File << " Email y telefono: " << jurado2.getEmail() << " - " << jurado2.getTelefono() << endl;
    File << " CC: " << jurado2.getCedula() << endl;
    File << "Director: " << endl;
    File << " Nombre y cargo: " << director.getNombre() << " - " << director.getRol() << endl;
    File << " Email y telefono: " << director.getEmail() << " - " << director.getTelefono() << endl;
    File << " CC: " << director.getCedula() << endl;
    if (codirectorEstado){
        File << "Codirector: " << endl;
        File << " Nombre y cargo: " << codirector.getNombre() << " - " << codirector.getRol() << endl;
        File << " Email y telefono: " << codirector.getEmail() << " - " << codirector.getTelefono() << endl;
        File << " CC: " << codirector.getCedula() << endl;
    } else {
        File << "Codirector: " << "---No existe---" << endl;
    }
    File.close();
    return;
}