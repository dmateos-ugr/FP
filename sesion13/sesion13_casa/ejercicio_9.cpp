#include <iostream>

using namespace std;

int divisoresMenores(int n, int k){
    if (k > 1 && k <= n){
        if (n%(k-1) == 0){
            return 1 + divisoresMenores(n, k-1);
        } else {
            return divisoresMenores(n, k-1);
        }
    } else if (k <= 1){
        return 0;
    } else { // caso en el que k > n
        return divisoresMenores(n, n);
    }
}


int main(){
    int n1, n2;
    int divisores;
    
    cout << "Introduzca dos números: ";
    cin >> n1 >> n2;
    
    divisores = divisoresMenores(n1, n2);
    
    cout << "Hay un total de " << divisores << " divisores propios de " << n1 << " menores de " << n2 << "." << endl;
    
    return 0;
}
