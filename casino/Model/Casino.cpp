//
// Created by lufe0 on 7/05/2021.
//

#include "Casino.h"

// Constructor que inicializa las ganancias y perdidas en cero
Casino::Casino() {
    cout <<"Inicialice casino";
    jugadoresMap.clear(); // Se limpian los jugadores del casino
}


void Casino::agregarJuego(Juego * juego) {
    juegosDisponibles.push_back(juego);
}

void Casino::agregarJugador(Jugador *pJugador) {
    jugadoresMap[ pJugador->getId() ] = pJugador;
}

bool Casino::verExisteJugador(long id) {
    if (jugadoresMap[ id ] != nullptr){
        return true;
    }
    return false;
}

Jugador *Casino::consultarJugador(long id) {
    return jugadoresMap[id]; // Retora el apuntador a jugador.
}

double Casino::convertirPesosAGonzos(double dinero) {
    double gonzos;
    gonzos = dinero / 100;
    return gonzos;
}

vector<Juego *> &Casino::consultarJuegos() {
    return juegosDisponibles;
}

void Casino::retirarJugador(long id) {
    jugadoresMap.erase(id);
}

double Casino::convertirGonzosPesos(float gonzos) {
    double dinero = gonzos * 100;
    return dinero;
}

Casino::~Casino() {

}