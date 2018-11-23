#include <iostream>
#include <cstring>

using namespace std;

const int TAMANO_MAX = 100000;

struct FrecuenciaCaracter{
    char caracter;
    int frecuencia;
};

int AumentarContador(char caracter, int contadores[][2], int tamano, FrecuenciaCaracter & moda){
    int nuevo_tamano = tamano;
    bool anadido = false;
        
    for (int i = 0; i < tamano && !anadido; i++){
        if (contadores[i][0] == caracter){
            contadores[i][1]++;
            if (moda.frecuencia < contadores[i][1]){
                moda.caracter = contadores[i][0];
                moda.frecuencia = contadores[i][1];
            }
            
            anadido = true;
        }
    }
    if (!anadido){
        contadores[tamano][0] = caracter;
        contadores[tamano][1] = 1;
        nuevo_tamano++;
    }
    
    return nuevo_tamano;
}


FrecuenciaCaracter Moda(char cadena[]){
    //Eficiencia O(N)
    const int tamano_cadena = strlen(cadena);
    FrecuenciaCaracter moda = {cadena[0], 1};
    int contadores[TAMANO_MAX][2] = {{cadena[0], 1}};
    int tamano_contadores = 1;
    
    for (int i = 1; i < tamano_cadena; i++){
        tamano_contadores = AumentarContador(cadena[i], contadores, tamano_contadores, moda);
    }
    
    return moda;
}
/*
FrecuenciaCaracter Moda(char cadena[]){
    //Eficiencia O(N^2)
    FrecuenciaCaracter moda = {cadena[0], 1};
    int contador = 0;
    for (int i = 0; i < strlen(cadena); i++){
        contador = 0;
        for (int j = 0; j < strlen(cadena); j++){
            if (cadena[j] == cadena[i]){
                contador++;
            }
        }
        
        if (contador > moda.frecuencia){
            moda.caracter = cadena[i];
            moda.frecuencia = contador;
        }
    }
    return moda;
}
*/
int main(){
    char cadena[TAMANO_MAX];
    FrecuenciaCaracter resultado;
    
    cout << "Introduce una cadena de caracteres: ";
    cin.getline(cadena, TAMANO_MAX);
    
    resultado = Moda(cadena);
    
    cout << "El caracter que más se repite es '" << resultado.caracter << "' con una frecuencia de " << resultado.frecuencia << endl;
    
    return 0;
}
