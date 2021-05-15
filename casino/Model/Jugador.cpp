//
// Created by lufe0 on 7/05/2021.
//

#include "Jugador.h"

Jugador::Jugador()
          :cantJuegos(0)
{
}
// Hace llamada delegada al constructor por defecto
Jugador::Jugador(long id, string nombre, float cantGonzos): Jugador() {
    this->id = id;
    this->nombre = nombre;
    this->cantGonzos = cantGonzos;
    this->cantJuegosGanados = 0;
    this->cantJuegos = 0;
}


/* Destructor*/
Jugador::~Jugador()
{
}

void Jugador::mostrarInfo() {
    cout << "ID" << id << endl;
    cout << "Name: " << nombre << endl;
    cout << "Gonzos: " << cantGonzos << endl;
    cout << "Cantidad de jugadas: " << cantJuegos << endl;
    cout << "Cantidad de juegos ganados: " << cantJuegosGanados << endl;
    cout << "Cantidad de juegos perdidos: " << cantJuegos - cantJuegosGanados << endl;
}

void Jugador::aumentarJuegos() {
    // Incrementa la cantidad de juegos que ha jugado el jugador
    cantJuegos++;
}

void Jugador::aumentarJuegosGanados() {
    cantJuegosGanados++;
}

void Jugador::actualizarGonzos(float resultadoJuego) {
    cantGonzos += resultadoJuego;
}

const string &Jugador::getNombre() const {
    return nombre;
}

float Jugador::getCantGonzos() const {
    return cantGonzos;
}

long Jugador::getId() const {
    return id;
}

int Jugador::getCantJuegos() const {
    return cantJuegos;
}





