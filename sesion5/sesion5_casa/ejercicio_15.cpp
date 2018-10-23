#include <iostream>

using namespace std;

int main(){
    const int DISTANCIA_MAY_MIN = 'a' - 'A';
    char letra_may, letra_min;
    bool es_mayuscula;

    do {
        cout << "Introduce una letra mayúscula: ";
        cin >> letra_may;
        es_mayuscula = letra_may >= 'A' && letra_may <= 'Z';
    } while (!es_mayuscula);

    letra_min = letra_may + DISTANCIA_MAY_MIN;
    cout << "La letra minúscula es: " << letra_min  << endl;

    return 0;
}
