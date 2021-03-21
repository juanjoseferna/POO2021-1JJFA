#include <iostream>
#include "acta.h"

Acta::Acta (){//Constructor vacio de Acta
}

void Acta::crearActa(int idActa){//Rellenar datos de acta que este vacia
    int opc, salida = 1;
    this->idActa = idActa;
    cout << "Ingrese el periodo universitario" << endl;
    fflush(stdin);
    getline(cin, periodo);
    fflush(stdin);
    cout << "Ingrese el nombre del trabajo" << endl;
    fflush(stdin);
    getline(cin, nombreTrabajo);
    fflush(stdin);
    estado = "Abierta";
    cout << "Ingrese el tipo del trabajo" << endl;
    cout << " 1. Investigacion" << endl;
    cout << " 2. Aplicado" << endl;
    do{
        cin >> opc;
        if (opc == 1){
            tipoTrabajo = "Investigacion";
            salida = 0;
        } else if (opc == 2){
            tipoTrabajo = "Aplicado";
            salida = 0;
        }
    } while (salida != 0);
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
    cout << "Existe codirector?" <<endl;
    cout << " 1. Si" << endl;
    cout << " 2. No" << endl;
    cin >> opc;
    estadoTrabajo = "Pendiente";
    do{
        if (opc == 1){
            cout << "Ingrese los datos del codirector" << endl;
            director.crearPersona(2);
            codirectorEstado = true;
            salida = 0;
        } else if (opc == 2){
            cout << "Listo!" << endl;
            codirectorEstado = true;
            salida = 0;
        }
    } while(salida != 0);
    return;
}

void Acta::setComentarioAdicional(){
    cout << "Ingrese el comentario adicional del jurado 1" << endl;
    fflush(stdin);
    getline(cin, observacionAdicionalJ1);
    fflush(stdin);
    cout << "Ingrese el comentario adicional del jurado 2" << endl;
    fflush(stdin);
    getline(cin, observacionAdicionalJ2);
    fflush(stdin);
}

int Acta::getCodigoJurado1(){//retorna el codigo del jurado1
    return jurado1.getCodigo();
}

int Acta::getCodigoJurado2(){//retorna el codigo del jurado2
    return jurado2.getCodigo();
}

int Acta::getCodigoDirector(){//retorna el codigo del director
    return director.getCodigo();
}

string Acta::getNombreActa(){//retorna el nombre del trabajo
    return nombreTrabajo;
}

string Acta::getNombreJurado1(){//retorna el nombre del jurado1
    return jurado2.getNombre();
}

string Acta::getNombreJurado2(){//retorna el nombre del jurado2
    return jurado1.getNombre();
}

string Acta::getTipoJurado1(){//retorna el tipo de jurado1
    return jurado1.getRol();
}

string Acta::getTipoJurado2(){//retorna el tipo de jurado2
    return jurado2.getRol();
}

void Acta::imprimirActa(){//imprime el acta
    cout << " Nombre del trabajo - ID: " << nombreTrabajo << " - " << idActa << endl;
    cout << " Estado: " << estado << endl;
    cout << " Fecha: " << fecha << endl;
    cout << " Tipo de trabajo: " << tipoTrabajo << endl;
    cout << " Estado: " << estado << endl;
    if (notaFinal == -1){
        cout << " Nota Final: No existe aun"  << endl;
    }else{
        cout << " Nota final: " <<  notaFinal << endl;
    }
    cout << "Autor: " << autor.getNombre() << endl;
    return;
}

int Acta::getId(){//retorna el id del acta
    return idActa;
}

int Acta::getNumeroTotalCriterios(){//retorna el total de criterios
    return numeroTotalCriterios;
}

string Acta::getEstado(){//retorna si el acta esta abierta o cerrada
    return estado;
}

string Acta::getEstadoTrabajo(){//retorna el estado del trabajo del acta pendiente, rechazada o aceptada
    return estadoTrabajo;
}

string Acta::getTipoTrabajo(){//retorna si el tipo de trabajo es de investigacion o aplicado
    return tipoTrabajo;
}

void Acta::agregarCalificaciones(){//rellena las calificaciones
    int opc;
    if (estado == "Cerrado"){
        cout << "Error_404: La acta ya se encuentra cerrada" << endl;
        return;
    }
    Calificacion calificacion;
    if (CalificacionesJurados.size() == numeroTotalCriterios){
        cout << "Ya hay suficientes calificaciones!!" << endl;
        cout << "Desea cambiar las calificaciones?" << endl;
        cout << " 1. Si" << endl;
        cout << " 2. No" << endl;
        cin >> opc;
        if (opc == 1){
            CalificacionesJurados.clear();
        } else {
            return;
        }
    }
    while(CalificacionesJurados.size() < numeroTotalCriterios){
        calificacion.crearCalificacion(CalificacionesJurados.size());
        CalificacionesJurados.push_back(calificacion);
    }
    return;
}

void Acta::cerrarActa(){//cambia el estado del acta a cerrado
    if (notaFinal == -1){
        cout << "calificacion final no calculada Error_404" << endl;
        return;
    }
    if (estado == "Cerrado"){
        cout << "El acta ya esta cerrada" << endl;
        return;
    }
    estado = "Cerrado";
    cout << "Se cerro el acta" << endl;
    return;
}

void Acta::calcularNotaFinal(){//Calcula la notaFinal si ya estan listas las calificaciones
    float notaFinal = 0, porcentaje;
    if (CalificacionesJurados.size() < 2){
        cout << "No hay suficientes calificaciones!!" << endl;
        return;
    }
    if (estado == "Cerrado"){
        cout << "El acta ya esta cerrada" << endl;
        return;
    }
    for(list<Calificacion>::iterator calificacion = CalificacionesJurados.begin();calificacion!=CalificacionesJurados.end();calificacion++){
        porcentaje = calificacion->getPorcentajeNota();
        notaFinal += (((calificacion->getNotaJ1() * porcentaje) + (calificacion->getNotaJ2() * porcentaje)));
    }
    this->notaFinal = notaFinal/2;
    cout << "La nota final es de: " << notaFinal << endl;
    if(notaFinal > 3.5){
        estadoTrabajo = "Aprobado";
    } else if (observacionAdicionalJ1 == "" || observacionAdicionalJ1 == ""){
        estadoTrabajo = "Pendiente";
    } else{
        estadoTrabajo = "Rechazado";
    }
    return;
}

void Acta::crearArchivoTXT(){//Crea un archivo .txt donde se guarda informacion del acta
    ofstream File;
    File.open("Actas.txt");
    File << " Nombre del trabajo - ID: " << nombreTrabajo << " - " << idActa << endl;
    File << " Estado: " << estado << endl;
    File << " Fecha: " << fecha << endl;
    File << " Tipo de trabajo: " << tipoTrabajo << endl;
    File << " Estado: " << estado << endl;
    File << " Estado: " << estadoTrabajo << endl;
    File << " Nota final: " <<  notaFinal << endl;
    File << "Autor: " << endl;
    File << " Nombre y cargo: " << autor.getNombre() << " - " << autor.getRol() << endl;
    File << " Email y telefono: " << autor.getEmail() << " - " << autor.getTelefono() << endl;
    File << " Codigo: " << autor.getCodigo() << endl;
    File << "Primer jurado: " << endl;
    File << " Nombre y cargo: " << jurado1.getNombre() << " - " << jurado1.getRol() << endl;
    File << " Email y telefono: " << jurado1.getEmail() << " - " << jurado1.getTelefono() << endl;
    File << " Codigo: " << jurado1.getCodigo() << endl;
    File << "Segundo jurado: " << endl;
    File << " Nombre y cargo: " << jurado2.getNombre() << " - " << jurado2.getRol() << endl;
    File << " Email y telefono: " << jurado2.getEmail() << " - " << jurado2.getTelefono() << endl;
    File << " Codigo: " << jurado2.getCodigo() << endl;
    File << "Director: " << endl;
    File << " Nombre y cargo: " << director.getNombre() << " - " << director.getRol() << endl;
    File << " Email y telefono: " << director.getEmail() << " - " << director.getTelefono() << endl;
    File << " Codigo: " << director.getCodigo() << endl;
    if (codirectorEstado){
        File << "Codirector: " << endl;
        File << " Nombre y cargo: " << codirector.getNombre() << " - " << codirector.getRol() << endl;
        File << " Email y telefono: " << codirector.getEmail() << " - " << codirector.getTelefono() << endl;
        File << " Codigo: " << codirector.getCodigo() << endl;
    } else {
        File << "Codirector: " << "---No existe---" << endl;
    }
    File << "Critrerios de evaluacion" << endl;
    for(list<Calificacion>::iterator calificacion = CalificacionesJurados.begin();calificacion!=CalificacionesJurados.end();calificacion++){
        File << "ID de Criterio: " << calificacion->getIdCriterio() << endl;
        File << "Porcentaje: " << calificacion->getPorcentajeNota() << endl;
        File << "Descripcion Criterio:\n " << calificacion->getDescripcionCriterio() << endl;
        File << "Nota del jurado 1: " << calificacion->getNotaJ1() << endl;
        File << "Comentarios del jurado 1:\n " << calificacion->getComentarioJ1() << endl;
        File << "Nota del jurado 2: " << calificacion->getNotaJ2() << endl;
        File << "Comentarios del jurado 1:\n " << calificacion->getComentarioJ2() << endl;
    }
    File.close();
    return;
}