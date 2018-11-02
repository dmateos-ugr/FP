#include <iostream>

using namespace std;

int main(){
    const int TAMANO_MAXIMO = 10000;    
    int tamano_real1, tamano_real2;
    int vector1[TAMANO_MAXIMO] = {0}, vector2[TAMANO_MAXIMO] = {0};
    bool es_el_mismo = true;
    
    cout << "Introduzca el número de elementos del primer vector (máximo 10000): ";
    cin >> tamano_real1;
    cout << "Introduzca el número de elementos del segundo vector (máximo 10000): ";
    cin >> tamano_real2;

    //Comprobación inicial.
    if (tamano_real1 == tamano_real2) {
        //Entrada
        for (int i = 0; i < tamano_real1; i++){
            cout << "Introduce el elemento " << i << " del primer vector: ";
            cin >> vector1[i];
            cout << "Introduce el elemento " << i << " del segundo vector: ";
            cin >> vector2[i];
        }

        //Cálculos
        int i = 0;
        while (i < tamano_real1 && es_el_mismo){
            if (vector1[i] != vector2[i]){
                es_el_mismo = false;
            }
            i++;
        }

    } else {
        es_el_mismo = false;
    }

    //Salida
    if (es_el_mismo){
        cout << "Ambos vectores tienen los mismos elementos." << endl;
    } else {
        cout << "Los dos vectores son diferentes." << endl;
    }

    return 0;
}
