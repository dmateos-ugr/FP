#include <iostream>

using namespace std;

int main(){
    int dato_introducido, numero_contando, veces = 0;
    
    cin >> dato_introducido;
    numero_contando = dato_introducido;
    
    while (dato_introducido != -1){
        do {
            veces++;
            cin >> dato_introducido;
        } while (dato_introducido == numero_contando);
        
        cout << veces << " " << numero_contando << " ";
        
        numero_contando = dato_introducido;
        veces = 0;
    }
    
    cout << endl;

    return 0;
}
