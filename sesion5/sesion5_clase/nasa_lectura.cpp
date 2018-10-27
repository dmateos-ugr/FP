#include <iostream>

using namespace std;

int main(){
    const int TERMINADOR = -1;
    int ceros_seguidos = 0;
    int unos_seguidos = 0;
    int n_introducido;

    while (ceros_seguidos < 5){
        do {
        cin >> n_introducido;
        } while (n_introducido != 0 && n_introducido != 1);

        if (n_introducido == 0){
            ceros_seguidos++;
            if (unos_seguidos != 0){
                cout << unos_seguidos << endl;
            }            
            unos_seguidos = 0;
            
        } else {
            unos_seguidos++;
            ceros_seguidos = 0;
        }
    }
    cout << TERMINADOR;
}
