#include <iostream>
#include "base.cpp"

void rotar(Imagen& Img){
	Imagen Imgrotada;
	int aux;
	for(int c = 0; c < Img.filas; c++){
		for(int f = 0; f < Img.columnas; f++){
			Imgrotada.matrix_pixeles[f][c] = Img.matrix_pixeles[c][Img.columnas - f];
		}
	}	
	
	for(int i = 0; i < Img.columnas; i++){
		for(int j = 0; j < Img.filas; j++){
			Img.matrix_pixeles[i][j] = Imgrotada.matrix_pixeles[i][j];
		}
	}
	
	aux = Img.filas;
   	Img.filas = Img.columnas;
	Img.columnas = aux;
	
}

using namespace std;

int main(){
	Imagen Img;
	PedirImagen(Img);
	rotar(Img);
	ImprimirImagen(Img);
}
