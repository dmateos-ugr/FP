#include <iostream>

using namespace std;

int main(){
    bool es_bisiesto;
    int ano;
    
    cout << "Introduce un año: ";
    cin >> ano;
   
    es_bisiesto = (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0));
    if (es_bisiesto){
        cout << "El año es bisiesto." << endl;
    } else {
        cout << "El año no es bisiesto." << endl;
    }
    return 0;
}


