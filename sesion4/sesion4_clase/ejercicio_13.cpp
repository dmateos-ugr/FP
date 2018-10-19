#include <iostream>
using namespace std;

int main(){
    double capital;
    double interes;
    int anos;    

    cout << "Introduzca el valor del capital: ";
    cin >> capital;
    cout << "Introduzca el valor del interes (porcentaje): ";
    cin >> interes;
    cout << "Introduzca el número de años: ";
    cin >> anos;

    for (int i=1; i <= anos; i++){
        capital = capital * (100 + interes)/100;
        cout << "Total en el año " << i << ": " << capital << " euros." << endl;
    }

    return 0;
}
