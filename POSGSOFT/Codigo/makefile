all: compilar
compilar: persona criterio calificacion acta main
	g++ -o Salida persona.o criterio.o calificacion.o acta.o main.o
persona: persona.cpp persona.h
	g++ -c persona.cpp
criterio: criterio.cpp criterio.h
	g++ -c criterio.cpp
calificacion: calificacion.cpp calificacion.h
	g++ -c calificacion.cpp
acta: acta.cpp acta.h
	g++ -c acta.cpp
main: main.cpp persona.h criterio.h calificacion.h acta.h
	g++ -c main.cpp
