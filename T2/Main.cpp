#include <iostream>
#include "Triangulo.h"
#include "Rectangulo.h"
#include "Circulo.h"

int menu (){
    int opc;
    std::cout << "Ingrese una opcion:\n 1. Para circulos\n 2. Para Rectangulos\n 3. Para Triangulos\n 0. Para salir" << std::endl;
    std::cin >> opc;
    return opc;
}

int main (){
    const int CAP = 10;
    int opc, totalCir = 0, totalRec = 0,totalTri = 0, i;
    Rectangulo misRectangulos [ CAP ];
    Circulo misCirculos [ CAP ];
    Triangulo misTriangulos [ CAP ];
    do{
        opc = menu();
        switch (opc){
            case 1:
                if ( totalCir  < CAP ){
                    float radio;
                    std::cout << "Ingrese un radio para el Circulo " << totalCir + 1 << ": ";
                    std::cin >> radio;
                    misCirculos[ totalCir ].setRadio( radio );
                    totalCir ++;
                } else {
                    std::cout << "Ya hay suficientes Circulos" << std::endl;
                }
                for (i = 0; i < totalCir; i++){
                    std::cout << "Circulo " << i + 1 << ":" << std::endl;
                    misCirculos[ i ].calcularAreaCir();
                    misCirculos[ i ].calcularPerimetroCir();
                }
                break;
            case 2:
                if ( totalCir  < CAP ){
                    float largo, ancho;
                    std::cout << "Ingrese el largo para el Rectangulo " << totalRec + 1 << ": ";
                    std::cin >> largo;
                    std::cout << "Ingrese el ancho para el Rectangulo " << totalRec + 1 << ": ";
                    std::cin >> ancho;
                    misRectangulos[ totalRec ].setAncho( ancho );
                    misRectangulos[ totalRec ].setLargo( largo );
                    totalRec++;
                } else {
                    std::cout << "Ya hay suficientes Rectangulos" << std::endl;
                }
                for (i = 0; i < totalRec; i++){
                    std::cout << "Rectangulo " << i + 1 << ":" << std::endl;
                    misRectangulos[ i ].calcularAreaRec();
                    misRectangulos[ i ].calcularPerimetroRec();
                }
                break;
            case 3:
                if ( totalTri  < CAP ){
                    float ladoA, ladoB, base, altura;
                    std::cout << "Ingrese el lado A para el Triangulo " << totalTri + 1 << ": ";
                    std::cin >> ladoA;
                    std::cout << "Ingrese el lado B para el Triangulo " << totalTri + 1 << ": ";
                    std::cin >> ladoB;
                    std::cout << "Ingrese la base para el Triangulo " << totalTri + 1 << ": ";
                    std::cin >> base;
                    std::cout << "Ingrese la altura para el Triangulo " << totalTri + 1 << ": ";
                    std::cin >> altura;
                    misTriangulos[ totalTri ].setLadoA( ladoA );
                    misTriangulos[ totalTri ].setLadoB( ladoB );
                    misTriangulos[ totalTri ].setBase( base );
                    misTriangulos[ totalTri ].setAltura( altura );
                    totalTri++;
                } else {
                    std::cout << "Ya hay suficientes Triangulos" << std::endl;
                }
                for (i = 0; i < totalTri; i++){
                    std::cout << "Triangulo " << i + 1 << ":" << std::endl;
                    misTriangulos[ i ].calcularAreaTri();
                    misTriangulos[ i ].calcularPerimetroTri();
                }
                break;
        }
    } while( opc != 0 );
    return 0;
}