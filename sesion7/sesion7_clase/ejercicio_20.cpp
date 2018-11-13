#include <iostream>
#include <cstring>

using namespace std;

int main(){
    const int TAMANO_MAX = 10000;
    char cadena1[TAMANO_MAX];
    char cadena2[TAMANO_MAX];
    int pos;
    int tamano_cadena2;
    
    //Entrada
    cout << "Introduzca una cadena: ";
    cin.getline(cadena1, TAMANO_MAX);
    cout << "Introduzca la cadena a insertar: ";
    cin.getline(cadena2, TAMANO_MAX);
    cout << "Introduzca la posición en la que quiere insertar la cadena: ";
    cin >> pos;
    
    //Cálculo
    tamano_cadena2 = strlen(cadena2);
    for (int i1 = pos, i2 = 0; i1 < pos + tamano_cadena2; i1++, i2++){
        cadena1[i1 + tamano_cadena2] = cadena1[i1];
        cadena1[i1] = cadena2[i2];
    }
    
    //Salida
    cout << "La cadena resultante es: " << cadena1 << endl;
    
    return 0;
}
