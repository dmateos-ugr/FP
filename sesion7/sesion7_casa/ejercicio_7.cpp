#include <iostream>
#include <cstring> 
using namespace std;

int main(){
    const int TAMANO_MAXIMO = 10000;
    char vector[TAMANO_MAXIMO];
   
    cout << "Introduce la cadena: ";
    cin.getline(vector, TAMANO_MAXIMO); 
    
    //Cálculos    
    int i = 0;
    while (i < strlen( vector )){
        if (vector[i] >= 'A' && vector[i] <= 'Z'){
            for (int j = i; j < tamano_real; j++){
                vector[j] = vector[j+1];
            }
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

