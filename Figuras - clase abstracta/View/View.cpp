#include "View.h"

void View::pedirDatosRectangulo(){
    float largo, ancho;
    do{
        cout << "Digite el valor del largo " << endl;
        cin >> largo;
        cout << "Digite el valor del ancho " << endl;
        cin >> ancho;
    } while (largo <= 0 || ancho <= 0);
    controller.agregarRectangulo(largo, ancho);
    return;
}

void View::pedirDatosCirculo(){
    float radio;
    do{
        cout << "Digite el radio " << endl;
        cin >> radio;
    } while (radio <= 0);
    controller.agregarCirculo(radio);
    return;
}

void View::pedirDatosTriangulo(){
    float base, altura;
    do
    {
        cout << "Digite la base " << endl;
        cin >> base;
        cout << "Digite la altura " << endl;
        cin >> altura;
    } while (base <= 0 && altura <= 0);
    controller.agregarTriangulo( base, altura );
    return;
}

void View::pedirDatosCuadrado(){
    float lado;
    do{
        cout << "Digite el lado " << endl;
        cin >> lado;
    } while (lado <= 0);
    controller.agregarCuadrado( lado );
    return;
}

void View::mostrarRectangulos(){
    int cont = 0;
    list<Rectangulo> &refListaRectangulo = controller.getListaRectangulo();
    for (list<Rectangulo>::iterator it = refListaRectangulo.begin(); it != refListaRectangulo.end(); ++it)
    {
        cout << "Rectangulo " << ++cont << ":" << endl;
        it->mostrarFigura();
    }
    return;
}

void View::mostrarCirculos(){
    int cont = 0;
    list<Circulo> &refListaCirculo = controller.getListaCirculo();
    for (list<Circulo>::iterator it = refListaCirculo.begin(); it != refListaCirculo.end(); ++it)
    {
        cout << "Circulo " << ++cont << ":" << endl;
        it->mostrarFigura();
    }
    return;
}

void View::mostrarTriangulos(){
    int cont = 0;
    list<Triangulo> &refListaTriangulo = controller.getListaTriangulo();
    for (list<Triangulo>::iterator it = refListaTriangulo.begin(); it != refListaTriangulo.end(); ++it)
    {
        cout << "Triangulo: " << ++cont << ":" << endl;
        it->mostrarFigura();
    }
    return;
}

void View::mostrarCuadrados(){
    int cont = 0;
    list<Cuadrado> &refListaCuadrado = controller.getListaCuadrado();
    for (list<Cuadrado>::iterator it = refListaCuadrado.begin(); it != refListaCuadrado.end(); ++it){
        cout << "Cuadrado: " << ++cont << ":" << endl;
        it->mostrarFigura();
    }
    return;
}

void View::mostrarTodos(){
    controller.llenarListaTodosDummy();
    list<FiguraGeometrica *> &pListaFiguras = controller.getListaFiguras();
    cout << "Cantidad de figuras " << pListaFiguras.size() << "\n";
    int cont = 0;
    for (list<FiguraGeometrica *>::iterator it = pListaFiguras.begin(); it != pListaFiguras.end(); ++it){
        FiguraGeometrica *tmp = *it; // Por descifrar
        cout << "Figura con polimorfismo:" << ++cont << ":" << endl;
        tmp->mostrarFigura();
        cout << "\n";
    }
    return;
}

int View::mostrarMenu()
{
    int opcion;
    cout << "Menu\n"
         << std::endl;
    cout << "1. Agregar Rectangulos" << std::endl;
    cout << "2. Mostrar Rectangulos" << std::endl;
    cout << "3. Agregar Circulos" << std::endl;
    cout << "4. Mostrar Circulos" << std::endl;
    cout << "5. Agregar Triangulos" << std::endl;
    cout << "6. Mostrar Triangulos" << std::endl;
    cout << "7. Agregar Cuadrados" << std::endl;
    cout << "8. Mostrar Cuadrados" << std::endl;
    cout << "9. [Todos] Mostrar todas figuras" << std::endl;
    cout << "11. Caso para pruebas" << std::endl;
    cout << "0. Salir\n"
         << std::endl;
    cout << "Digita el numero: ";
    cin >> opcion;
    return opcion;
}

void View::verPrincipal()
{
    int opcion;
    do
    {
        opcion = mostrarMenu();
        switch (opcion)
        {
        case 1: //Rectangulos
            pedirDatosRectangulo();
            break;
        case 2: //Mostrar Rectangulos
            mostrarRectangulos();
            break;
        case 3:
            pedirDatosCirculo();
            break;
        case 4:
            mostrarCirculos();
            break;
        case 5:
            pedirDatosTriangulo();
            break;
        case 6:
            mostrarTriangulos();
            break;
        case 7:
            pedirDatosCuadrado();
            break;
        case 8:
            mostrarCuadrados();
            break;
        case 9:
            mostrarTodos();
            break;
        case 11:{
            Rectangulo &rectangulo = controller.encontrarMayorAncho();
            rectangulo.mostrarFigura();
        }
        break;
        }
    } while (opcion != 0);
    return;
}