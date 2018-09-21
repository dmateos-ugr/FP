#include <iostream>
using namespace std;

int main(){
    const double PI = 3.1415927;
    double radio;
    double area;
    double longitud;
    
    cout << "Introduzca el valor del radio: ";
    cin >> radio;
    
    area = PI * radio * radio;
    longitud = 2 * PI * radio;

    cout << "El area de un círculo de radio " << radio << " es de " << area << " , y su longitud es de " << longitud << endl;

}
