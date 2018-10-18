#include <iostream>

using namespace std;

int main(){
    const int TERMINADOR = 0;
    int dato;
    int minimo = 0;
    int n_datos = 0;

    cout << "Introduce un número: ";
    cin >> dato;
    minimo = dato;

    while (dato != TERMINADOR){
        if (dato < minimo){
            minimo = dato;
        }
        
        n_datos += 1;
        cout << "Introduce un número: ";
        cin >> dato;
    }
    
    cout << "Has introducido " << n_datos << " números, y el menor de ellos es " << minimo << endl;
    return 0;
}
