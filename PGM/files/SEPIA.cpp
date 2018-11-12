#include<iostream>
#include "base.cpp"
using namespace std;

void SEPIA(Imagen & img){        //módulo que pasa la imagen a negativo.
	for(int i=0; i < img.filas; i++ ){
		for(int j=0; j < img.columnas; j++ ){
			img.matrix_pixeles[i][j] = 255 - img.matrix_pixeles[i][j];
		}
	}
}

int main(){
	
	Imagen img;
	
	PedirImagen(img);
	
	SEPIA(img);
	
	ImprimirImagen(img);
	
	return 0;
}
