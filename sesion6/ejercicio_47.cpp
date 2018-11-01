#include <iostream>

using namespace std;

int main(){
    int multiplicando, multiplicador;
    int resultado = 0;
    bool es_impar;
    
    cout << "Introduce un número: ";
    cin >> multiplicando;
    cout << "Introduce un número: ";
    cin >> multiplicador;
    
    while (multiplicando >= 1){
        es_impar = multiplicando % 2 == 1;
        if (es_impar){
            resultado += multiplicador;
        }
        
        multiplicando = multiplicando/2;
        multiplicador = multiplicador*2;
    }
    
    cout << "El resultado del producto es " << resultado << endl;
    
    return 0;
}
