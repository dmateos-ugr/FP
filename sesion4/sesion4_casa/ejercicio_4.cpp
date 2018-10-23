#include <iostream>

using namespace std;

int main(){
    int n1, n2, n3;
    bool ordenados_ascend, ordenados_descend;
    
    cout << "Introduzca tres números: ";
    cin >> n1 >> n2 >> n3;
    
    ordenados_ascend = n1 < n2 && n2 < n3;
    ordenados_descend = n1 > n2 && n2 > n3;
    if (ordenados_ascend || ordenados_descend){
        cout << "Están ordenados." << endl;
    } else {
        cout << "No están ordenados." << endl;
    }


    return 0;
}
