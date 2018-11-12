#include <iostream>

using namespace std;

const int MAX_TAM = 650;

struct Imagen{
    int filas;
    int columnas;
    int matrix_pixeles[MAX_TAM][MAX_TAM];
};

void PedirImagen(Imagen& imagen_salida){
    char header[2];
    int max_color;

    cin >> header;
    cin >> imagen_salida.columnas >> imagen_salida.filas;
    cin >> max_color;

    //cout << "el tamano es " << imagen_salida.columnas << " " << imagen_salida.filas << endl;;

    for (int f = 0; f < imagen_salida.filas; f++){
        for (int c = 0; c < imagen_salida.columnas; c++){
            cin >> imagen_salida.matrix_pixeles[f][c];
        }
    }    
}

void ImprimirImagen(Imagen img){
    cout << "P2" << endl << img.columnas << " " << img.filas << endl << "255" << endl;
    for (int f = 0; f < img.filas; f++){
        for (int c = 0; c < img.columnas; c++){
            cout << img.matrix_pixeles[f][c] << " ";
        }
        cout << endl;
    }
}
