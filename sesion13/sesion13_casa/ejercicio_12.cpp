#include <iostream>
#include <cmath>

using namespace std;

const double EPS = 0.00001;

double f(double x){
    //return x*x + 2*x - 3;
    return x*x*x - 5*x*x + 2*x - 8;
    //return x*x - 4;
}

double absoluto(double n){
    return (n>0 ? n : -n);
}

double raiz(double i, double d){
    double m = (i+d)/2.0;
        
    if ( absoluto(i - d) < EPS){
        return m;
    } else if (f(m) * f(i) > 0) {
        return raiz(m, d);
    } else if (f(m) * f(d) > 0) {
        return raiz(i, m);
    } else { 
        //Este caso se dará solamente cuando f(m) = 0,
        //con lo cual habremos encontrado la solución.
        return m;
    }
}


int main(){
    double a, b;
    double r;
    
    cout << "A continuación se hallará una raíz del polinomio x^3 - 5x^2 + 2x - 8." << endl;
    cout << "Introduzca dos puntos en los que el polinomio tome valores con diferentes signos: ";
    
    cin >> a >> b;
    
    if (f(a) * f(b) >= 0){
        cout << "La función no toma valores con diferentes signos en los puntos introducidos." << endl;
    } else {
        r = raiz(a, b);
    
        cout << "Una raíz es el punto x = " << r << endl;
    }
    return 0;
}
