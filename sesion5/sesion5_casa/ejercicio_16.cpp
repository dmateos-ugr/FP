/*16. Un numero entero ´ n se dice que es desgarrable (torn) si al dividirlo en dos partes izda y dcha,
el cuadrado de la suma de ambas partes es igual a n. Por ejemplo, 88209 es desgarrable ya que
(88+209)2 = 88209. Cread un programa que lea un entero n e indique si es o no desgarrable.
Finalidad: Ejercitar los bucles. Dificultad Baja.*/

/*
Problemas que he tenido con 0, 1, y las potencias de 10.
Antes cifras se inicializaba a 0, y el while que calcula las cifras daba que 0 tenía 0 cifras, ya que
10^0 = 1 > 0, y por ello no se llegaba a ejecutar el interior de ninguno de los dos whiles, resultando en que
0 no era desgarrable.
Además, el while que calcula las cifras antes era <, por lo que las potencias de 10 acababan con una cifra menos.
Esto incluía a 1, que salía con 0 cifras, por lo que el segundo while ni se llegaba a ejecutar, resultando en
que 1 no era desgarrable.
*/
#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n, n1, n2;
    int cifras = 1, cifras_probadas = 0, divisor = 0;
    bool desgarrable = false;

    cout << "Introduce un número entero: ";
    cin >> n;

    while (pow(10, cifras) <= n){
        cifras++;
    }

    cout << "El numero tiene " << cifras << " cifras." << endl;

    while (!desgarrable && cifras_probadas < cifras){
        divisor = pow(10, cifras_probadas);
        n1 = n / divisor;
        n2 = n % divisor;

        cout << n1 << " " << n2 << "    " << pow(n1 + n2, 2) << endl;

        desgarrable = ( pow(n1 + n2, 2) == n );
        cifras_probadas += 1;        
    }

    if (desgarrable){
        cout << "El número " << n << " es desgarrable." << endl;
    } else {
        cout << "El número " << n << " no es desgarrable." << endl;
    }

    return 0;
}
