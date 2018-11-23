#include <iostream>

using namespace std;

void Perfectos(int n){
    int suma = 0;
    
    for (int i = 1; i < n; i++){
        suma = 0;
        
        for (int j = 1; j < i; j++){
            if (i % j == 0){
                suma += j;
            }
        }
        
        if (suma == i){
            cout << i << " ";
        }
        
    }
    
}


int main(){
    int n;
    
    cin >> n;
    Perfectos(n);
    
    return 0;
}
