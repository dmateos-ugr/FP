#include <iostream>

using namespace std;

const int TAMANO_MAX = 1000;

struct Permutacion{
    int imagen[TAMANO_MAX];
    int tamano;
};


bool PermutacionCorrecta(Permutacion p){
    //Comprueba si la permutación dada es correcta. Si su tamaño es n, debe tener
    //todos los números desde 1 hasta n. Esto implica que no deben estar repetidos.
    bool correcta = true;
    bool encontrado = false;
    for (int n = 1; n <= p.tamano && correcta ; n++){
        encontrado = false;
        for (int i = 0; i < p.tamano && !encontrado; i++){
            if (p.imagen[i] == n){
                encontrado = true;
            }
        }
        if (!encontrado){
            correcta = false;
        }
    }
    return correcta;
}

Permutacion Composicion(Permutacion p1, Permutacion p2){
    //Compone p1 con p2 y devuelve el resultado.
    //Dada la imagen de dos permutaciones p1 y p2, el elemento i de la composición es
    //obtener el valor de p1 en la posición i, y coger el valor de p2 en la posicion
    //del valor de p1 hallado menos 1, teniendo en cuenta que la posición inicial es 0 y no 1.
    //Ejemplo: componer 1 3 4 2 y 1 4 2 3 --> 1 2 3 4
    //para obtener por ej. el elemento 3 de la composición, voy a la posición 3 de p1,
    //obtengo su valor: 2, le resto 1: 1, y voy a esa posición en p2: 4.
    Permutacion nueva_permutacion;
    nueva_permutacion.tamano = p1.tamano;
    
    for (int i = 0; i < p1.tamano; i++){
        nueva_permutacion.imagen[i] = p2.imagen[p1.imagen[i]-1];
    }
    
    return nueva_permutacion;
}

Permutacion Potencia(Permutacion p, int potencia){
    //Calcula la potencia de una permutación interpretando la multiplicación como una
    //composición y devuelve el resultado.
    Permutacion nueva_permutacion;
    nueva_permutacion.tamano = p.tamano;
    for (int i = 0; i < p.tamano; i++){
        nueva_permutacion.imagen[i] = p.imagen[i];
    }
    
    for (int i = 1; i < potencia; i++){
       nueva_permutacion = Composicion(nueva_permutacion, p);
    }
    
    return nueva_permutacion;
}


int main(){
    Permutacion p;
    Permutacion potencia;
    int exp;
    
    cout << "Introduzca el tamaño de la permutación: ";
    cin >> p.tamano;
    do{
        cout << "Introduzca la imagen de la permutación: ";
        for (int i = 0; i < p.tamano; i++){
            cin >> p.imagen[i];
        }
    } while (! PermutacionCorrecta(p));
    cout << "Introduzca el exponente: ";
    cin >> exp;
    
    potencia = Potencia(p, exp);
    
    
    cout << "La potencia " << exp << " de la permutación dada es: ";
    for (int i = 0; i < potencia.tamano;i++){
        cout << potencia.imagen[i] << " ";
    }
    cout << endl;
    
    return 0;
}
