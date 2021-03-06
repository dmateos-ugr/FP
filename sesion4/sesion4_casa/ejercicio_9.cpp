#include <iostream>
#include <string>

using namespace std;

int main(){
    //Declaración de variables
    double renta_bruta, renta_neta, retencion;
    bool autonomo, pensionista, casado = false;
    string tmp;
    
    //Entrada de datos
    cout << "Introduzca su renta bruta: ";
    cin >> renta_bruta;
    cout << "Introduzca su retención en porcentaje: ";
    cin >> retencion;
    
    //AUTONOMO
    do { //not using functions hurts
        cout << "¿Es usted autónomo? (si/no): ";
        cin >> tmp;
    } while (tmp != "si" && tmp != "no");
    autonomo = tmp == "si";
    
    //las leyes fiscales de los autonómos son independientes
    //de las demás condiciones
    if (!autonomo){ 
        //PENSIONISTA
        do { 
            cout << "¿Es usted pensionista? (si/no): ";
            cin >> tmp;
        } while (tmp != "si" && tmp != "no");
        pensionista = tmp == "si";
        
        if (!pensionista){
            //CASADO
            do { 
                cout << "¿Está usted casado? (si/no): ";
                cin >> tmp;
            } while (tmp != "si" && tmp != "no");
            casado = tmp == "si";
        }
    }
    cout << endl;    
    
    //Cálculos y salidas mezcladas
    //(no creo necesario separarlos dada la simplicidad de los cálculos
    //y la cantidad de variables necesarias si se hiciera)
    if (autonomo){
        retencion -= retencion*3/100;
        cout << "Se aplica una bajada del 3% a su retención debido a que es autónomo. Su nueva retención es: " << retencion << "%." << endl;
    } else if (pensionista){
        retencion -= retencion*1/100;
        cout << "Se aplica una bajada del 1% a su retención debido a que es pensionista no autónomo. Su nueva retención es: " << retencion << "%." << endl;
    } else {
        retencion += retencion*2/100;
        cout << "Se aplica una subida del 2% a su retención. Su nueva retención es: " << retencion << "%." << endl;
        if (renta_bruta < 20000) {
            retencion += retencion*6/100;
            cout << "Se aplica una subida del 6% a su retención debido a que su renta bruta es menor de 20000 euros. Su nueva retención es: " << retencion << "%." << endl;
        } else if (!casado) {
            retencion += retencion*10/100;
            cout << "Se aplica una subida del 10% a su retención debido a que es soltero y su renta bruta es mayor de 20000 euros. Su nueva retención es: " << retencion << "%." << endl;
        } else {
            retencion += retencion*8/100;
            cout << "Se aplica una subida del 8% a su retención debido a que no es soltero y su renta bruta es mayor de 20000 euros. Su nueva retención es: " << retencion << "%." << endl;
        }
    }
    
    renta_neta = renta_bruta - renta_bruta * retencion / 100;
    
    cout << "\nTras aplicar una retención del " << retencion << "%, su renta neta sería de un total de " << renta_neta << " euros." << endl;
    return 0;
}
