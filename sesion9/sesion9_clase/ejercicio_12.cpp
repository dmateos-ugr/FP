#include <iostream>

using namespace std;

int MCD(int n1, int n2){
    int resto;
    while (n2 != 0){
        resto = n1 % n2;
        n1 = n2;
        n2 = resto;
    }
    return n1;
}

int MCM(int n1, int n2){
    return (n1*n2)/MCD(n1, n2);
}

int Calculadora(int n1, int n2, char op){
    int result;
    
    switch (op){
        case 'm':
            //result = MCM(n1, n2);
            break;
        case 'd':
            result = MCD(n1, n2);
            break;
        case '+':
            result = n1 + n2;
            break;
        case '*':
            result = n1 * n2;
            break;
        case '-':
            result = n1 - n2;
            break;
        case '/':
            result = n1 / n2;
            break;
            
    }
    
    return result;
}


int main(){
    int n1, n2, resultado;
    char op;
    
    cout << "Introduzca dos números enteros positivos: ";
    cin >> n1 >> n2;
    cout << "Introduzca el carácter de la operación: ";
    cin >> op;
    
    resultado = Calculadora(n1, n2, op);
    
    cout << "El resultado es: " << resultado << endl;
    
    return 0;
}
