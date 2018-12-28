#include <iostream>

using namespace std;

const int TAM_MAX = 1000;

void DecimalToBinary(int decimal, int vector[], int & tamano){
    for (int i = tamano; i > 0; i--){
        vector[i] = vector[i-1];
    }
    tamano++;
    if (decimal < 2){
        vector[0] = decimal;
    } else {
        vector[0] = decimal%2;
        DecimalToBinary(decimal / 2, vector, tamano);
    }
}


int main(){
    int v[TAM_MAX], tamano = 0, dec;
    
    cout << "Introduzca un decimal: ";
    cin >> dec;
    
    DecimalToBinary(dec, v, tamano);
    
    cout << "Su representación en binario es: ";
    for (int i = 0; i < tamano; i++){
        cout << v[i] << " ";
    }
    cout << endl;
    
    return 0;
}
