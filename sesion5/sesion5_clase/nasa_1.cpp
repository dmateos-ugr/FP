#include <iostream>
#include <string>

using namespace std;

int main(){
    const string msg = "Introduce un número (0 o 1): ";
    int ceros_seguidos = 0;
    int unos_seguidos = 0;
    int n_introducido;
    int n_calculado = 1;
    bool entrada_valida;

    while (ceros_seguidos < 5){
        do {
        cout << msg;
        cin >> n_introducido;
        entrada_valida = (n_introducido != 0 && n_introducido != 1);
        } while (entrada_valida);

        if (n_introducido == 0){
            ceros_seguidos++;
            if (unos_seguidos != 0){
                n_calculado *= unos_seguidos;
            }            
            unos_seguidos = 0;
            
        } else {
            unos_seguidos++;
            ceros_seguidos = 0;
        }
    }
    
    cout << "Número introducido: " << n_calculado << endl;
    
    return 0;
}
