#include <iostream>
#include <cmath>

using namespace std;

int main(){
    double lado1, lado2;
    double angulo;
    double area;
    
    cout << "Introduzca la longitud de cada lado en centímetros: ";
    cin >> lado1 >> lado2;
    cout << "Introduzca el valor del ángulo que forman estos dos lados en grados: ";
    cin >> angulo;
    
    angulo = angulo * 2 * M_PI  / 360;
    area = lado1 * lado2 * sin(angulo) / 2;
    
    cout << "El área del triángulo formado por los datos introducidos es: " << area << endl;
    return 0;
}
