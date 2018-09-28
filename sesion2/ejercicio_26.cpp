#include <iostream>
using namespace std;

int main(){
    double distancia, velocidad1, velocidad2;
    double tiempo, distancia_choque1, distancia_choque2;
    
    cout << "Introduzca la distancia entre ambas locomotoras: ";
    cin >> distancia;
    cout << "Introduzca la velocidad de cada locomotora: ";
    cin >> velocidad1 >> velocidad2;
    
    tiempo = distancia / (velocidad1 + velocidad2);
    distancia_choque1 = velocidad1*tiempo;
    distancia_choque2 = distancia-distancia_choque1;
    
    cout << "El choque se produciría a una distancia de " << distancia_choque1 << " de la primera locomotora, y a " <<  distancia_choque2 << " de la segunda locomotora." << endl;
    
    return 0;
}
