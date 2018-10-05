#include <iostream>

using namespace std;

int main(){
    int entero;
    char caracter;

    cout << "Introduce un numero del 0 al 9: ";
    cin >> caracter;

    entero = caracter - 48;

    cout << "Valor que has introducido transformado a int: " << entero << endl;

    return 0;
}
