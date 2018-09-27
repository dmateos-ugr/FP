#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double altura1, altura2, altura3;
    double media, desviacion;
    cout << "Introduce la altura de la persona 1: ";
    cin >> altura1;
    cout << "Introduce la altura de la persona 2: ";
    cin >> altura2;
    cout << "Introduce la altura de la persona 3: ";
    cin >> altura3;

    media = (altura1 + altura2 + altura3) / 3;
    desviacion = sqrt((pow(altura1 - media, 2) + pow(altura2 - media, 2) + pow(altura3 - media, 2))/3);
    
    cout << "La media aritmética de las alturas introducidad es " << media << endl;
    cout << "La desviación típica de las alturas introducidas es " << desviacion << endl;
    
    return 0;
}
