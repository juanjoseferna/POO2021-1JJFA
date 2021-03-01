//#ifndef FIGURAS_H
//#define FIGURAS_H

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

//#endif /* !FIGURAS_H */