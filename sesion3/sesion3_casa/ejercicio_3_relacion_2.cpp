#include <iostream>

using namespace std;

int main(){
    int a, b;

    cout << "Introduzca dos números: ";
    cin >> a >> b;

    if ((a % b == 0) || (b % a == 0)){
        cout << "Un número divide a otro." << endl;
    } else {
        cout << "Ninguno de los dos números divide al otro." << endl;
    }

    return 0;
}
