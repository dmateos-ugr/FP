#include <iostream>

using namespace std;

int main(){
    const int TAMANO_MAXIMO = 10000;
    int vector1[TAMANO_MAXIMO], vector2[TAMANO_MAXIMO];
    int tamano_real1, tamano_real2;
    int resultado = 0;
    int i_vector2 = 0;
    int pos_inicio[TAMANO_MAXIMO]; //ampliación
    int i_pos_inicio = 0; //ampliación

    //Entrada    
    cout << "Introduce el tamaño del vector uno: ";
    cin >> tamano_real1;
    do {
        cout << "Introduce el tamaño del vector dos (menor o igual que el del vector uno): ";
        cin >> tamano_real2;
    } while (tamano_real2 > tamano_real1);

    cout << "Introduce el vector1: ";
    for (int i = 0; i < tamano_real1; i++){
        cin >> vector1[i];
    }
    cout << "Introduce el vector2: ";
    for (int i = 0; i < tamano_real2; i++){
        cin >> vector2[i];
    }

    //Cálculos
    for (int i = 0; i < tamano_real1; i++){
        if (vector1[i] == vector2[i_vector2]){
            i_vector2++;
            if (i_vector2 == tamano_real2){
                resultado++;
                pos_inicio[i_pos_inicio] = i - tamano_real2 + 1;
                i_pos_inicio++;
                i_vector2 = 0;
            }
        } else {
            i_vector2 = 0;
        }
    }

    //Salida
    cout << "El vector dos se repite " << resultado << " veces en el vector uno, en las posiciones: ";
    for (int i = 0; i < i_pos_inicio; i++){
        cout << pos_inicio[i];
        if (i + 2 < i_pos_inicio)
            cout << ", ";
    }
    cout << "." << endl;

    return 0;
}
