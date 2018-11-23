#include <iostream>
#include <cstring>

using namespace std;

bool EncontrarCaracter(char c, char cadena[]){
    bool result = false;
    int tamano = strlen(cadena);
    for (int i = 0; i < tamano && !result; i++){
        if (cadena[i] == c){
            result = true;
        }
    }
    return result;
}

int main(){
    bool result;
    const int TAMANO_MAX = 1000;
    char caracter, cadena[TAMANO_MAX];
    
    cout << "Introduce una cadena: ";
    cin >> cadena;
    cout << "Introduce un caracter: ";
    cin >> caracter;
    
    result = EncontrarCaracter(caracter, cadena);
    
    cout << "El caracter introducido " << (result ? "sí" : "no") << " aparece en la cadena." << endl;
    
    return 0;
}
