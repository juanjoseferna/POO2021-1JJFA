//
// Created by lufe0 on 7/05/2021.
//

#include "Controller.h"
#include "../Model/Mayor13.h"
#include "../Model/AdivinoParesImpares.h"
#include "../Model/DosColores.h"
#include "../Model/PiedraPapelTijera.h"
#include "../Model/sacaTres.h"

Controller::Controller() {
  this->casino = Casino();
  // Se agregan los juegos disponibles para el casino
  Mayor13 * juego1 = new Mayor13();
  DosColores * juego2 = new DosColores();
  AdivinoParesImpares * juego3 = new AdivinoParesImpares();
  PiedraPapelTijera * juego4 = new PiedraPapelTijera();
  sacaTres * juego5 = new sacaTres();
  casino.agregarJuego(juego1);
  casino.agregarJuego(juego2);
  casino.agregarJuego(juego3);
  casino.agregarJuego(juego4);
  casino.agregarJuego(juego5);
}

void Controller::agregarJugador(long id, string nombreJugador, double dinero){
    // Se agrega jugador solo si no existe con anticipacion
    if (casino.verExisteJugador(id) == false){
        // Se convierte el dinero a Gonzos
        float cantGonzos = casino.convertirPesosAGonzos(dinero);
        Jugador * pJugador = new Jugador (id, nombreJugador, cantGonzos);
        casino.agregarJugador(pJugador);

    }else {
        throw std::domain_error("El jugador con la identificacion recibida ya existe\n");
    }
}

bool Controller::jugar(int idJuego, long idJugador, float gonzosApostar) {
    float gonzosActuales = casino.consultarJugador(idJugador)->getCantGonzos();
    if (casino.verExisteJugador(idJugador) == false){
        throw std::domain_error("El jugador con la identificacion recibida NO existe, no es posible jugar\n");
    }
    if (idJuego > casino.consultarJuegos().size()){
        throw std::domain_error("NO existe el juego que desea jugar\n");
    }
    if (verPuedeContinuar(idJugador)== false){
        throw std::domain_error("No tienes saldo suficiente para jugar\n");
    }
    if (gonzosActuales < gonzosApostar){
        throw std::domain_error("No tienes saldo suficiente para jugar\n");
    }
    casino.consultarJugador(idJugador)->actualizarGonzos(-gonzosApostar);//Quita los gonzos a apostar
    // Si no hay errores se inicia el juego
    int posJuego = idJuego -1; // Se corrige la posicion para acceder al juego
    Juego * pJuegoAJugar = casino.consultarJuegos().at(posJuego);
    // Consutlta al jugador, consulta los gonzos iniciales, juega y obtiene el resultado
    casino.consultarJugador(idJugador)->mostrarInfo();
    gonzosApostar= pJuegoAJugar->jugar(gonzosApostar);
    // Actualiza el saldo del jugador con el resultado
    casino.consultarJugador(idJugador)->actualizarGonzos(gonzosApostar);
    // Actualiza la cantidad de juegos jugados
    casino.consultarJugador(idJugador)->aumentarJuegos();
    // Retorna verdadero si el jugador ganó y false si el jugador perdio
    if (gonzosApostar == 0){
        return false;
    } else {
        casino.consultarJugador(idJugador)->aumentarJuegosGanados();
        return true;
    }
}

void Controller::verInfoJugador(long idJugador){
    // En teoría esta excepción no debería salir nunca pero se pone como táctica de programación segura.
    if (casino.verExisteJugador(idJugador) == false){
        throw std::domain_error("El jugador con la identificacion recibida NO existe\n");
    }
    Jugador * pJugador = casino.consultarJugador(idJugador);
    pJugador->mostrarInfo();
}

bool Controller::verPuedeContinuar(int idJugador) {
    // En teoría esta excepción no debería salir nunca pero se pone como táctica de programación segura.
    if (casino.verExisteJugador(idJugador) == false) {
        throw std::domain_error("El jugador con la identificacion recibida NO existe");
    }
    Jugador *pJugador = casino.consultarJugador(idJugador);
    if (pJugador->getCantGonzos() == 0) {
        return false;
    }
    return true;
}

void Controller::retirarJugador(long idJugador) {
    if (!casino.verExisteJugador(idJugador)) {
        throw std::domain_error("El jugador con la identificacion recibida NO existe");
    }
    casino.retirarJugador(idJugador);
    //cout << "Fase dos, por hacer \n";
}

void Controller::recargarGonzos(long idJugador, double dinero) {
    float gonzos = casino.convertirPesosAGonzos(dinero);
    int azar;
    if (casino.verExisteJugador(idJugador)){
        srand(time(nullptr));
        azar = 1+rand()%11;// numeros de 1 a 10
        if (azar > 5){
            cout << "Felicidades! Tus gonzos se han multiplicado" << endl;
            gonzos *= 2;
        }
        casino.consultarJugador(idJugador)->actualizarGonzos(gonzos);
    } else {
        throw std::domain_error("El jugador con la identificacion recibida no existe\n");
    }
}

void Controller::gonzosDinero(long idJugador, double gonzos){
    double dinero = casino.convertirGonzosPesos(gonzos);
    int azar;
    float gonzosActuales = casino.consultarJugador(idJugador)->getCantGonzos();
    if (casino.verExisteJugador(idJugador)){
        if(gonzosActuales >= gonzos) {
            casino.consultarJugador(idJugador)->actualizarGonzos(-gonzos);
        } else {
            throw std::domain_error("Insuficientes gonzos\n");
        }
    }else {
        throw std::domain_error("El jugador con la identificacion recibida no existe\n");
    }
}