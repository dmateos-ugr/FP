/*16. Un numero entero ´ n se dice que es desgarrable (torn) si al dividirlo en dos partes izda y dcha,
el cuadrado de la suma de ambas partes es igual a n. Por ejemplo, 88209 es desgarrable ya que
(88+209)2 = 88209. Cread un programa que lea un entero n e indique si es o no desgarrable.
Finalidad: Ejercitar los bucles. Dificultad Baja.*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n, n1, n2;
    int cifras = 0, cifras_probadas = 0, divisor = 0;
    bool desgarrable = false;

    cout << "Introduce un número entero: ";
    cin >> n;

    while (pow(10, cifras) < n){
        cifras++;
    }

    while (!desgarrable && cifras_probadas < cifras){
        divisor = pow(10, cifras_probadas);
        n1 = n / divisor;
        n2 = n % divisor;
        
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
