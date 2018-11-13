#include <iostream>

using namespace std;

void tachar_multiplos(int n, bool primos[], int tamano){
    //Tacha todos los múltiplos de un número excepto él mismo
    for (int i = 2; i*n < tamano; i++){
        primos[i*n] = false;
    }
    
}


int main(){
    const int TAMANO_MAX = 1000000;
    bool primos[TAMANO_MAX];
    int tamano;
    
    //Entrada
    cout << "Introduce un número: ";
    cin >> tamano;
    
    //Inicialización
    for (int i = 0; i < tamano; i++){
        primos[i] = true;
    }
    primos[0] = false; primos[1] = false;
    
    //Cálculo
    for (int i = 2; i < tamano; i++){
        if (primos[i]){
            tachar_multiplos(i, primos, tamano);
        }
    }
    
    //Salida
    cout << "Los números primos menores que " << tamano << " son: ";
    for (int i = 0; i < tamano; i++){
        if (primos[i]){
            cout << i << " ";
        }
    }
    cout << endl;
    
    return 0;
}
