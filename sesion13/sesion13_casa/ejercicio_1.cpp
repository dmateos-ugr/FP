#include <iostream>

using namespace std;

int SumaDigitos(int n){
    int result;
    if (n / 10 == 0){
        result = n;
    } else {
        result = n % 10 + SumaDigitos(n / 10);
    }
    return result;
}

//Una sola línea usando el operador ternario
/*
int SumaDigitos(int n){
    return (n/10 ? ( n%10 + SumaDigitos(n/10) ) : n);
}
*/

int main(){
    int n, suma;
    
    cout << "Introduzca un número: ";
    cin >> n;
    
    suma = SumaDigitos(n);
    
    cout << "La suma de sus dígitos es: " << suma << endl;
    
    return 0;
}
