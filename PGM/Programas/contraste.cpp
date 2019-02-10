/*contraste.exe Cambia los colores menores de 125 a 0 y los mayores o iguales a 255*/
#include <iostream>
#include "base.cpp"
using namespace std;

void Contraste(Imagen & img){
    for (int f=0;f<img.filas;f++){
        for (int c=0;c<img.columnas;c++){	
            if (img.matrix_pixeles[f][c] < 125){
                img.matrix_pixeles[f][c]=0;
            }
            else{
                img.matrix_pixeles[f][c]=255;
            }
        }
    }
}
	
int main(){
	Imagen img;
	
	PedirImagen(img);
	Contraste(img);
	ImprimirImagen(img);
}
