#include <iostream>
using namespace std;

int main(){
    double capital_inicial, capital_calculado;
    double interes;
    int anos = 0;    

    cout << "Introduzca el valor del capital: ";
    cin >> capital_inicial;
    cout << "Introduzca el valor del interes (porcentaje): ";
    cin >> interes;

    capital_calculado = capital_inicial;
    while (capital_calculado < capital_inicial*2){
        capital_calculado = capital_calculado * (100 + interes)/100;
        anos++;
    }

    cout << "Es necesario un total de " << anos << " para doblar el capital." << endl;
    return 0;
}
