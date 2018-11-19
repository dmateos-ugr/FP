#include <iostream>

using namespace std;

int MCM(int a, int b){
    int resultado = 0;
    
    for (int i = 0; i <= b && !resultado; i++){
        if ( (i * a) % b == 0 ){
            resultado = i*a;
        }
    }
    
    return resultado;
}


int main(){
    int n1, n2;
    
    cin >> n1 >> n2;
    cout << MCM(n1, n2) << endl;
    
    return 0;
}
