#include <iostream>

using namespace std;

int main(){
    int x = 10;
    int y = 20;
    int z = 30;

    cout << "Los valores de las variables son " << x << " " << y << " " << z << endl;

    x = x + y; //a 'x' le sumo 'y'
    y = x - y; //a 'z' le asigno el valor de x menos el de 'y' (se queda con el de 'x')
    x = x - y; //a 'z' le resto el valor actual de 'y' (que era el de 'x'), y se queda con el valor de 'y'.
    //tengo ahora mismo 'x' con el valor de 'y', e 'y' con el valor de 'x'
    //repito las mismas operaciones con 'z' y con 'x' (que ahora tiene el valor de 'y')
    z = z + x;
    x = z - x;
    z = z - x;

    //A pesar de no usar variables axuliares, podemos ver que la facilidad de lectura ha empeorado bastante,
    //por lo que sería mejor usar una variable auxiliar en contra de lo que pide el ejercicio.
    
    cout << "Los valores de las variables son " << x << " " << y << " " << z << endl;

    return 0;
}
