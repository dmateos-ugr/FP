#include <iostream>

using namespace std;

int main(){
    const int TAMANO_MAX = 1000;
    int vector[TAMANO_MAX];
    int tamano;
    int posiciones[2];
    
    //Entradas
    cout << "Introduzca el tamaño del vector de enteros: ";
    cin >> tamano;
    cout << "Introduzca los elementos del vector: ";
    for (int i = 0; i < tamano; i++){
        cin >> vector[i];
    }
    cout << "Introduzca el índice de un elemento: ";
    cin >> posiciones[0];
    cout << "Introduzca el índice de otro elemento: ";
    cin >> posiciones[1];
    
    //Ajuste para que el 1 sea el primer índice
    posiciones[0]--;
    posiciones[1]--;
    
    //Cálculos
    int aux = vector[posiciones[0]];
    vector[posiciones[0]] = vector[posiciones[1]];
    vector[posiciones[1]] = aux;
    
    //Salida
    cout << "El vector resultante de intercambiar ambos elementos es: ";
    for (int i = 0; i < tamano; i++){
        cout << vector[i] << " ";
    }
    cout << endl;
    
    return 0;
}
