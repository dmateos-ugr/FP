#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAX_TAM_INPUT = 1000;

class Frase{
    private:
        vector<char> caracteres;
        vector<vector<int>> posiciones_palabras;
        
        //Analiza la frase actualizando posiciones_palabras, necesario tras cualquier modificación
        //para las futuras operaciones sobre la frase.
        void AnalizarFrase();
        
    public:
        //Constructor base, deja la frase en blanco.
        Frase();
        
        //Constructor a partir de vector de chars, establece la frase a ese vector de chars.
        Frase(vector<char> v);
        
        //Devuelve la posición de inicio de la palabra k_ésima.
        int LocalizarPalabra(int k_esima);
        
        //Elimina los blancos iniciales que pueda haber en la frase hasta la primera palabra.
        void EliminaBlancosIniciales();
        
        //Elimina los blancos finales que pueda haber en la frase despues de la ultima palabra.
        void EliminaBlancosFinales();
        
        //Devuelve el número de palabras de la frase.
        int NumeroPalabras();
        
        //Borra la palabra k_ésima de la frase.
        void BorraPalabra(int k_esima);
        
        //Añade un espacio al final de la frase y mueve la palabra k_ésima al final.
        void MoverPalabraFinal(int k_esima);
        
        //Imprime la frase.
        void Imprimir(const char nombre[]);
};

Frase PedirFrase();

int main(){
    Frase frase = PedirFrase();
    frase.Imprimir("introducida");
    
    frase.EliminaBlancosIniciales();
    frase.EliminaBlancosFinales();
    frase.Imprimir("tras eliminar los blancos iniciales y finales");
    
    int n;
    int pos;
    cout << "Introduce un número de palabra para eliminarla: ";
    cin >> n;
    frase.BorraPalabra(n);
    frase.Imprimir("tras eliminar la palabra");
    
    cout << "Introduce un número de palabra para moverla al final: ";
    cin >> n;
    frase.MoverPalabraFinal(n);
    frase.Imprimir("tras mover la palabra al final");
    
    cout << "Introduce un número de palabra para obtener su posición: ";
    cin >> n;
    pos = frase.LocalizarPalabra(n);
    cout << "La palabra introducida está en la posición " << pos << "." << endl;
    
    return 0;
}

void Frase::AnalizarFrase(){
    //Actualiza posiciones_palabras, que es una matriz de dos filas. En la primera está la posición 
    //inicial de cada palabra y en la segunda la posición final.
    //Recorre los caracteres de la frase. Cuando se encuentra un primer caracter que no es un espacio,
    //establece la posición de inicio de esa palabra y comienza a contar. Cuando se encuentra un espacio,
    //para de contar y guarda las posiciones de la palabra. Si termina la frase y estaba contando una
    //palabra, la guarda.
    posiciones_palabras.clear();
    
    int pos_inicial_palabra = 0, pos_final_palabra = 0;
    bool contando = false;
    vector<int> pos_palabra;
    
    
    for (int i = 0; i < caracteres.size(); i++){
        if (caracteres[i] == ' '){
            if (contando){
                contando = false;
                pos_palabra.push_back(pos_inicial_palabra);
                pos_palabra.push_back(pos_final_palabra);
                posiciones_palabras.push_back(pos_palabra);
                pos_palabra.clear();
            }
        } else {
            if (contando){
                pos_final_palabra++;
            } else {
                contando = true;
                pos_inicial_palabra = i;
                pos_final_palabra = i;
            }
        }
    }
    
    if (contando){
        pos_palabra.push_back(pos_inicial_palabra);
        pos_palabra.push_back(pos_final_palabra);
        posiciones_palabras.push_back(pos_palabra);
    }
    
}

Frase::Frase(){}

Frase::Frase(vector<char> v){
    caracteres = v;
    AnalizarFrase();
}

int Frase::LocalizarPalabra(int k_esima){
    int result;
    if (k_esima > 0 && k_esima <= posiciones_palabras.size()){
        result = posiciones_palabras[k_esima - 1][0];
    } else {
        result = -1;
    }
    return result;
}

void Frase::EliminaBlancosIniciales(){
    while (caracteres[0] == ' '){
        caracteres.erase(caracteres.begin());
    }
    AnalizarFrase();
}

void Frase::EliminaBlancosFinales(){
    int last_pos = caracteres.size() - 1;
    while (caracteres[last_pos] == ' '){
        caracteres.erase(caracteres.end() - 1);
        last_pos--;
    }
    AnalizarFrase();
}

int Frase::NumeroPalabras(){
    return posiciones_palabras.size();
}

void Frase::BorraPalabra(int k_esima){
    int pos_inicial = posiciones_palabras[k_esima - 1][0];
    int pos_final = posiciones_palabras[k_esima - 1][1];
    caracteres.erase(caracteres.begin() + pos_inicial, caracteres.begin() + pos_final + 1);
    AnalizarFrase();
}

void Frase::MoverPalabraFinal(int k_esima){
    //Obtiene la longitud y las posiciones inicial y final de la palabra deseada. Inserta un espacio
    //al final de la frase y borra cada caracter de la palabra de donde estaba y lo añade al final.
    if (k_esima > 0 && k_esima < posiciones_palabras.size()){
        int pos_inicial = posiciones_palabras[k_esima - 1][0];
        int pos_final = posiciones_palabras[k_esima - 1][1];
        int longitud = pos_final - pos_inicial + 1;
        
        caracteres.push_back(' ');
        for (int i = 0; i < longitud; i++){
            caracteres.push_back(caracteres[pos_inicial]);
            caracteres.erase(caracteres.begin() + pos_inicial);
        }
        AnalizarFrase();
    }
}


void Frase::Imprimir(const char nombre[]){
    cout << "La frase " << nombre << " es: '";
    for (int i = 0; i < caracteres.size(); i++){
        cout << caracteres[i];
    }
    cout << "'." << endl;
}

Frase PedirFrase(){
    vector<char> v;
    char entrada[MAX_TAM_INPUT];
    
    cout << "Introduzca una frase: ";
    cin.getline(entrada, MAX_TAM_INPUT);
    
    for (int i = 0; i < strlen(entrada); i++){
        v.push_back(entrada[i]);
    }
    
    Frase result(v);
    return result;
    
}

