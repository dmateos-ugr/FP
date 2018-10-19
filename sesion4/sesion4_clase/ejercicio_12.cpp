#include <iostream>

using namespace std;

int main(){
    int minimo_cadena_1, maximo_cadena_2, dato;

    cout << "Introduce un número para la primera cadena: ";
    cin >> dato;
    minimo_cadena_1 = dato;
    while (dato != 0) {
        if (dato < minimo_cadena_1){
            minimo_cadena_1 = dato;
        }
        cout << "Introduce un número para la primera cadena: ";
        cin >> dato;
    }
    
    cout << "Introduce un número para la segunda cadena: ";
    cin >> dato;
    maximo_cadena_2 = dato;
    while (dato != 0) {
        if (dato > maximo_cadena_2){
            maximo_cadena_2 = dato;
        }
        cout << "Introduce un número para la segunda cadena: ";
        cin >> dato;
    } 
    
    if (minimo_cadena_1 > maximo_cadena_2){
        cout << "\nTodos los números de la primera cadena son mayores a los de la segunda cadena." << endl;
    } else {
        cout << "\nNo todos los números de la primera cadena son mayores a los de la segunda cadena." << endl;
    }

    return 0;
}
