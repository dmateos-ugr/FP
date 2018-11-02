#include <iostream>

using namespace std;

int main(){
    const int TAMANO_MAXIMO = 10000;
    int vector1[TAMANO_MAXIMO] = {0}, vector2[TAMANO_MAXIMO] = {0}, vector_result[TAMANO_MAXIMO] = {0};
    int tamano_real1, tamano_real2;

    //Entrada
    cout << "Introduzca el tamaño del primer vector ordenado: ";
    cin >> tamano_real1;
    cout << "Introduzca el tamaño del segundo vector ordenado: ";
    cin >> tamano_real2;
    
    for (int i = 0; i < tamano_real1; i++){
        cout << "Introduzca el elemento " << i << " del primer vector: ";
        cin >> vector1[i];
    }
    for (int i = 0; i < tamano_real2; i++){
        cout << "Introduzca el elemento " << i << " del segundo vector: ";
        cin >> vector2[i];
    }
    
    //Cálculos
    /*
    El bucle se realiza hasta que se hayan recorrido ambos vectores. Si aún no
    se han recorrido ambos, se comparan los elementos entre ellos. Si ya se ha
    terminado de recorrer uno, se añaden los elementos del otro.
    */
    int i1 = 0, i2 = 0, i_result = 0;
    while (i1 < tamano_real1 || i2 < tamano_real2){
        if (i1 < tamano_real1 && i2 < tamano_real2){
            if (vector1[i1] < vector2[i2]){
                vector_result[i_result] = vector1[i1];
                i1++;
            } else {
                vector_result[i_result] = vector2[i2];
                i2++;
            }
        } else if (i1 < tamano_real1){
            vector_result[i_result] = vector1[i1];
            i1++;
        } else {
            vector_result[i_result] = vector2[i2];
            i2++;
        }
        i_result++;
    }

    //Salida
    cout << "El vector final es: ";
    for (int i = 0; i < i_result; i++){
        cout << vector_result[i] << " ";
    }
    cout << endl;
    return 0;
}
