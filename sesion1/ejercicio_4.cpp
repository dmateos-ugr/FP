#include <iostream>
#include <cmath>

using namespace std;

int main(){
    cout << "Bienvenido." << endl;

    double mean;
    double standard_deviation;
    double x;
    double result;

    cout << "Introduzca el valor de esperanza o media: ";
    cin >> mean;
    cout << "Introduzca el valor de desviación típica: ";
    cin >> standard_deviation;
    cout << "Introduzca el valor de abscisa x para el que calcular la función Gaussiana: ";
    cin >> x;

    result = exp(-0.5*pow((x-mean)/standard_deviation, 2))/(standard_deviation*sqrt(2*M_PI));

    cout << "El resultado es: " << result << endl;


}
