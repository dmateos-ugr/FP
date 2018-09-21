#include <iostream>
using namespace std;

int main(){
    double capital;
    double interes;
    
    cout << "Introduzca el valor del capital: ";
    cin >> capital;
    cout << "Introduzca el valor del interes: ";
    cin >> interes;

    capital = capital * (100 + interes)/100;
    
    cout << "Tras un año, el capital total sería de " << capital << endl;
    return 0;
}
