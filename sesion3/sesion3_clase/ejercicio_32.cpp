#include <iostream>
#include <string>

using namespace std;

struct CuentaCD {
    double saldo;
    double tasa_de_interes;
    int plazo;
    char inicial1;
    char inicial2;
};

int main(){
    CuentaCD cuenta;
    
    cout << "Los resultados de cada apartado están comentados en el código" << endl;
    /*
    APARTADO A. cuenta.saldo
        Sería de tipo double.
    APARTADO B. cuenta.tasa_de_interes
        Sería de tipo double.
    APARTADO C. CuentaCD.plazo
        Es erróneo, ya que CuentaCD es el tipo y no la variable.
    APARTADO D. cuenta_ahorros.inicial1
        Es erróneo, ya que cuenta_ahorros no está definida.
    APARTADO E. cuenta.inicial2
        Sería de tipo char2.
    APARTADO F. cuenta
        Sería de tipo CuentaCD.
    */
    return 0;
}
