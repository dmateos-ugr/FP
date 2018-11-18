#include <iostream>

using namespace std;

int MCD(int a, int b){
    //Calcula el MCD de a y b mediante el algoritmo de Euclides.
    int resto;

    if (b > a){
        //intercambio a por b
        a = a + b;
        b = a - b;
        a = a - b;
    }
    while (b > 0){
        resto = a%b;
        a = b;
        b = resto;
    }
    
    return a;
}


int main(){
    int n1, n2;
    int mcd;
    
    cout << "Introduce dos números: ";
    cin >> n1 >> n2;
    
    mcd = MCD(n1, n2);
    
    cout << "Su máximo común divisor es " << mcd << endl;
    
    return 0;
}
