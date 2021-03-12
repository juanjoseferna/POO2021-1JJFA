//#ifndef ACTA_H
//#define ACTA_H
#include <iostream>

class Acta{
	private:
		int ID;
		std::string Fecha, Nombre, Estado, Periodo;
		Jurado jurado1, jurado2;
	public:
		Acta();
};

//#endif /* !ACTA_H */