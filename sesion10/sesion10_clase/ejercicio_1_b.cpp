#include <iostream>

using namespace std;

class Recta{
    public:
        double a, b, c;
        
        double Pendiente();
        
        double ObtenerY(double x);
        
        double ObtenerX(double y);
};

int main(){
    Recta recta1, recta2;
    double pendiente1, pendiente2;
    
    cout << "Introduzca los coeficientes de la recta 1: ";
    cin >> recta1.a >> recta1.b >> recta1.c;
    cout << "Introduzca los coeficientes de la recta 2: ";
    cin >> recta2.a >> recta2.b >> recta2.c;
    
    pendiente1 = recta1.Pendiente();
    pendiente2 = recta2.Pendiente();
    
    cout << "La pendiente de la recta 1 es: " << pendiente1 << endl;
    cout << "La pendiente de la recta 2 es: " << pendiente2 << endl;
    
    int x, y, x_result, y_result;
    
    cout << "Introduce un valor de abscisa: ";
    cin >> x;
    cout << "Introduce un valor de ordenada: ";
    cin >> y;
    
    y_result = recta1.ObtenerY(x);
    x_result = recta1.ObtenerX(y);
    
    cout << "El valor de ordenada correspondiente a la abscisa " << x << " en la recta 1 es: " << y_result << endl;
    cout << "El valor de abscisa correspondiente a la ordenada " << y << " en la recta 1 es: " << x_result << endl;
    
    return 0;
}


double Recta::Pendiente(){
    return -a/b;
}

double Recta::ObtenerY(double x){
    return (-c - x*a)/b;
}

double Recta::ObtenerX(double y){
    return (-c - y*a)/b;
}
