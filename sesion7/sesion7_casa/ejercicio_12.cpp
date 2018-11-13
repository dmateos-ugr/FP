#include <iostream>

using namespace std;

int main(){
    const int TAMANO_MAX = 1000;
    int vector[TAMANO_MAX];
    int tamano;
    int resultado = 1;
        
    //Entrada
    cout << "Introduzca el tamaño del vector: ";
    cin >> tamano;
    cout << "Introduzca los elementos del vector: ";
    for (int i = 0; i < tamano; i++){
        cin >> vector[i];
    }
    
    //Cálculos
    for (int i = 1; i < tamano; i++){
        if (vector[i] < vector[i-1]){
            resultado++;
        }
    }
    
    //Salida
    cout << "En el vector introducido hay " << resultado << " secuencias ascendentes." << endl;
    
    return 0;
}
