#include <iostream>

using namespace std;

int main(){
    int tope;
    
    do{
    cout << "Introduce un número positivo: ";
    cin >> tope;
    } while (tope <= 0);
    
    
    cout << "Sus divisores son: ";
    for (int i = 1; i <= tope; i++){
        if (tope % i == 0){
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}
