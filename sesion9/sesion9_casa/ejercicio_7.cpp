#include <iostream>

using namespace std;

bool FechaValida(int dia, int mes, int ano){
    bool resultado = true;
    int es_bisiesto = (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0));
    bool mes_de_31 = (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12);
    
    if (dia < 1 || mes < 1 || mes > 12){
        resultado = false;
    }
    
    if (mes_de_31){
        if (dia > 31){
            resultado = false;
        }
    } else if (mes == 2){
        if ( ( es_bisiesto && dia > 29 ) || ( !es_bisiesto && dia > 28 ) ){
            resultado = false;
        }
    } else if (dia > 30){
        resultado = false;
    }
    
    return resultado;
}


int main(){
    int dia, mes, ano;
    
    cin >> dia >> mes >> ano;
    cout << FechaValida(dia, mes, ano) << endl;
    
    return 0;
}
