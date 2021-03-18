all: compilar
compilar: persona criterio calificacion acta registro main
	g++ -o Salida persona.o criterio.o calificacion.o acta.o registro.o main.o
persona: persona.cpp persona.h
	g++ -c persona.cpp
criterio: criterio.cpp criterio.h
	g++ -c criterio.cpp
calificacion: calificacion.cpp calificacion.h
	g++ -c calificacion.cpp
acta: acta.cpp acta.h
	g++ -c acta.cpp
registro: registro.cpp registro.h
	g++ -c registro.cpp
main: main.cpp persona.h criterio.h calificacion.h acta.h registro.h
	g++ -c main.cpp
