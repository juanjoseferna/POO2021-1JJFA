#include <iostream>
#include "jurado.h"

class Jurado{
	private:
		std::string tipo;
		Calificacion calificacionesJurado;
		std::string observaciones [10];
	public:
		Jurado();
		void editarNota();
};

Jurado::Jurado(){}

void Jurado::editarNota(){
	int opc = -1;
	float nota;
	std::cout << "Ingrese que cual es la nota que desearia Cambiar" << std::endl;
	std::cout << " 1. Desarrollo y profundidad en el tratamiento del tema" << std::endl;
	std::cout << " 2. Desafío académico y científico del tema" << std::endl;
	std::cout << " 3. Cumplimiento de los objetivos propuestos" << std::endl;
	std::cout << " 4. Creatividad e innovación de las soluciones y desarrollos propuestos" << std::endl;
	std::cout << " 5. Validez de los resultados y conclusiones" << std::endl;
	std::cout << " 6. Manejo y procesamiento de la información y bibliografía" << std::endl;
	std::cout << " 7. Calidad y presentación del documento escrito" << std::endl;
	std::cout << " 8. Presentación oral" << std::endl;
	std::cout << " 0. Para salir" << std::endl;
	do{
		std::cin >> opc;
		std::cout << "Ingrese la calificacion correspondiente: ";
		std::cin >> nota;
		switch (opc){
		case 1:
			calificacionesJurado.setNotaDesarrollo(nota);
			break;
		case 2:
			calificacionesJurado.setNotaDesafio(nota);
			break;
		case 3:
			calificacionesJurado.setNotaCumplimiento(nota);
			break;
		case 4:
			calificacionesJurado.setNotaInnovacion(nota);
			break;
		case 5:
			calificacionesJurado.setNotaResultados(nota);
			break;
		case 6:
			calificacionesJurado.setNotaInformacion(nota);
			break;
		case 7:
			calificacionesJurado.setNotaCalidadDoc(nota);
			break;
		case 8:
			calificacionesJurado.setNotaPresentacion(nota);
			break;
		}
	} while (opc != 0);
	return;
}