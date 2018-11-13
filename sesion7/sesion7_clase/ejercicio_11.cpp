#include <iostream>

using namespace std;

struct TipoConjunto{
    int num_elem;
    int elementos[1000];
};


void PedirElementos(TipoConjunto & conjunto, char nombre[]){
    cout << "Introduzca el número de elementos del conjunto " << nombre << ": ";
    cin >> conjunto.num_elem;
    cout << "Introduzca los elementos del conjunto " << nombre << ": ";
    for (int i = 0; i < conjunto.num_elem; i++){
        cin >> conjunto.elementos[i];
    }
}

void ImprimirElementos(TipoConjunto conjunto, char nombre[]){
    cout << "Los elementos del conjunto " << nombre << " son: ";
    for (int i = 0; i < conjunto.num_elem; i++){
        cout << conjunto.elementos[i] << " ";
    }
    cout << endl;
    
}

bool ExisteElemento(int elemento, TipoConjunto conjunto){
    //Comprueba si existe el elemento en el conjunto ordenado mediante búsqueda binaria.
    bool result = false;
    int extremo_inferior = 0, extremo_superior = conjunto.num_elem - 1;
    int i = extremo_inferior + (extremo_superior - extremo_inferior)/2;
    
    while (extremo_inferior < extremo_superior && !result){
        if (elemento == conjunto.elementos[i]){
            result = true;
        } else if (elemento < conjunto.elementos[i]){
            extremo_superior = i - 1;
        } else{
            extremo_inferior = i + 1;
        }
        i = extremo_inferior + (extremo_superior - extremo_inferior)/2;
    }
    return result;
}

void InsertarElemento(int elemento, TipoConjunto & conjunto){
    bool insertado = false;
    for (int i = 0; i < conjunto.num_elem && !insertado; i++){
        if (elemento < conjunto.elementos[i]){
            for (int j = conjunto.num_elem - 1; j >= i ; j--){
                conjunto.elementos[j+1] = conjunto.elementos[j];
            }
            conjunto.elementos[i] = elemento;
            insertado = true;
        }
    }
    if (!insertado){
        conjunto.elementos[conjunto.num_elem] = elemento;
    }
    conjunto.num_elem++;
}



int main(){
    TipoConjunto conjunto1, conjunto2;
    
    PedirElementos(conjunto1, "1");
    PedirElementos(conjunto2, "2");
    
    //Determinar si un elemento se encuentra en un conjunto
    int elemento;
    bool resultado1, resultado2;
    
    cout << "Introduzca un elemento para comprobar si existe en los conjuntos: ";
    cin >> elemento;
    
    resultado1 = ExisteElemento(elemento, conjunto1);
    resultado2 = ExisteElemento(elemento, conjunto2);
    
    cout << "El número " << elemento << " " << (resultado1 ? "sí" : "no") << " se encuentra en el conjunto1." << endl;
    cout << "El número " << elemento << " " << (resultado2 ? "sí" : "no") << " se encuentra en el conjunto2." << endl;


    //Añadir elemento al conjunto
    cout << "Introduzca un elemento para añadir al conjunto 1: ";
    cin >> elemento;
    InsertarElemento(elemento, conjunto1);
    cout << "Introduzca un elemento para añadir al conjunto 2: ";
    cin >> elemento;
    InsertarElemento(elemento, conjunto2);
    
    ImprimirElementos(conjunto1, "1 tras la inserción");
    ImprimirElementos(conjunto2, "2 tras la inserción");
    
    
    //U
    
    return 0;
}
