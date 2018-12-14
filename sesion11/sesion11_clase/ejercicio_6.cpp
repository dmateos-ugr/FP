#include <iostream>
#include <vector>

using namespace std;

class Conjunto{
    private:
        vector<int> elementos;
        void EliminarRepetidos();
        void Ordenar();
        
    public:
        Conjunto();
        Conjunto(vector<int> v);
        vector<int> GetVector();
        bool Existe(int n);
        void Add(int n);
        void Remove(int n);
        Conjunto Union(Conjunto c);
        Conjunto Interseccion(Conjunto c);
        void Imprimir(const char nombre[]);
    
};

int BusquedaBinaria(vector<int> elementos, int n);

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
    int j, elemento;
    for (int i = 1; i < elementos.size(); i++){
        elemento = elementos[i];
        elementos.erase(elementos.begin() + i);
        j = i - 1;
        while (j>= 0 && elementos[j] > elemento){
            j--;
        }
        elementos.insert(elementos.begin() + j + 1, elemento);
    }
}


void Conjunto::EliminarRepetidos(){
    vector<int> elementos_unicos;
    bool encontrado_anteriormente = false;
    
    int i = 0;
    while (i < elementos.size()){
        encontrado_anteriormente = false;
        for (int j = 0; j < elementos_unicos.size() && !encontrado_anteriormente; j++){
            if (elementos[i] == elementos_unicos[j]){
                encontrado_anteriormente = true;
            }
        }
        
        if (encontrado_anteriormente){
            elementos.erase(elementos.begin() + i);
        } else {
            elementos_unicos.push_back(elementos[i]);
            i++;
        }
    }
}

Conjunto::Conjunto(){}

Conjunto::Conjunto(vector<int> v){
    elementos = v;
    EliminarRepetidos();
    Ordenar();
}

vector<int> Conjunto::GetVector(){
    return elementos;
}

bool Conjunto::Existe(int n){
    int posicion = BusquedaBinaria(elementos, n);
    return (posicion != -1);
}

void Conjunto::Add(int n){
    bool introducido = false, elemento_repetido = false;
    
    elemento_repetido = (BusquedaBinaria(elementos, n) != -1);
    
    for (int i = 0; i < elementos.size() && !introducido && !elemento_repetido; i++){
        if (elementos[i] > n){
            elementos.insert(elementos.begin() + i, n);
            introducido = true;
        }
    }
    
    if (!introducido && !elemento_repetido){
        elementos.push_back(n);
    }
}

void Conjunto::Remove(int n){
    int pos = BusquedaBinaria(elementos, n);
    
    if (pos != -1){
        elementos.erase(elementos.begin() + pos);
    }
}

Conjunto Conjunto::Union(Conjunto c){
    vector<int> v_result;
    int i = 0, j = 0;
    vector<int> elementos2 = c.GetVector();
    
    while (i < elementos.size() && j < elementos2.size()){
        if (elementos[i] < elementos2[j]){
            v_result.push_back(elementos[i]);
            i++;
        } else {
            v_result.push_back(elementos2[j]);
            j++;
        }
    }
    
    while (i < elementos.size()){
        v_result.push_back(elementos[i]);
        i++;
    }
    
    while (j < elementos2.size()){
        v_result.push_back(elementos2[j]);
        j++;
    }
    
    Conjunto result(v_result);
    return result;
}

Conjunto Conjunto::Interseccion(Conjunto c){
    vector<int> v_result;
    vector<int> elementos2 = c.GetVector();
    vector<int> elementos2_copy(elementos2);
    
    int pos;
    for (int i = 0; i < elementos.size(); i++){
        pos = BusquedaBinaria(elementos2_copy, elementos[i]);
        if (pos != -1){
            v_result.push_back(elementos[i]);
            elementos2_copy.erase(elementos2_copy.begin() + pos);
        }
    }
    
    Conjunto resultado(v_result);
    return resultado;
}

void Conjunto::Imprimir(const char nombre[]){
    cout << "Los elementos del conjunto " << nombre << " son: ";
    for (int i = 0; i < elementos.size(); i++){
        cout << elementos[i] << " ";
    }
    cout << endl;
}

int BusquedaBinaria(vector<int> elementos, int n){
    int posicion = -1;
    int extremo_inf = 0;
    int extremo_sup = elementos.size() - 1;
    int i = extremo_inf + (extremo_sup - extremo_inf)/2;
    
    while (extremo_sup >= extremo_inf && posicion == -1){
        if (elementos[i] > n){
            extremo_sup = i - 1;
        } else if (elementos[i] < n){
            extremo_inf = i + 1;
        } else {
            posicion = i;
        }
        i = extremo_inf + (extremo_sup - extremo_inf)/2;
    }
    return posicion;
}

Conjunto PedirConjunto(){
    int n;

    cout << "Intrdouzca el número de elementos del conjunto: ";
    cin >> n;
    
    vector<int> v(n);
    
    cout << "Introduzca los elementos del conjunto: ";
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    
    Conjunto result(v);
    return result;
}
