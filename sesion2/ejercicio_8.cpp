#include <iostream>
using namespace std;

int main(){
    int numero = 0;
    int centenas, decenas, unidades = 0;
    
    cout << "Introduce el número deseado: ";
    cin >> numero;
    
    centenas = numero/100;
    numero = numero - centenas*100;
    decenas = numero/10;
    numero = numero - decenas*10;
    unidades = numero;

    cout << centenas << " " << decenas << " " << unidades << endl; 
    return 0;
}
