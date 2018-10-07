#include <iostream>

using namespace std;

int main(){
    char caracter_mayus;
    char caracter_minus;

    cout << "Introduzca una letra mayúscula: ";
    cin >> caracter_mayus;

    caracter_minus = caracter_mayus+32;
    cout << "El caracter en minusculas es: " << caracter_minus << endl;

    return 0;
}
