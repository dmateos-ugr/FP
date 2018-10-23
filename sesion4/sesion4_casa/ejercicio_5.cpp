#include <iostream>

using namespace std;

int main(){
    const int DISTANCIA_MAY_MIN = 'a' - 'A';
    char letra_original, letra_convertida;
    bool es_mayuscula;

    cout << "Introduce un caracter: ";
    cin >> letra_original;
    
    es_mayuscula = letra_original >= 'A' && letra_original <= 'Z';

    letra_convertida = letra_original;
    if (es_mayuscula){
        letra_convertida += DISTANCIA_MAY_MIN;
    }
    
    cout << "El carácter " << letra_original << " una vez convertido es: " << letra_convertida << endl;
    
    return 0;
}
