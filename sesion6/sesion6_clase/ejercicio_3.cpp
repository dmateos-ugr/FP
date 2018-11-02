/*3. Implementar un programa que nos diga si una secuencia de caracteres es un pal´ındromo,
es decir, que se lee igual de izquierda a derecha que de derecha a izquierda. Por ejemplo,
’a’,’b’,’b’,’a’ ser´ıa un pal´ındromo, pero ’a’,’c’,’b’,’a’ no lo ser´ıa. Si la secuencia tiene un
numero impar de componentes, la que ocupa la posici ´ on central es descartada, por lo que ´
’a’,’b’,’j’,’b’,’a’ ser´ıa un pal´ındromo. El programa debe leer una serie de caracteres hasta
llegar al terminador ’#’ y diga si es un pal´ındromo. Se puede suponer que la secuencia no
contiene espacios en blanco, ya que para poder leer un espacio en blanco no se puede emplear
cin >> caracter;. Si se quiere tambien considerar los espacios en blanco, se puede ´
utilizar la sentencia caracter = cin.get();. Cada vez que se ejecute cin.get()
el compilador lee un caracter (incluido el espacio en blanco) desde la entrada de datos por ´
defecto.*/

#include <iostream>

using namespace std;

int main(){
    /*
    //C++ STRINGS
    string cadena;
    int tamano;
    bool es_palindromo = true;

    //Entrada
    cout << "Introduce la cadena: ";
    getline(cin, cadena);
    tamano = cadena.size();

    //Cálculos
    int i = 0;
    while (es_palindromo && i < tamano){
        if (cadena[i] != cadena[tamano - i - 1]){
            es_palindromo = false;
        }
        i++;
    }

    if (es_palindromo){
        cout << "La cadena introducida es un palíndromo." << endl;
    } else {
        cout << "La cadena introducida no es un palíndromo." << endl;
    }
    return 0;*/
    
    //C STRINGS (requiere introducir tamaño, ya que no disponemos de la biblioteca cstrings)
    const int TAMANO_MAXIMO = 10000;
    char cadena[TAMANO_MAXIMO];
    int tamano_real;
    bool es_palindromo = true;

    cout << "Introduzca el tamaño de la cadena: ";
    cin >> tamano_real;
    
    cout << "Introduzca la cadena: ";
    cin >> cadena;

    int i = 0;
    while (i < tamano_real && es_palindromo){
        if (cadena[i] != cadena[tamano_real - i - 1]){
            es_palindromo = false;
        }
        i++;
    }

    if (es_palindromo){
        cout << "La cadena introducida es un palíndromo." << endl;
    } else {
        cout << "La cadena introducida no es un palíndromo." << endl;
    }
    //cout << cadena << endl;
    
    return 0;
}
