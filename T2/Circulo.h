//#ifndef FIGURAS_H
//#define FIGURAS_H

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

//#endif /* !FIGURAS_H */