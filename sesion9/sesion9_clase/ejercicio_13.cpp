#include <iostream>

using namespace std;

int Inverso(int n){
    int resultado = 0;
        
    while (n > 0){
        resultado = resultado* 10;
        resultado += (n % 10);
        n = n / 10;
    }
    
    return resultado;
}

int main(){
    int n;
    
    cin >> n;
    cout << Inverso(n);
    
    return 0;
}
