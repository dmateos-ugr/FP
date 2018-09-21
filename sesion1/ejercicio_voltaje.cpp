#include <iostream>
using namespace std;

int main(){
    double intensidad;
    double resistencia;
    double voltaje;
    
    cout << "Introduzca el valor de la intensidad: ";
    cin >> intensidad;
    cout << "Introduzca el valor de la resistencia: ";
    cin >> resistencia;
    
    voltaje = resistencia*intensidad;
    
    cout << "El valor del voltaje resultante es " << voltaje << endl;
    return 0;

}
