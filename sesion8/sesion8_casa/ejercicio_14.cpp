#include <iostream>

using namespace std;

const int TAMANO_MAX = 100;

struct Matriz{
	int filas;
	int columnas;
	int elementos[TAMANO_MAX][TAMANO_MAX];
};

Matriz PedirMatriz(){
	Matriz matriz;
	cout << "Introduce el número de las filas de la matriz: ";
	cin >> matriz.filas;
	cout << "Introduce el número de las columnas de la matriz: ";
	cin >> matriz.columnas;
	cout << "Introduce los elementos de la matriz:\n";
	for (int f = 0; f < matriz.filas; f++){
		for (int c = 0; c < matriz.columnas; c++){
			cin >> matriz.elementos[f][c];
		}
	}
	return matriz;
}

int SumaFilas(Matriz matriz, int vector[]){
	int tamano = 0;
	int suma = 0;
	for (int f = 0; f < matriz.filas; f++){
		suma = 0;
		for (int c = 0; c < matriz.columnas; c++){
			suma += matriz.elementos[f][c];
		}
		vector[tamano] = suma;
		tamano++;
	}
	return tamano;
}

int SumaColumnas(Matriz matriz, int vector[]){
    int tamano = 0;
    int suma = 0;
    for (int c = 0; c < matriz.columnas; c++){
        suma = 0;
        for (int f = 0; f < matriz.filas; f++){
            suma += matriz.elementos[f][c];
        }
        vector[tamano] = suma;
        tamano++;
    }
    return tamano;
}

void ImprimirVector(int vector[], int tamano){
	for (int i = 0; i < tamano; i++){
		cout << vector[i] << " ";
	}
	cout << endl;	
}

int main(){
	Matriz matriz;
	int vector_filas[TAMANO_MAX], vector_columnas[TAMANO_MAX];
    int tamano_filas, tamano_columnas;
    
    matriz = PedirMatriz();
	tamano_filas = SumaFilas(matriz, vector_filas);
    tamano_columnas = SumaColumnas(matriz, vector_columnas);
	
	cout << "El vector resultante de la suma de cada fila es: ";
	ImprimirVector(vector_filas, tamano_filas);
    cout << "El vector resultante de la suma de cada columna es: ";
    ImprimirVector(vector_columnas, tamano_columnas);
    
	return 0;
}
