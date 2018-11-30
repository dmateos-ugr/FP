#include <iostream>

using namespace std;

class Recta{
    private:
        double a, b, c;
    
    public:
        void SetA(double v);
        
        void SetB(double v);
        
        void SetC(double v);
        
        double GetA();
        
        double GetB();
        
        double GetC();
        
        double Pendiente();
        
        double ObtenerY(double x);
        
        double ObtenerX(double y);
};

int main(){
    Recta recta1, recta2;
    double pendiente1, pendiente2;
    double a, b, c;
    
    cout << "Introduzca los coeficientes de la recta 1: ";
    cin >> a >> b >> c;
    recta1.SetA(a);
    recta1.SetB(b);
    recta1.SetC(c);
        
    cout << "Introduzca los coeficientes de la recta 2: ";
    cin >> a >> b >> c;
    recta2.SetA(a);
    recta2.SetB(b);
    recta2.SetC(c);
    
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

void Recta::SetA(double v){
    a = v;
}

void Recta::SetB(double v){
    b = v;
}

void Recta::SetC(double v){
    c = v;
}

double Recta::GetA(){
    return a;
}

double Recta::GetB(){
    return b;
}

double Recta::GetC(){
    return c;
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
