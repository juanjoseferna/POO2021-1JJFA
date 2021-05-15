//
// Created by lufe0 on 7/05/2021.
//

#include "View.h"

View::View(){
    controller = Controller();
}
void View::agregarJugador()
{
    string nombreJugador;
    float dineroPesos;
    long idJugador;
    cout << "Ingrese el nombre del jugador \n";
    cin.ignore(100, '\n');
    getline(cin, nombreJugador);
    // Id del jugador
    cout << "Ingrese el id del jugador \n";
    cin >> idJugador;
    // Validacion de los datos del jugador
    do
    {
        cout << "Ingrese el dinero en pesos \n";
        cin >> dineroPesos;
    } while (dineroPesos <= 0);

    // Esta linea de codigo controla la excepcion que lanza el controller y lo muestra en pantalla
    try {
        controller.agregarJugador(idJugador, nombreJugador, dineroPesos);
    } catch (std::domain_error ex) {
        cout << "ERROR: " << ex.what();
    }
}


void View::pedirUsuario(){
    try {
        long idJugador;
        cout << "Ingrese el id del jugador para el que quiere jugar \n";
        cin >> idJugador;
        // LLama a la función que hacer toda la logica de jugar.
        jugarView(idJugador);
    }catch (std::domain_error ex){
        // Se muestra un error si el usuario no existe
        cout << ex.what();
    }
}

void View:: jugarView(long idJugador) {
    float cantGonzos;
    int idJuego, opc;
    do{
        cout << "Lista de juegos: " << endl;
        cout << "1. Mayor trece " << endl;
        cout << "2. Dos colores " << endl;
        cout << "3. Adivino de pares e impares " << endl;
        cout << "4. Piedra papel o tijera " << endl;
        cout << "5. Saca tres " << endl;
        cout << "Digita el id del juego que quiere jugar: " << endl;
        cin >> idJuego;
        cout << "Ingrese la cantidad de gonzos que desea apostar" << endl;
        cin >> cantGonzos;
        controller.jugar(idJuego, idJugador, cantGonzos);
        cout << "Desea seguir jugando?" << endl;
        cout << " 1. Si" << endl;
        cout << " 2. No" << endl;
        cin >> opc;
    }while (opc!=2);
}

int View::mostrarMenu()
{
    int opcion;
    cout << "Menu\n";
    cout << "1. Agregar jugador " << std::endl;
    cout << "2. Jugar" << std::endl;
    cout << "3. Consultar jugador" << std::endl;
    cout << "4. Vender gonzos  " << std::endl;
    cout << "5. Comprar gonzos" << endl;
    cout << "6. Eliminar jugador" << endl;
    cout << "0. Salir\n"
         << std::endl;
    cout << "Digita el numero: ";
    cin >> opcion;
    return opcion;
}

void View::verPrincipal()
{
    int opcion;
    do{
        opcion = mostrarMenu();
        switch (opcion)
        {
            case 1:
                agregarJugador();
                break;
            case 2:
                pedirUsuario();
                break;
            case 3:
                mostrarJugador();
                break;
            case 4:
                gonzosDineroView();
                break;
            case 5:
                recargarGonzosView();
                break;
            case 6:
                retirarJugador();
                break;
        }
    } while (opcion != 0);
}

void View::mostrarJugador() {
    int id;
    cout << "Digita el id del usuario a consultar: " << endl;
    cin >> id;
    controller.verInfoJugador(id);
    // LLama al metodo del controller que muestra los datos
}

void View::retirarJugador() {
    int id;
    cout << "Digita el id del usuario a retirar: " << endl;
    cin >> id;
    controller.retirarJugador(id);
}

void View::recargarGonzosView() {
    int id;
    double dinero;
    cout << "Digita el id del usuario a retirar: " << endl;
    cin >> id;
    cout << "Digita el dinero a recargar: " << endl;
    cin >> dinero;
    controller.recargarGonzos(id, dinero);
}

void View::gonzosDineroView() {
    int id;
    double gonzos;
    cout << "Digita el id del usuario a vender los gonzos: " << endl;
    cin >> id;
    cout << "Digita los gonzos: " << endl;
    cin >> gonzos;
    controller.gonzosDinero(id,gonzos);
}