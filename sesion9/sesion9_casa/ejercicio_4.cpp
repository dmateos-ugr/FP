#include <iostream>

using namespace std;

char To_Lower(char c){
    char result;
    int distancia = 'a' - 'A';
    bool mayuscula = (c >= 'A' && c <= 'Z');
    if (mayuscula){
        result = c + distancia;
    } else {
        result = c;
    }
    
    return result;
}

int main(){
    char c;
    
    cin >> c;
    cout << To_Lower(c) << endl;
    
    return 0;
}
