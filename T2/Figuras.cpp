#include <iostream>

class Rectangulo{
    private:
        float ancho, largo;
    public:
        Rectangulo();
        Rectangulo( float ancho, float largo );
        void calcularAreaRec();
        void calcularPerimetroRec();
        void setAncho( float ancho );
        void setLargo( float largo );
};

class Circulo{
    private:
        float radio;
        const float PI = 3.14159265359;
    public:
        Circulo ();
        Circulo ( float radio );
        void calcularAreaCir();
        void calcularPerimetroCir();
        int getRadio();
        void setRadio( float radio );
};

class Triangulo{
    private:
        float ladoA, ladoB, base, altura;
    public:
        Triangulo();
        Triangulo( float ladoA, float ladoB, float base, float altura );
        void calcularAreaTri();
        void calcularPerimetroTri();
        void setLadoA( float ladoA );
        void setLadoB( float ladoB );
        void setBase( float base );
        void setAltura( float altura );
};

Rectangulo::Rectangulo( float a, float b ){
    this->ancho = a;
    this->largo = b;
}

Rectangulo::Rectangulo(){
    this->ancho = 0;
    this->largo = 0;
}

void Rectangulo::calcularAreaRec(){
    std::cout << "El area del rectangulo es: " << ancho * largo << std::endl;
    return;
}

void Rectangulo::calcularPerimetroRec(){
    std::cout << "El perimetro del rectangulo es: " << ancho * 2 + largo * 2 << std::endl;
    return;
}

void Rectangulo::setAncho ( float ancho ){
    this->ancho = ancho;
    return;
}

void Rectangulo::setLargo( float largo ){
    this->largo = largo;
    return;
}

Circulo::Circulo(){
    this->radio = 0;
}

Circulo :: Circulo ( float radio ){
    this->radio = radio;
}

void Circulo::calcularAreaCir(){
    float area = PI * ( radio * radio );
    std::cout << "El area del circulo es: " << area << std::endl;
    return;
}

void Circulo::calcularPerimetroCir(){
    float perimetro = 2 * radio * PI;
    std::cout << "El perimetro del circulo es: " << perimetro << std::endl;
    return;
}

int Circulo::getRadio(){
    return this->radio;
}

void Circulo::setRadio( float radio ){
    this->radio = radio;
    return;
}

Triangulo::Triangulo( float ladoA, float ladoB, float base, float altura){
    this->ladoA = ladoA;
    this->ladoB = ladoB;
    this->base = base;
    this->altura = altura;
}

Triangulo::Triangulo(){
    this->ladoA = 0;
    this->ladoB = 0;
    this->base = 0;
    this->altura = 0;
}

void Triangulo::calcularAreaTri(){
    std::cout << "El area del triangulo es: " << ( base * altura )/2 << std::endl;
    return;
}

void Triangulo::calcularPerimetroTri(){
    std::cout << "El perimetro del triangulo es: " << ladoA + ladoB + base << std::endl;
}

void Triangulo::setLadoA( float ladoA ){
    this->ladoA = ladoA;
    return;
}

void Triangulo::setLadoB( float ladoB ){
    this->ladoB = ladoB;
    return;
}

void Triangulo::setBase( float base ){
    this->base = base;
    return;
}

void Triangulo::setAltura( float altura ){
    this->altura = altura;
    return;
}

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
                if ( totalCir  < 10 ){
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
                if ( totalCir  < 10 ){
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
                if ( totalTri  < 10 ){
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