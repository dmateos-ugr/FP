#include <iostream>

using namespace std;

int main(){
    const int TAMANO_MAXIMO = 10000;
    int vector[TAMANO_MAXIMO] = {0};
    int tamano_real, tamano_real_result = 0;
    bool valor_repetido = false;

    //Entrada
    cout << "Introduzca el tamaño del vector: ";
    cin >> tamano_real;

    for (int i = 0; i < tamano_real; i++){
        cout << "Introduzca el elemento " << i << " del vector: ";
        cin >> vector[i];
    }

    //1 1 2 3 4 4 5
    //Cálculo:
    /*
    i apunta a la posición del elemento analizado.
    Este elemento se compara con todos los demás.
    j apunta a la posición del elemento con el que se compara el elemento en i.
    Si ambos son iguales, se elimina el elemento situado en j.
    Si no lo son, i aumenta (se pasa al siguiente elemento)
    */  
    int j = 0, i = 0;
    while (i < tamano_real){
        valor_repetido = false;
        j = i;
        while (j < tamano_real && !valor_repetido){
            j++;
            cout << vector[i] << " " << vector[j] << endl;
            if (vector[i] == vector[j]){
                valor_repetido = true;                
            }            
        }

        if (valor_repetido){
            cout << "Valor eliminado: " << vector[j-1] << endl;
            for (int k = j; k < tamano_real; k++){
                vector[k] = vector[k+1];
            }
            tamano_real--;
        } else {
            i++;
        }
    }

    //Salida
    cout << "Los elementos del vector final son: ";    
    for (int i = 0; i < tamano_real; i++){
        cout << vector[i] << " ";
    }
    cout << endl;
    
    return 0;
}
