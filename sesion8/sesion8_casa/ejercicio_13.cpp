#include <iostream>

using namespace std;

const int TAMANO_MAX = 100;

struct Matriz{
	int elementos[TAMANO_MAX][TAMANO_MAX];
	int filas;
	int columnas;
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

bool SonIguales(Matriz matriz1, Matriz matriz2){
	bool resultado = true;
	
	if (matriz1.filas != matriz2.filas || matriz1.columnas != matriz2.columnas){
		resultado = false;
	}
	
	for (int f = 0; f < matriz1.filas && resultado; f++){
		for (int c = 0; c < matriz2.columnas && resultado; c++){
			if (matriz1.elementos[f][c] != matriz2.elementos[f][c]){
				resultado = false;
			}
		}
	}
	return resultado;
}

int main(){
	Matriz matriz1 = PedirMatriz("1");
	Matriz matriz2 = PedirMatriz("2");
	bool iguales = SonIguales(matriz1, matriz2);
	
	cout << "Las matrices son iguales: " << (igualesW ? "sí." : "no") << endl;
	
	return 0;
}
