#include <iostream>
#include <cstring> //PROPUESTA: usar cstring para no tener que pedir longitud máxima
using namespace std;

int main(){
    const int TAMANO_MAXIMO = 10000;
    char vector[TAMANO_MAXIMO];
    //int tamano_real; // Esto no sería necesario
    
    //Entrada    
    //cout << "Introduce el tamaño de la cadena: ";
    //cin >> tamano_real;

    cout << "Introduce la cadena: ";
    //cin.ignore();
    cin.getline(vector, TAMANO_MAXIMO); //Así puedes declarar cadenas de cualquier tamaño menor que el máximo
    
    //Cálculos    
    int i = 0;
    while (i < strlen( vector )){
        if (vector[i] >= 'A' && vector[i] <= 'Z'){
            for (int j = i; j < tamano_real; j++){
                vector[j] = vector[j+1];
            }
           // tamano_real--; Tampoco sería necesario porque el '\0' se desplaza
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

