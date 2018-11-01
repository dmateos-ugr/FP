#include <iostream>

using namespace std;

int main(){
    int dato_introducido, last_dato_introducido;
    int longitud_actual = 0, longitud_mayor = 0;
    int posicion_actual = 1, posicion_inicio_secuencia_actual = 1, posicion_inicio_mayor_secuencia = 1;
    
    cin >> dato_introducido;
    last_dato_introducido = dato_introducido;
    
    while (dato_introducido > 0 && dato_introducido < 100){
        if (dato_introducido >= last_dato_introducido){
            //Continua la secuencia
            longitud_actual++;
            if (longitud_actual > longitud_mayor){
                longitud_mayor = longitud_actual;
                posicion_inicio_mayor_secuencia = posicion_inicio_secuencia_actual;
            } 
        } else {
            //Nueva secuencia
            posicion_inicio_secuencia_actual = posicion_actual;
            longitud_actual = 1;
        }
        
        posicion_actual++;
        last_dato_introducido = dato_introducido;
        cin >> dato_introducido;
    }
    
    cout << "La mayor subsecuencia empezaba en la posicion " << posicion_inicio_mayor_secuencia << " y tiene longitud " << longitud_mayor << endl;
    
    return 0;
}
