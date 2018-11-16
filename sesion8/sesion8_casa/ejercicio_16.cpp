#include <iostream>

using namespace std;

const int TAMANO_MAX = 100;


int PedirMatrizSimetrica(int m[][TAMANO_MAX]){
    int tamano;
    
    cout << "Introduzca el número de filas y columnas para una matriz simétrica: ";
    cin >> tamano;
    cout << "Introduzca sus elementos:\n";
    for (int i = 0; i < tamano; i++){
        for (int j = 0; j < tamano; j++){
            cin >> m[i][j];
        }
    }
    return tamano;
}

int VectorDeMatrizSimetrica(const int m[][TAMANO_MAX], int tamano, int vector[]){
    int col_max = 1;
    int pos_vector = 0;
    
    for (int f = 0; f < tamano; f++){
        for (int c = 0; c < col_max; c++){
            vector[pos_vector] = m[f][c];
            pos_vector++;
        }
        col_max++;
    }
    
    return pos_vector;
}

void ImprimirVector(const int v[], int tamano){
    cout << "Los elementos del vector resultante a partir de la matriz simétrica son:\n";
    for (int i = 0; i < tamano; i++){
        cout << v[i] << " ";
    }
    cout << endl << endl;
}

int PedirVector(int v[]){
    int tamano;
    cout << "Introduce el tamaño del vector: ";
    cin >> tamano;
    cout << "Introduce los elementos: ";
    for (int i = 0; i < tamano; i++){
        cin >> v[i];
    }
    cout << endl;
    return tamano;
}

int MatrizSimetricaDeVector(const int vector[], int tamano, int matriz[][TAMANO_MAX]){
    //Calcula la matriz simétrica generada a partir del vector, y la va guardando en matriz.
    //Devuelve el tamaño de la matriz.
    
    int tamano_fila_parte_inferior = 0;
    int i_vector = 0;
    
    /*
    00 01 02 03      |\   00 10 20 30
    10 11 12 13 -----  \  10 11 21 31
    20 21 22 23 -----  /  20 21 22 32
    30 31 32 33      |/   30 31 32 33
    
    v = 00 10 11 20 21 22 30 31 32 33
    
    */
    
    //En cada iteración pone primero los elementos inferiores y superiores, y después el de la diagonal.
    while (i_vector < tamano){
        for (int i = 0; i < tamano_fila_parte_inferior; i++){ 
            matriz[tamano_fila_parte_inferior][i] = vector[i_vector];
            matriz[i][tamano_fila_parte_inferior] = vector[i_vector];
            i_vector++;
        }
        matriz[tamano_fila_parte_inferior][tamano_fila_parte_inferior] = vector[i_vector];
        i_vector++;
        tamano_fila_parte_inferior++;
    }
    
    return tamano_fila_parte_inferior;
}

void ImprimirMatrizSimetrica(const int m[][TAMANO_MAX], int tamano){
    cout << "La matriz simétrica resultante a partir del vector dado es:\n";
    for (int i = 0; i < tamano; i++){
        for (int j = 0; j < tamano; j++){
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    //Primera parte: vector a partir de matriz
    int matriz[TAMANO_MAX][TAMANO_MAX];
    int vector[TAMANO_MAX];
    int tamano_matriz, tamano_vector;
    
    tamano_matriz = PedirMatrizSimetrica(matriz);
    tamano_vector = VectorDeMatrizSimetrica(matriz, tamano_matriz, vector);
    ImprimirVector(vector, tamano_vector);
    
    
    //Segunda parte: matriz a partir de vector
    cout << "A continuación introducirá un vector con los elementos de la diagonal principal y los que están por debajo de ella de una matriz." << endl;
    tamano_vector = PedirVector(vector);
    tamano_matriz = MatrizSimetricaDeVector(vector, tamano_vector, matriz);
    ImprimirMatrizSimetrica(matriz, tamano_matriz);
    
    
    /*
    for (int i = 0; i < tamano; i++){
        for (int j = 0; j < tamano; j++){
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }*/

    
    
    return 0;
}
