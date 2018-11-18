#include <iostream>
#include <string>

using namespace std;

string Codificar(string c, int n){
    string resultado = "";
    int tamano_palabra = 0;
    
    for (int i = 0; i < c.size(); i++){
        if (c[i] == ' '){
            tamano_palabra = 0;
        } else if (tamano_palabra < n){
            resultado += tolower(c[i]);
            tamano_palabra++;
        }
    }
    
    return resultado;
}


int main(){
    string cadena;
    string usuario;
    int n;
    
    cout << "Introduzca nombre y apellidos: ";
    getline(cin, cadena);
    cout << "Introduzca un entero: ";
    cin >> n;
    
    usuario = Codificar(cadena, n);
    
    cout << "El usuario sugerido es: " << usuario << endl;
    
    return 0;
}
