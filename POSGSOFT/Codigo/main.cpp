#include <iostream>
#include <string>
#include "criterio.h"
#include "persona.h"
#include "registro.h"
#include "acta.h"

int menu(){
    int opcion;
    cout << "Menu del sistema de actas de grado"<< endl;
    cout << " 1. Crear acta" << endl;
    cout << " 2. Para eliminar acta" << endl;
    cout << " 3. Para ver el menu de las calificaciones" << endl;
    cin >> opcion;
    return opcion;
} 

int main(){
	int opcion;
	Registro actas;
	do{
		opcion = menu();
		switch(opcion){
			case 1:
				actas.agregarActa();
				break;
			case 2:
				actas.borrarActa();
				break;
			case 3:
				actas.imprimirActas();
				break;
			case 4:
				actas.editarActa();
				break;
		}
	} while(opcion != 0);
	return 0;
}