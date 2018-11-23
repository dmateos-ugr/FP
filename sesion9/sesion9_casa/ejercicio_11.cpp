#include <iostream>
#include <cmath>

using namespace std;

const int TAMANO_MAX = 1000;

/*
int SumaDivisores(int n){
    //Calcula y devuelve la suma de los divisores de n.
    int suma_divisores = 0;
    for (int i = 1; i <= n/2; i++){
        if (n % i == 0){
            suma_divisores += i;
        }
    }
    return suma_divisores;
}
*/

int IncrementarFactor(int n, int factores[][2], int tamano){
    int nuevo_tamano = tamano;
    bool anadido = false;
    
    for (int i = 0; i < tamano && !anadido; i++){
        if (factores[i][0] == n){
            factores[i][1]++;
            anadido = true;
        }
    }
    if (!anadido){
        factores[tamano][0] = n;
        factores[tamano][1] = 1;
        nuevo_tamano++;
    }
    
    return nuevo_tamano;
}

int Factorizar(int n, int factores[][2]){
    int tamano = 0;
    bool anadido = false;
    
    //me quito primero el 2 para luego probar solo los impares
    while (n % 2 == 0){
        n = n/2;
        tamano = IncrementarFactor(2, factores, tamano);
    }
    
    while (n != 1){
        anadido = false;
        for (int i = 3; i <= n && !anadido; i += 2){
            if (n % i == 0){
                n = n/i;
                tamano = IncrementarFactor(i, factores, tamano);
                anadido = true;
            }
        }
    }
    
    return tamano;
}

int SumaDivisores(int n){
    //http://teoriadenumeros.wikidot.com/suma-de-divisores
    int suma_divisores = 1;
    int tamano;
    int factores[TAMANO_MAX][2];
    
    tamano = Factorizar(n, factores);
    
    for (int i = 0; i < tamano; i++){
        suma_divisores *= ( (pow(factores[i][0], factores[i][1] + 1) - 1) / (factores[i][0] - 1) );
        //cout << suma_divisores << endl;
    }
    suma_divisores -= n;
    
    return suma_divisores;
}

bool Amigos(int n1, int n2){
    int suma1 = SumaDivisores(n1);
    int suma2 = SumaDivisores(n2);
    bool resultado = (suma1 == n2 && suma2 == n1);
    return resultado;
}


int main(){
    const double MAX_RELACION = 284.0 / 220.0;
    int extremo_inferior, extremo_superior;
    
    cin >> extremo_inferior >> extremo_superior;
    
    
    for (int i = extremo_inferior; i <= extremo_superior; i++){
        for (int j = i + 1; j <= i*MAX_RELACION && j <= extremo_superior; j++){
            if (Amigos(i, j)){
                cout << i << " " << j << endl;
            }
        }
    }
    
    

    /*for (int i = extremo_inferior; i <= extremo_superior; i++){
        cout << "SUma de divisores de " << i << ": " << SumaDivisores(i) << endl;
        
    }*/
    
    
    return 0;
}
