#include <iostream>

using namespace std;

int main(){
    //Declaración de variables
    int edad;
    double ingresos;
    double nuevos_ingresos1, nuevos_ingresos2;
    bool ingresos_subidos;
    
    //Entrada de datos
    cout << "Introduzca su edad: ";
    cin >> edad;
    cout << "Introduzca sus ingresos: ";
    cin >> ingresos;
    
    //Método 1: mezcando cómputos y salidas
    cout << "\n[MÉTODO 1] Mezclando cómputos y salidas." << endl;
    if (edad > 65 && ingresos < 300){
        nuevos_ingresos1 = ingresos * 105 / 100;
        cout << "Se le ha aplicado una subida del 5%." << endl;
    } else {
        nuevos_ingresos1 = ingresos;
        cout << "La subida no es aplicable." << endl;
    }
    cout << "Su salario resultantes es " << nuevos_ingresos1 << endl;
    
    
    //Método 2: separando cómputos y salidas
    cout << "\n[MÉTODO 2] Separando cómputos y salidas." << endl;
    
    //Cómputos
    if (edad > 65 && ingresos < 300){
        ingresos_subidos = true;
        nuevos_ingresos2 = ingresos * 105 / 100;
    } else {
        ingresos_subidos = false;
        nuevos_ingresos2 = ingresos;
    }
    
    //Salidas
    if (ingresos_subidos){
        cout << "Se le ha aplicado una subida del 5%." << endl;
    } else {
        cout << "La subida no es aplicable." << endl;
    }
    
    cout << "Su salario resultantes es " << nuevos_ingresos2 << endl;
    
    return 0;
}
