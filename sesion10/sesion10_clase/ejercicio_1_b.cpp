#include <iostream>

using namespace std;

class Recta{
    public:
        double a, b, c;
    
};

int main(){
    Recta recta1, recta2;
    double pendiente1, pendiente2;
    
    cout << "Introduzca los coeficientes de la recta 1: ";
    cin >> recta1.a >> recta1.b >> recta1.c;
    cout << "Introduzca los coeficientes de la recta 2: ";
    cin >> recta2.a >> recta2.b >> recta2.c;
    
    pendiente1 = -recta1.a / recta1.b;
    pendiente2 = -recta2.a / recta2.b;
    
    cout << "La pendiente de la recta 1 es: " << pendiente1 << endl;
    cout << "La pendiente de la recta 2 es: " << pendiente2 << endl;
    
    return 0;
}
