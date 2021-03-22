#include <iostream>
#include "criterio.h"

Criterio::Criterio(){}

void Criterio::crearCriterio(int id){//le da informacion de un criterio segun el id que mande
    this->id = id;
    if (id == 0){
        descripcion = "Desarrollo y profundidad en el tratamiento del tema";
        porcentaje = 0.2;
    } else if (id == 1){
        descripcion = "Desafio academico y cientifico del tema";
        porcentaje = 0.15;
    } else if (id == 2){
        descripcion = "Cumplimiento de los objetivos propuestos";
        porcentaje = 0.1;
    } else if (id == 3){
        descripcion = "Creatividad e innovacion de las soluciones y desarrollos propuestos";
        porcentaje = 0.1; 
    } else if (id == 4){
        descripcion = "Validez de los resultados y conclusiones";
        porcentaje = 0.2;
    } else if (id == 5){
        descripcion = "Manejo y procesamiento de la informacion y bibliografia";
        porcentaje =0.1;
    } else if (id == 6){
        descripcion = "Calidad y presentación del documento escrito";
        porcentaje = 0.075;
    } else if (id == 7){
        descripcion = "Presentacion oral";
        porcentaje = 0.075;
    }
    return;
}

float Criterio::getPorcentaje(){//retorna el porcentaje del criterio
    return porcentaje;
}

string Criterio::getDescripcion(){//retorna la descricion de un criterio
    return descripcion;
}

int Criterio::getId(){
    return id;
}

void Criterio::mostrarCriterio(){//Imprime la informacion de un criterio
	cout << " ID: " << id << endl;
	cout << " Peso en la nota final (total = 1): " << porcentaje << endl;
	cout << " Descripcion : " << descripcion << endl;
	return;
}