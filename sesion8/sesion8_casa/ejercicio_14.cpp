#include <iostream>

using namespace std;

const int TAMANO_MAX = 100;

struct Matriz{
	int filas;
	int columnas;
	int elementos[TAMANO_MAX][TAMANO_MAX];
};

Matriz PedirMatriz(const char nombre[]){
	Matriz matriz;
	cout << "Introduce el número de las filas de la matriz " << nombre << ": ";
	cin >> matriz.filas;
	cout << "Introduce el número de las columnas de la matriz " << nombre << ": ";
	cin >> matriz.columnas;
	cout << "Introduce los elementos de la matriz " << nombre << ":\n";
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

void ImprimirVector(int vector[], int tamano){
	for (int i = 0; i < tamano; i++){
		cout << vector[i] << " ";
	}
	cout << endl;	
}

int main(){
	Matriz matriz = PedirMatriz("inicial");
	int vector[TAMANO_MAX];
	int tamano = SumaFilas(matriz, vector);
	
	cout << "La suma de cada fila es: ";
	ImprimirVector(vector, tamano);
	return 0;
}
