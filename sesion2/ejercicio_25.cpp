#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double x, y, h;
    double a, b, c;
    
    cout << "Introduce el valor x: ";
    cin >> x;
    cout << "Introduce el valor y: ";
    cin >> y;
    cout << "Introduce el valor h: ";
    cin >> h;
    
    a = (1 + pow(x, 2)/y) / (pow(x, 3)/(1 + y));
    b = (1 + sin(h)/3  - cos(h)/7)/(2*h);
    c = sqrt(1 + pow(exp(x)/pow(x, 2), 2));
    
    cout << "El valor de la operación a es " << a << endl;
    cout << "El valor de la operación b es " << b << endl;
    cout << "El valor de la operación c es " << c << endl;
    
    return 0;
}
