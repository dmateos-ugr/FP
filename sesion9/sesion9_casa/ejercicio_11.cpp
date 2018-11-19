#include <iostream>

using namespace std;

int SumaDivisores(int n){
    //Calcula y devuelve la suma de los divisores de n.
    int suma_divisores = 0;
    for (int i = 1; i <= n/2; i++){
        if (n % i == 0){
            suma_divisores += i;
        }
    }
    return suma_divisores;
}

bool Amigos(int n1, int n2){
    int suma1 = SumaDivisores(n1);
    int suma2 = SumaDivisores(n2);
    bool resultado = (suma1 == n2 && suma2 == n1);
    return resultado;
}


int main(){
    int extremo_inferior, extremo_superior;
    
    cin >> extremo_inferior >> extremo_superior;
    
    for (int i = extremo_inferior; i <= extremo_superior; i++){
        for (int j = i; j <= extremo_superior; j++){
            if (Amigos(i, j)){
                cout << i << " " << j << endl;
            }
        }
    }
    
    
    return 0;
}
