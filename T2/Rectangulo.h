//#ifndef FIGURAS_H
//#define FIGURAS_H

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

//#endif /* !FIGURAS_H */