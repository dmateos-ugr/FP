#include <iostream>

using namespace std;

void CalcularParesImpares(const int v[], int tamano, int pares[], int & tamano_pares, int impares[], int & tamano_impares){
    for (int i = 0; i < tamano; i++){
        if (v[i] % 2 == 0){
            pares[tamano_pares] = v[i];
            tamano_pares++;
        } else {
            impares[tamano_impares] = v[i];
            tamano_impares++;
        }
    }
}

void ImprimirElementos(const int v[], int t){
    for (int i = 0; i < t; i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

int main(){
    const int TAMANO_MAX = 10000;
    int vector[TAMANO_MAX], pares[TAMANO_MAX], impares[TAMANO_MAX];
    int tamano, tamano_pares = 0, tamano_impares = 0;
    
    cout << "Introduzca el tamaño del vector: ";
    cin >> tamano;
    cout << "Introduzca los elementos del vector: ";
    for (int i = 0; i < tamano; i++){
        cin >> vector[i];
    }
    
    CalcularParesImpares(vector, tamano, pares, tamano_pares, impares, tamano_impares);
    
    cout << "Los elementos pares son:" << endl;
    ImprimirElementos(pares, tamano_pares);
    cout << "Los elementos impares son:" << endl;
    ImprimirElementos(impares, tamano_impares);
    
    return 0;
}
