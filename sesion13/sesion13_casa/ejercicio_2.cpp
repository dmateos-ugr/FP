#include <iostream>

using namespace std;


int MCD(int a, int b){
    int result;
    
    if (b == 0){
        result = a;
    } else {
        result = MCD(b, a%b);
    }
    
    return result;
}

//Una sola línea usando el operador ternario
/*
int MCD(int a, int b){
    return (b ? MCD(b, a%b) : a);
}
*/


int main(){
    int n1, n2;
    int mcd;
    
    cout << "Introduzca dos números: ";
    cin >> n1 >> n2;
    
    mcd = MCD(n1, n2);
    
    cout << "Su MCD es: " << mcd << endl;
    
    
    return 0;
}
