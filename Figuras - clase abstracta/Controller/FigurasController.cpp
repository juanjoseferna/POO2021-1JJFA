#include "../Controller/FigurasController.h"
const int FigurasController::MAX_ITEMS = 10;

void FigurasController::agregarRectangulo(const float largo, const float ancho){
    try{
        if (listaRectangulo.size() < MAX_ITEMS)
        {
            cout << "Agrego rectangulo" << endl;
            Rectangulo *pRectTemp = new Rectangulo(largo, ancho);
            listaRectangulo.push_back(*pRectTemp);
            pListaFiguras.push_back(pRectTemp);
        }
        else
        {
            //FIXME agregar manejo de excepcion
            std::cout << "\nSe sobrepasa el limite\n"
                    << std::endl;
        }
    }catch(const string *error){
        cout << " Error: " << error << endl;
    }
    return;
}

void FigurasController::agregarCirculo(float radio){
    try{
        if (listaCirculo.size() < MAX_ITEMS)
        {
            cout << "Agrego circulo" << endl;
            Circulo *pcirculoTemp = new Circulo(radio);
            listaCirculo.push_back(*pcirculoTemp);
            pListaFiguras.push_back(pcirculoTemp);
        }
        else
        {
            std::cout << "\nSe sobrepasa el limite\n"
                    << std::endl;
        }
    }catch(const string *error){
        cout << " Error: " << error << endl;
    }
    return;
}

void FigurasController::agregarTriangulo(const float base, const float altura){
    try{
        if (listaTriangulo.size() < MAX_ITEMS)
        {
            cout << "Agrego triangulo" << endl;
            Triangulo *pTrianTemp = new Triangulo(base, altura);
            listaTriangulo.push_back(*pTrianTemp);
            pListaFiguras.push_back(pTrianTemp);
        }
        else
        {
            std::cout << "\nSe sobrepasa el limite\n"
                    << std::endl;
        }
    }catch(const string *error){
        cout << " Error: " << error << endl;
    }
    return;
}

void FigurasController::agregarCuadrado( float lado ) {
    try{
        if (listaCuadrado.size() < MAX_ITEMS){
            cout << "Agrego cuadrado" << endl;
            Cuadrado *pCuaTemp = new Cuadrado( lado );
            listaCuadrado.push_back(*pCuaTemp);
            pListaFiguras.push_back(pCuaTemp);
        }
        else{
            std::cout << "\nSe sobrepasa el limite\n"
                    << std::endl;
        }
    }catch(const string *error){
        cout << " Error: " << error << endl;
    }
    return;
}

void FigurasController::llenarListaTodosDummy(){
    Circulo *pMiCirculo = new Circulo(10);
    Rectangulo *pMiRectangulo = new Rectangulo(10, 10);
    Rectangulo *pMiRectangulo2 = new Rectangulo(20, 20);
    Triangulo *pMiTriangulo = new Triangulo(5, 10);
    Cuadrado *pMiCuadrado = new Cuadrado(20);
    this->pListaFiguras.push_back(pMiCirculo);
    this->pListaFiguras.push_back(pMiRectangulo);
    this->pListaFiguras.push_back(pMiRectangulo2);
    this->pListaFiguras.push_back(pMiTriangulo);
    this->pListaFiguras.push_back(pMiCuadrado);
    return;
}

list<Rectangulo> &FigurasController::getListaRectangulo(){
    list<Rectangulo> &lista = listaRectangulo;
    return lista;
}

list<Circulo> &FigurasController::getListaCirculo(){
    list<Circulo> &lista = listaCirculo;
    return lista;
}

list<Triangulo> &FigurasController::getListaTriangulo(){
    list<Triangulo> &lista = listaTriangulo;
    return lista;
}

list<Cuadrado> &FigurasController::getListaCuadrado(){
    list<Cuadrado> &lista = listaCuadrado;
    return lista;
}

list<FiguraGeometrica *> &FigurasController::getListaFiguras(){
    return pListaFiguras;
}

Rectangulo &FigurasController::encontrarMayorAncho(){
    bool isFirst = true;
    int mayorAncho = 0;
    Rectangulo *pRectanguloMayor = NULL;
    for (list<Rectangulo>::iterator it = listaRectangulo.begin(); it != listaRectangulo.end(); ++it){
        if (isFirst){
            int mayorAncho = listaRectangulo.begin()->getAncho();
            isFirst = false;
            pRectanguloMayor = &(*it);
        }
        else{
            if (it->getAncho() > pRectanguloMayor->getAncho()){
                pRectanguloMayor = &(*it);
            }
        }
    }
    return *pRectanguloMayor;
}