#include <iostream>

using namespace std;

class Recta{
    private:
        double a, b, c;
    
    public:
        void SetA(double v){
            a = v;
        }
        
        void SetB(double v){
            b = v;
        }
        
        void SetC(double v){
            c = v;
        }
        
        double GetA(){
            return a;
        }
        
        double GetB(){
            return b;
        }
        
        double GetC(){
            return c;
        }
        
        double Pendiente(){
            return -a/b;
        }
        
        double ObtenerY(double x){
            return (-c - x*a)/b;
        }
        
        double ObtenerX(double y){
            return (-c - y*a)/b;
        }
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
