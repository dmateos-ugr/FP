#include <iostream>

using namespace std;

int main(){
    const int TAMANO_MAXIMO = 10000;
    char vector[TAMANO_MAXIMO];
    int tamano_real;
    
    //Entrada    
    cout << "Introduce el tamaño de la cadena: ";
    cin >> tamano_real;

    cout << "Introduce la cadena: ";
    cin.ignore();
    cin.getline(vector, tamano_real+1); //+1 por el caracter de fin de cadena
    
    //Cálculos    
    int i = 0;
    while (i < tamano_real){
        if (vector[i] >= 'A' && vector[i] <= 'Z'){
            for (int j = i; j < tamano_real; j++){
                vector[j] = vector[j+1];
            }
            tamano_real--;
        } else {
            i++;
        }
    }

    //Salida
    cout << "El vector final es: ";
    for (int i = 0; i < tamano_real; i++){
        cout << vector[i];
    }
    cout << endl;

    return 0;
}

