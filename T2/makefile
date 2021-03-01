all: compilar
compilar: rectangulo triangulo circulo main
		g++ -o Salida Rectangulo.o Triangulo.o Circulo.o Main.o
rectangulo: Rectangulo.cpp Rectangulo.h
		g++ -c Rectangulo.cpp
triangulo: Triangulo.cpp Triangulo.h
		g++ -c Triangulo.cpp
circulo: Circulo.cpp Circulo.h
		g++ -c Circulo.cpp
main: Main.cpp Rectangulo.h
		g++ -c Main.cpp