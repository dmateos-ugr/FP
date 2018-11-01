#include <iostream>

using namespace std;

int main(){
    char pais, hortaliza;
    int cantidad;
    
    int contador_espana = 0, contador_francia = 0, contador_alemania = 0;
    
    cin >> pais;
    
    while (pais != '@'){
        cin >> hortaliza >> cantidad;
        
        //Asumo que la entrada es siempre correcta.
        if (pais == 'E'){
            contador_espana += cantidad;
        } else if (pais == 'F'){
            contador_francia += cantidad;
        } else {
            contador_alemania += cantidad;
        }
        
        cin >> pais;
    }
    

    bool espana_es_el_mayor = contador_espana >= contador_francia && contador_espana >= contador_alemania;
    bool francia_mayor_que_alemania = contador_francia >= contador_alemania;
    
    if (espana_es_el_mayor){
        cout << "El país que mas vende es España con un total de " << contador_espana << " toneladas." << endl;
    } else if (francia_mayor_que_alemania){
        cout << "El país que mas vende es Francia con un total de " << contador_francia << " toneladas." << endl;
    } else {
        cout << "El país que mas vende es Alemania con un total de " << contador_alemania << " toneladas." << endl;
    }
    //cout << contador_espana << " " << contador_francia << " " << contador_alemania << endl;
    
    
    return 0;
}
