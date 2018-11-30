#include <iostream>

using namespace std;

class Recta{
    private:
        double a, b, c;
        
        bool DatosCorrectos(double n1, double n2);
        
    public:
        Recta(double n1, double n2, double n3);
        
        double SetCoeficientes(double n1, double n2, double n3);
        
        double GetA();
        
        double GetB();
        
        double GetC();
        
        double Pendiente();
        
        double ObtenerY(double x);
        
        double ObtenerX(double y);
};

int main(){
    double pendiente1, pendiente2;
    double a, b, c;
    
    cout << "Introduzca los coeficientes de la recta 1: ";
    cin >> a >> b >> c;
    Recta recta1(a, b, c);
        
    cout << "Introduzca los coeficientes de la recta 2: ";
    cin >> a >> b >> c;
    Recta recta2(a, b, c);
    
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

Recta::Recta(double n1, double n2, double n3){
    SetCoeficientes(n1, n2, n3);
}

bool Recta::DatosCorrectos(double n1, double n2){
    return !(n1 == 0 && n2 == 0);
}

double Recta::SetCoeficientes(double n1, double n2, double n3){
    if (DatosCorrectos(n1, n2)){
        a = n1;
        b = n2;
        c = n3;
    } else {
        a = 0;
        b = 1;
        c = 0;
        cout << "Coeficientes incorrectos. La recta se ha establecido como el eje x." << endl;
    }
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
