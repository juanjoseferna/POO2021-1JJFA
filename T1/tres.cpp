#include <iostream>
#include<cstdlib>
#include <string.h>
using namespace std;

struct contacto{
    string nombre, apellido;
    int telefono;
    struct contacto *siguiente;
};

typedef struct contacto *lista;

void registrarPredefinidos ( lista &agenda ){
    lista contacto1, contacto2, contacto3, recorrer;
    contacto1->nombre = "Pepito";
    contacto1->apellido = "Ramirez";
    contacto1->telefono = 3216537467;
    contacto1->siguiente = contacto2;
    contacto2->nombre = "Santiago";
    contacto2->apellido = "Cadena";
    cout << "a" << endl;
    contacto2->telefono = 3134156483;
    contacto2->siguiente = contacto3;
    contacto3->nombre = "Samantha";
    contacto3->apellido = "Lopez";
    contacto3->telefono = 3145166515;
    contacto3->siguiente = NULL;
    if ( agenda == NULL ){
        agenda = contacto1;
    } else {
        recorrer = agenda;
        while( recorrer->siguiente == NULL ){
            recorrer = recorrer->siguiente;
        }
        recorrer->siguiente = contacto1;
    }
    return;
}

void registrarNuevo ( lista &agenda ){
    lista contacto, recorrer;
    cout << "Ingrese el nombre: " << endl;
    cin.getline(contacto->nombre,40);
    cout << "Ingrese el apellido: " << endl;
    cin >> contacto->apellido;
    cout << "Ingrese el numero" << endl;
    cin >> contacto->telefono;
    contacto->siguiente = NULL;
    if ( agenda == NULL ){
        agenda = contacto;
    } else {
        recorrer = agenda;
        while( recorrer->siguiente == NULL ){
            recorrer = recorrer->siguiente;
        }
        recorrer->siguiente = contacto;
    }
    return;
}

void imprimirAgenda( lista &agenda ){
    lista imprimir = agenda;
    int salida, indice = 1;
    if ( imprimir == NULL ){
        cout << "Lista vacia" << endl;
        return;
    }
    while( salida == 0 ){
        if( imprimir == NULL ){
            salida = 1;
        } else {
            cout << "Contacto #" << indice <<endl;
            cout << "Nombre: " << imprimir->nombre << endl;
            cout << "Apellido: " << imprimir->apellido << endl;
            cout << "Numero: " << imprimir->telefono << endl;
            imprimir = imprimir->siguiente;
            indice++;
        }
    }
    
}

int main(){
    int salida = 0, opc;
    lista agenda = NULL;
    registrarPredefinidos( agenda );
    while( salida == 0 ){
        cout << "Ingrese una opcion \n 1. Crear agenda con contactos predefinidos\n 2. Agregar contacto\n 3. Ver lista de contactos\n 0. Para salir"<< endl;
        cin >> opc;
        switch (opc){
            case 1:{
                registrarPredefinidos( agenda );
                break;
            }
            case 2:{
                registrarNuevo( agenda );
                break;
            }
            case 3:{
                imprimirAgenda( agenda );
                break;
            }
        }
    } 
}