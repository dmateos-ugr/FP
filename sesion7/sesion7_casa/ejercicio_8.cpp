#include <iostream>

using namespace std;

int main(){
    const int TAMANO_MAXIMO = 10000;
    char vector[TAMANO_MAXIMO];
    int tamano_real;
    int posicion_lectura = 0, posicion_escritura = 0;
    
    //Entrada    
    cout << "Introduce el tamaño de la cadena: ";
    cin >> tamano_real;

    cout << "Introduce la cadena: ";
    cin.ignore();
    cin.getline(vector, tamano_real+1); //+1 por el caracter de fin de cadena
    
    //Cálculos    
    while (posicion_lectura < tamano_real){
        if (! (vector[posicion_lectura] >= 'A' && vector[posicion_lectura] <= 'Z')){
            vector[posicion_escritura] = vector[posicion_lectura];
            posicion_escritura++;
        }
        posicion_lectura++;
    }

    //Salida
    //El tamaño final del vector es la siguiente posición en la que se iba a escribir,
    //es decir, posicion_escritura. tamano_real no puede ser modificado durante el bucle
    //ya que la cadena se debe recorrer al completo. Podría crear un contador y que
    //tamano_real sea modificado después del bucle, pero encuentro mas práctico usar las
    //variables ya definidas.
    cout << "El vector final es: ";
    for (int i = 0; i < posicion_escritura; i++){
        cout << vector[i];
    }
    cout << endl;

    return 0;
}

