#include <iostream>

using namespace std;

int main(){
    int n_introducido, n_calculado = 1;
    
    cin >> n_introducido;
    while (n_introducido != -1){
        n_calculado *= n_introducido;
        cin >> n_introducido;
    }
    cout << "El número resultante es " << n_calculado << endl;
    return 0;
}
