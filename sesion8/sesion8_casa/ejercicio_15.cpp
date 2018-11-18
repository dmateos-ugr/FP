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

Matriz Traspuesta(Matriz matriz){
    Matriz resultado;
    resultado.columnas = matriz.filas;
    resultado.filas = matriz.columnas;
    
    for (int f = 0; f < matriz.filas; f++){
        for (int c = 0; c < matriz.columnas; c++){
            resultado.elementos[c][f] = matriz.elementos[f][c];
        }
    }
    
    return resultado;
}

void ImprimirMatriz(Matriz matriz, const char nombre[]){
    cout << "La matriz " << nombre << " es:" << endl;
    for (int i = 0; i < matriz.filas; i++){
        for (int j = 0; j < matriz.columnas; j++){
            cout << matriz.elementos[i][j] << " ";
        }
        cout << endl;
    }
}

void CalcularPosicion(Matriz matriz, int pos_maximo_minimo[2]){
    //Calcula la posición del máximo elemento entre los mínimos de los elementos de cada fila,
    //y la introduce en pos_maximo_minimo.
    //Calcula las posiciones de los minimos de cada fila, y luego la posicion del maximo de estos minimos.
    int pos_minimos[TAMANO_MAX][2];
    int pos_minimo[2];
    int tamano = 0;
    
    for (int f = 0; f < matriz.filas; f++){
        pos_minimo[0] = f;
        pos_minimo[1] = 0;
        for (int c = 1; c < matriz.columnas; c++){
            if (matriz.elementos[f][c] < matriz.elementos[pos_minimo[0]][pos_minimo[1]]){
                pos_minimo[0] = f;
                pos_minimo[1] = c;
            }
        }
        pos_minimos[tamano][0] = pos_minimo[0];
        pos_minimos[tamano][1] = pos_minimo[1];
        tamano++;
    }
    
    pos_maximo_minimo[0] = pos_minimos[0][0];
    pos_maximo_minimo[1] = pos_minimos[0][1];
    for (int i = 1; i < tamano; i++){
        if (matriz.elementos[pos_minimos[i][0]][pos_minimos[i][1]] > matriz.elementos[pos_maximo_minimo[0]][pos_maximo_minimo[1]]){
            pos_maximo_minimo[0] = pos_minimos[i][0];
            pos_maximo_minimo[1] = pos_minimos[i][1];
        }
    }
}


bool MaxiMin(Matriz matriz, int & maximin){
    bool resultado = false;
    int maximo;
    int columna_maximo = 0;
    bool es_maximin = true;
    
    for (int f = 0; f < matriz.filas && !resultado; f++){
        maximo = matriz.elementos[f][0];
        for (int c = 1; c < matriz.columnas; c++){
            if (matriz.elementos[f][c] > maximo){
                maximo = matriz.elementos[f][c];
                columna_maximo = c;
            }
        }
        
        for (int f = 0; f < matriz.filas && es_maximin; f++){
            if (maximo > matriz.elementos[f][columna_maximo]){
                es_maximin = false;
            }
        }
        
        if (es_maximin){
            resultado = true;
            maximin = maximo;
        }
        
    }
    
    return resultado;
}

Matriz MultiplicarMatrices(Matriz m1, Matriz m2){
    Matriz resultado = {0, 0, {{0}}};
    
    if (m1.columnas == m2.filas){
        resultado.filas = m1.filas;
        resultado.columnas = m2.columnas;
        
        for (int f = 0; f < resultado.filas; f++){
            for (int c = 0; c < resultado.columnas; c++){
                for (int c2 = 0; c2 < m2.columnas; c2++){
                    resultado.elementos[f][c] += m1.elementos[f][c2] * m2.elementos[c2][c];
                }
            }
        }
        /*
        (00 01 02)   (00' 01')     (00 = 00*00' + 01*10' + 02*20' | 01 = 00*01' + 01*11' + 02*21')
        (10 11 12) x (10' 11')  =  (10 = 10*00' + 11*10' + 12*20' | 11 = 10*01' + 11*11' + 12*21')
                     (20' 21')     
        m[f][c] = m1[f][k]*m2[k][c]
        */
    }
    
    return resultado;
}

int main(){
    Matriz matriz, traspuesta, matriz2, multiplicacion;
    int posicion[2];
    int maximin;
    
    matriz = PedirMatriz();
    matriz2 = PedirMatriz();
    
    traspuesta = Traspuesta(matriz);
    CalcularPosicion(matriz, posicion);
    
    cout << endl;
    ImprimirMatriz(traspuesta, "traspuesta");
    cout << endl;
    cout << "La posición del mayor elemento entre los mínimos de cada fila es: " << posicion[0] << ", " << posicion[1] << endl;
    
    if (MaxiMin(matriz, maximin)){
        cout << "Hay un elemento máximo de su fila y mínimo de su columna: " << maximin << endl;
    } else {
        cout << "No hay ningún elemento que sea máximo de su fila y mínimo de su columna." << endl;
    }
    
    multiplicacion = MultiplicarMatrices(matriz, matriz2);
    if (multiplicacion.filas == 0){
        cout << "La multiplicación entre las dos matrices no es posible." << endl;
    } else {
        ImprimirMatriz(multiplicacion, "multiplicación");
    }
    
    return 0;
}
