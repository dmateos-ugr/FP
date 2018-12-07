#include <iostream>

using namespace std;

const int MAXELEM = 100;

class Conjunto{
    private:
        int num_elem;
        int elementos[MAXELEM];
        void Ordenar();
        void EliminarRepetidos();

    public:
        Conjunto();
        Conjunto(const int v[], int n_elementos);
        int GetTamano();
        void GetElementos(int v[]);
        bool Existe(int n);
        void Add(int n);
        void Remove(int n);
        Conjunto Union(Conjunto c);
        Conjunto Interseccion(Conjunto c);
        void Imprimir(const char nombre[]);
};

Conjunto PedirConjunto();

int main(){
    int n;
    bool existe;
    Conjunto conjunto = PedirConjunto();
    conjunto.Imprimir("introducido");

    cout << "Introduce un número para añadirlo al conjunto: ";
    cin >> n;
    conjunto.Add(n);
    cout << "Introduce un número para quitarlo del conjunto: ";
    cin >> n;
    conjunto.Remove(n);

    conjunto.Imprimir("resultante");

    cout << "Introduce un número para saber si existe o no en el conjunto: ";
    cin >> n;
    existe = conjunto.Existe(n);
    cout << "El número " << n << (existe ? " sí" : " no") << " se encuentra en el conjunto introducido." << endl;

    Conjunto conjunto2 = PedirConjunto();
    Conjunto union_ = conjunto.Union(conjunto2);
    Conjunto interseccion = conjunto.Interseccion(conjunto2);
    union_.Imprimir("unión");
    interseccion.Imprimir("intersección");

    return 0;
}

void Conjunto::Ordenar(){
    bool elemento_ordenado;
    int elemento;
    for (int i = 1; i < num_elem; i++){
        elemento = elementos[i];
        elemento_ordenado = false;
        for (int j = i - 1; j >= 0 && !elemento_ordenado; j--){
            if (elemento < elementos[j]){
                elementos[j+1] = elementos[j];
            } else {
                elementos[j+1] = elemento;
                elemento_ordenado = true;
            }
        }

        if (!elemento_ordenado){
            elementos[0] = elemento;
        }

    }

}

void Conjunto::EliminarRepetidos(){
    //Formas realizando primero la eliminación de repetidos:
    //Forma 1: por cada elemento, recorro el vector a partir de él eliminando los que son iguales a él.


    //Forma 2: por cada elemento, voy guardandalo en otro vector si no está ya en él. si está en él, lo elimino del original.
    //Ordenar forma papa + eliminar = 30 secs
    //Eliminar + ordenar forma papa = 21 secs
    int elem_unicos[MAXELEM];
    int num_elem_unicos = 0;
    bool encontrado;
    int i = 0;
    while (i < num_elem){
        encontrado = false;
        for (int j = 0; j < num_elem_unicos && !encontrado; j++){
            if (elementos[i] == elem_unicos[j]){
                //Lo elimino
                for (int k = i; k < num_elem-1; k++){
                    elementos[k] = elementos[k+1];
                }
                num_elem--;
                encontrado = true;
            }
        }

        if (!encontrado){
            elem_unicos[num_elem_unicos] = elementos[i];
            num_elem_unicos++;
            i++;
        }
    }


    /*
    //Forma realizando primero la ordenación y aprovechándose de ello.
    //Ordenar forma papa + eliminar = 30 secs
    int i = 0;
    while (i < num_elem - 1){
        if (elementos[i] == elementos[i+1]){
            for (int j = i; j < num_elem; j++){
                elementos[j] = elementos[j+1];
            }
            num_elem--;
        } else {
            i++;
        }

    }
    cout << "done" << endl;
    */
}

Conjunto::Conjunto(){
    num_elem = 0;
}

Conjunto::Conjunto(const int v[], int n_elementos){
    num_elem = n_elementos;
    for (int i = 0; i < num_elem; i++){
        elementos[i] = v[i];
    }
    EliminarRepetidos();
    Ordenar();

}

int Conjunto::GetTamano(){
    return num_elem;
}

void Conjunto::GetElementos(int v[]){
    for (int i = 0; i < num_elem;  i++){
        v[i] = elementos[i];
    }
}

bool Conjunto::Existe(int n){
    bool result = false;
    int extremo_inferior = 0;
    int extremo_superior = num_elem - 1;
    int i = extremo_inferior + (extremo_superior - extremo_inferior)/2;

    while (extremo_inferior <= extremo_superior && !result){
        if (n == elementos[i]){
            result = true;
        } else if (n > elementos[i]){
            extremo_inferior = i + 1;
        } else {
            extremo_superior = i - 1;
        }
        i = extremo_inferior + (extremo_superior - extremo_inferior)/2;
    }
    return result;
}

void Conjunto::Add(int n){
    bool introducido = false;
    bool elemento_repetido = false;

    for (int i = 0; i < num_elem && !elemento_repetido && !introducido; i++){
        if (n == elementos[i]){
            elemento_repetido = true;
        } else if (n < elementos[i]){
            for (int j = num_elem; j > i; j--){
                elementos[j] = elementos[j-1];
            }
            elementos[i] = n;
            introducido = true;
            num_elem++;
        }
    }

    if (!introducido && !elemento_repetido){
        elementos[num_elem] = n;
        num_elem++;
    }
}

void Conjunto::Remove(int n){
    bool eliminado;
    for (int i = 0; i < num_elem && !eliminado; i++){
        if (elementos[i] == n){
            for (int j = i; j < num_elem; j++){
                elementos[j] = elementos[j+1];
            }
            eliminado = true;
            num_elem--;
        }
    }
}

Conjunto Conjunto::Union(Conjunto c){
    //mergesort
    int v_result[MAXELEM];
    int i = 0, j = 0, i_result = 0;
    int tamano1 = num_elem;
    int tamano2 = c.GetTamano();
    int elementos2[MAXELEM];
    c.GetElementos(elementos2);

    while (i < tamano1 || j < tamano2){
        if (elementos[i] < elementos2[j]){
            v_result[i_result] = elementos[i];
            i++;
        } else {
            v_result[i_result] = elementos2[j];
            j++;
        }
        i_result++;
    }

    while (i < tamano1){
        v_result[i_result] = elementos[i];
        i++;
        i_result++;
    }

    while (j < tamano2){
        v_result[i_result] = elementos2[j];
        j++;
        i_result++;
    }

    Conjunto resultado(v_result, i_result);
    return resultado;
}

Conjunto Conjunto::Interseccion(Conjunto c){
    int v_resultado[MAXELEM];
    int num_elem2 = c.GetTamano();
    int elementos2[MAXELEM];
    c.GetElementos(elementos2);

    bool tachados[MAXELEM];
    bool pertenece_a_interseccion = false;
    int i_result = 0;

    for (int i = 0; i < num_elem2; i++){
        tachados[i] = false;
    }

    for (int i1 = 0; i1 < num_elem; i1++){
        pertenece_a_interseccion = false;
        for (int i2 = 0; i2 < num_elem2 && !pertenece_a_interseccion; i2++){
            if (!tachados[i2] && elementos[i1] == elementos2[i2]){
                v_resultado[i_result] = elementos[i1];
                tachados[i2] = true;
                pertenece_a_interseccion = true;
                i_result++;
            }
        }
    }


    Conjunto result(v_resultado, i_result);
    return result;
}

void Conjunto::Imprimir(const char nombre[]){
    cout << "Los elementos del conjunto " << nombre << " son: ";
    for (int i = 0; i < num_elem; i++){
        cout << elementos[i] << " ";
    }
    cout << endl;
}

Conjunto PedirConjunto(){
    int n;
    int elem[MAXELEM];

    cout << "Introduzca el número de elementos: ";
    cin >> n;
    cout << "Introduzca los elementos: ";
    for (int i = 0; i < n; i++){
        cin >> elem[i];
    }
    Conjunto result(elem, n);
    return result;
}
