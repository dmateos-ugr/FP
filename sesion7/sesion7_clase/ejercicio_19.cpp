#include <iostream>

using namespace std;

int main(){
    const int TAMANO_MAX = 10000;
    char cadena[TAMANO_MAX], resultado[TAMANO_MAX];
    int pos[2];
    int i_resultado = 0;
    
    //Entrada
    cout << "Introduce una cadena: ";
    cin.getline(cadena, TAMANO_MAX);
    cout << "Introduce la posición 1: ";
    cin >> pos[0];
    cout << "Introduce la posición 2: ";
    cin >> pos[1];
    
    //Cálculo
    for (int i = pos[0]; i <= pos[1]; i++){
        resultado[i_resultado] = cadena[i];
        i_resultado++;
    }
    resultado[i_resultado] = '\0';
    
    //Salida
    cout << "La cadena entre esas posiciones es: " << resultado << endl;
    
    return 0;
}
