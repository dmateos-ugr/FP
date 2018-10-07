#include <iostream>
#include <string>

using namespace std;

struct TipoPunto{
    double abscisa;
    double ordenada;
};

struct TipoCiudad{
    TipoPunto situacion;
    string nombre;
};

int main(){
    TipoPunto loc_ciudad1, loc_ciudad2, loc_ciudad3;
    TipoCiudad ciudad1, ciudad2, ciudad3;
    ciudad1.situacion = loc_ciudad1;
    ciudad2.situacion = loc_ciudad2;
    ciudad3.situacion = loc_ciudad3;

    cout << "Introduzca el nombre de la primera ciudad: ";
    cin >> ciudad1.nombre;
    cout << "Introduzca sus coordenadas (abscisa y ordenada, en ese orden): ";
    cin >> ciudad1.situacion.abscisa >> ciudad1.situacion.ordenada;
    cout << "Introduzca el nombre de la segunda ciudad: ";
    cin >> ciudad2.nombre;
    cout << "Introduzca sus coordenadas (abscisa y ordenada, en ese orden): ";
    cin >> ciudad2.situacion.abscisa >> ciudad2.situacion.ordenada;
    
    //Es mejor asi? o definir aqui directamente ciudad3?
    ciudad3.nombre = ciudad1.nombre + ciudad2.nombre;
    ciudad3.situacion.abscisa = ciudad1.situacion.abscisa * ciudad2.situacion.abscisa;
    ciudad3.situacion.ordenada = ciudad1.situacion.ordenada * ciudad2.situacion.ordenada;

    cout << "La ciudad resultante tiene de nombre " << ciudad3.nombre << " y su situación es " << ciudad3.situacion.abscisa << ", " << ciudad3.situacion.ordenada << endl;

    return 0;
}
