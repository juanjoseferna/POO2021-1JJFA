#include <iostream>
using namespace std;

int edadPersona(){
    int edad;
    cout << "Ingrese su edad: " << endl;
    cin >> edad;
    return edad;
}

char sexoPersona(){
    char sexo;
    cout << "Ingrese su sexo: " << endl;
    cin >> sexo;
    return sexo;
}

float estaturaPersona(){
    float estatura;
    cout << "Ingrese su estatura: " << endl;
    cin >> estatura;
    return estatura;
}

int main(){
    int edad = edadPersona();
    char sexo = sexoPersona();
    float estatura = estaturaPersona();
    cout << "Edad: " << edad << "\nSexo: " << sexo << "\nEstatura: " << estatura << endl;
    return 0;
}


