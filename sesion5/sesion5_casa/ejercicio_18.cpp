#include <iostream>

using namespace std;

int main(){
    double x, potencia;
    int n, factorial;
    
    
    cout << "Introduzca un número real: ";
    cin >> x;
    cout << "Introduzca un número entero: ";
    cin >> n;
    
    //Cálculos potencia
    potencia = 1;
    for (int i=0; i < n; i++){
        potencia = potencia * x;
    }
    
    //Cálculos factorial
    factorial = 1;
    for (int i=1; i <= n; i++){
        factorial = factorial * i;
    } 

    //Salidas
    cout << "La potencia " << x << " elevado a " << n << " da un total de: " << potencia << endl;
    cout << "El factorial de " << n << " da un total de: " << factorial << endl;

    return 0;
}
