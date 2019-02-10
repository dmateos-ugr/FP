#include <iostream>
#include "base.cpp"

using namespace std;

void BlanquearImagen(Imagen & img){
    for (int f = 0; f < img.filas; f++){
        for (int c = 0; c < img.columnas; c++){
            img.matrix_pixeles[f][c] = 255;
        }
    }
}

int main(){
    Imagen img;

    PedirImagen(img);

    BlanquearImagen(img);

    ImprimirImagen(img);

    return 0;
}
