#include <iostream>

using namespace std;

int main(){
    const int TAMANO_MAXIMO = 10000;
    char vector[TAMANO_MAXIMO];
    int tamano_real;
    

    //Entrada    
    cout << "Introduce el tamaño del vector: ";
    cin >> tamano_real;

    cout << "Introduce la cadena1: ";
    cin >> vector;

    //Cálculos
    //cout << vector1[0] << " " << vector2[0] << endl;

    int i = 0;
    while (i < tamano_real){
        if (vector[i] >= 'A' && vector[i] <= 'Z'){
            cout << "Eliminado elemento " << vector[i] << endl;
            for (int j = i; j++; j < tamano_real-1){
                vector[j] = vector[j+1];
            }
            tamano_real--;
        }
        i++;
    }

    cout << "El vector final es: ";
    for (int i = 0; i < tamano_real; i++){
        cout << vector[i];
    }
    cout << endl;

    return 0;
}

