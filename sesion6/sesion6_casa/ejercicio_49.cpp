/*
49. Un numero perfecto es aquel que es igual a la suma de todos sus divisores positivos excepto ´
el mismo. El primer n ´ umero perfecto es el 6 ya que sus divisores son 1, 2 y 3 y ´ 6 = 1 + 2 + 3.
Escribir un programa que muestre el mayor numero perfecto que sea menor a un n ´ umero dado ´
por el usuario.
*/

#include <iostream>

using namespace std;

int main(){
    int numero_maximo;
    bool numero_perfecto_encontrado = false;
    int numero_calculando;
    int suma_divisores = 0;
    
    cout << "Introduce el número máximo: ";
    cin >> numero_maximo;
    numero_calculando = numero_maximo;
    
    while (!numero_perfecto_encontrado && numero_calculando != 0) {
        suma_divisores = 0;
        for (int i = 1; i <= numero_calculando/2; i++){
            if (numero_calculando % i == 0){
                suma_divisores += i;
            }
        }
        
        if (suma_divisores == numero_calculando){
            numero_perfecto_encontrado = true;
        }
        
        numero_calculando -= 1;
    }

    if (numero_calculando == 0){
        cout << "No hay ningún número perfecto por debajo del " << numero_maximo << endl;
    } else {
        cout << "El mayor número perfecto por debajo del " << numero_maximo << " es el " << numero_calculando << endl;
    }
    
    return 0;
}
