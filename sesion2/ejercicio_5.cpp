#include <iostream>
using namespace std;

int main(){
    double ganancia_total;
    double ganancia_disenador;
    double ganancia_fabricante;

    cout << "Introduzca la ganancia total de la empresa: ";
    cin >> ganancia_total;
    
    //ganancia total: 40% diseñador, 20% cada fabricante
    ganancia_disenador = ganancia_total * 0.4;
    ganancia_fabricante = ganancia_total * 0.2;
    
    cout << "El diseñador gana un total de " << ganancia_disenador << ", y cada fabricante gana un total de " << ganancia_fabricante << endl;
    return 0;
}
