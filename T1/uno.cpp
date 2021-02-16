#include <iostream>
using namespace std;

int calcularIVA ( int num1 ){
    num1 = num1 + ( num1 * 0.19 );
    return num1;
}

int main (){
    int precio_final;
    cout <<"Ingrese el precio del producto"<<endl;
    cin >>precio_final;
    precio_final = calcularIVA( precio_final );
    cout <<precio_final<<endl;
    return 0;
}