#include <iostream>
#include <conio.h>
using namespace std;


int calcularIVA ( int num1 ){
    num1 = num1 + ( num1 * 0.19 );
    return num1;
}

int main (){
    int precio_final;
    cout <<"Ingrese el precio del producto"<<endl;
    scanf("%i", &precio_final);
    precio_final = calcularIVA( precio_final );
    printf ("%i", precio_final);
    return 0;
}