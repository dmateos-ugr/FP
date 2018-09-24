#include <iostream>
using namespace std;

int main(){
    int precio_centimos = 0;
    int centimos_introducidos = 0;
    int monedas_100, monedas_50, monedas_20, monedas_10, monedas_5, monedas_2, monedas_1 = 0;
    
    cout << "Introduzca el precio del producto que desea comprar en céntimos: ";
    cin >> precio_centimos;
    cout << "Introduzca la cantidad de céntimos que introduce para comprar el producto: ";
    cin >> centimos_introducidos;
    
    centimos_introducidos -= precio_centimos;
    monedas_100 = centimos_introducidos/100;
    centimos_introducidos -= monedas_100*100;
    monedas_50 = centimos_introducidos/50;
    centimos_introducidos -= monedas_50*50;
    monedas_20 = centimos_introducidos/20;
    centimos_introducidos -= monedas_20*20;
    monedas_10 = centimos_introducidos/10;
    centimos_introducidos -= monedas_10*10;
    monedas_5 = centimos_introducidos/5;
    centimos_introducidos -= monedas_5*5;
    monedas_2 = centimos_introducidos/2;
    centimos_introducidos -= monedas_2*2;
    monedas_1 = centimos_introducidos;
    centimos_introducidos -= monedas_1;
    
    cout << "Monedas de euro: " << monedas_100 << endl;
    cout << "Monedas de 50centimos : " << monedas_50 << endl;
    cout << "Monedas de 20 centimos: " << monedas_20 << endl;
    cout << "Monedas de 10 centimos: " << monedas_10 << endl;
    cout << "Monedas de 5 centimos: " << monedas_5 << endl;
    cout << "Monedas de 2 centimos: " << monedas_2 << endl;
    cout << "Monedas de 1 centimo: " << monedas_1 << endl;

    return 0;
}
