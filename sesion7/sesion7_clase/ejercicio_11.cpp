#include <iostream>

using namespace std;

const int TAMANO_MAX = 1000;

struct TipoConjunto{
    int num_elem;
    int elementos[TAMANO_MAX];
};


void PedirElementos(TipoConjunto & conjunto, const char nombre[]){
    //Pide y guarda los elementos de un conjunto.
    cout << "Introduzca el número de elementos del conjunto " << nombre << ": ";
    cin >> conjunto.num_elem;
    cout << "Introduzca los elementos del conjunto " << nombre << ": ";
    for (int i = 0; i < conjunto.num_elem; i++){
        cin >> conjunto.elementos[i];
    }
}


void ImprimirElementos(TipoConjunto conjunto, const char nombre[]){
    //Imprime los elementos de un conjunto.
    cout << "Los elementos del conjunto " << nombre << " son: ";
    for (int i = 0; i < conjunto.num_elem; i++){
        cout << conjunto.elementos[i] << " ";
    }
    cout << endl;
}


void OrdenarElementos(TipoConjunto & conjunto){
    //Ordena los elementos de un conjunto mediante insertion sort.
    bool elemento_ordenado = false;
    int swap_aux;
    for (int i = 1; i < conjunto.num_elem; i++){
        elemento_ordenado = false;
        for (int j = i; j > 0 && !elemento_ordenado; j--){
            if (conjunto.elementos[j] < conjunto.elementos[j-1]){
                swap_aux = conjunto.elementos[j];
                conjunto.elementos[j] = conjunto.elementos[j-1];
                conjunto.elementos[j-1] = swap_aux;
            } else {
                elemento_ordenado = true;
            }
        }
    }
}


bool ExisteElemento(int elemento, TipoConjunto conjunto){
    //Comprueba si existe el elemento en el conjunto ordenado mediante búsqueda binaria.
    bool result = false;
    int extremo_inferior = 0, extremo_superior = conjunto.num_elem - 1;
    int i = extremo_inferior + (extremo_superior - extremo_inferior)/2;
    
    while (extremo_inferior <= extremo_superior && !result){
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
    //Inserta un elemento en el conjunto en la posición correcta para que sea ordenado.
    //Otra forma sería simplemente introducir el elemento de forma desordenada, y
    //posteriormente llamar a OrdenarElementos.
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


TipoConjunto UnionConjuntos(TipoConjunto conjunto1, TipoConjunto conjunto2){
    //Calcula y devuelve la unión de los dos conjuntos mediante merge sort.
    //Tambien se podría calcular la unión desordenada y llamar a OrdenarElementos.
    TipoConjunto resultado;
    resultado.num_elem = conjunto1.num_elem + conjunto2.num_elem;
    int i1 = 0, i2 = 0, i_result = 0;
    
    while (i1 < conjunto1.num_elem || i2 < conjunto2.num_elem){
        if (i1 < conjunto1.num_elem && i2 < conjunto2.num_elem){
            if (conjunto1.elementos[i1] < conjunto2.elementos[i2]){
                resultado.elementos[i_result] = conjunto1.elementos[i1];
                i1++;
            } else {
                resultado.elementos[i_result] = conjunto2.elementos[i2];
                i2++;
            }
            
        }
        else if (i1 < conjunto1.num_elem){
            resultado.elementos[i_result] = conjunto1.elementos[i1];
            i1++;
        } else {
            resultado.elementos[i_result] = conjunto2.elementos[i2];
            i2++;
        }
        i_result++;
    }
    
    return resultado;
}


TipoConjunto InterseccionConjuntos(TipoConjunto conjunto1, TipoConjunto conjunto2){
    //Calcula y devuelve la intersección de los dos conjuntos.
    TipoConjunto resultado;
    bool tachados[TAMANO_MAX];
    bool pertenece_a_interseccion = false;
    int i_result = 0;
    
    for (int i = 0; i < conjunto2.num_elem; i++){
        tachados[i] = false;
    }
    
    for (int i1 = 0; i1 < conjunto1.num_elem; i1++){
        pertenece_a_interseccion = false;
        for (int i2 = 0; i2 < conjunto2.num_elem && !pertenece_a_interseccion; i2++){
            if (!tachados[i2] && conjunto1.elementos[i1] == conjunto2.elementos[i2]){
                pertenece_a_interseccion = true;
                tachados[i2] = true;
                resultado.elementos[i_result] = conjunto1.elementos[i1];
                i_result++;
            }
        }
    }
    
    resultado.num_elem = i_result;
    
    return resultado;
}


int main(){
    TipoConjunto conjunto1, conjunto2;
    
    PedirElementos(conjunto1, "1");
    PedirElementos(conjunto2, "2");
    
    OrdenarElementos(conjunto1);
    OrdenarElementos(conjunto2);
    
    ImprimirElementos(conjunto1, "1 ordenados");
    ImprimirElementos(conjunto2, "2 ordenados");
    
    //Determinar si un elemento se encuentra en un conjunto
    int elemento;
    bool resultado1, resultado2;
    
    cout << "Introduzca un elemento para comprobar si existe en los conjuntos: ";
    cin >> elemento;
    
    resultado1 = ExisteElemento(elemento, conjunto1);
    resultado2 = ExisteElemento(elemento, conjunto2);
    
    cout << "El número " << elemento << " " << (resultado1 ? "sí" : "no") << " se encuentra en el conjunto 1." << endl;
    cout << "El número " << elemento << " " << (resultado2 ? "sí" : "no") << " se encuentra en el conjunto 2." << endl;


    //Añadir elemento al conjunto
    cout << "Introduzca un elemento para añadir al conjunto 1: ";
    cin >> elemento;
    InsertarElemento(elemento, conjunto1);
    cout << "Introduzca un elemento para añadir al conjunto 2: ";
    cin >> elemento;
    InsertarElemento(elemento, conjunto2);
    
    ImprimirElementos(conjunto1, "1 tras la inserción");
    ImprimirElementos(conjunto2, "2 tras la inserción");
    
    
    //Unión de conjuntos
    TipoConjunto union_conjuntos = UnionConjuntos(conjunto1, conjunto2);
    
    ImprimirElementos(union_conjuntos, "unión de 1 y 2");
    
    
    //Intersección de conjuntos
    TipoConjunto interseccion_conjuntos = InterseccionConjuntos(conjunto1, conjunto2);
    
    ImprimirElementos(interseccion_conjuntos, "intersección de 1 y 2");
    return 0;
}
