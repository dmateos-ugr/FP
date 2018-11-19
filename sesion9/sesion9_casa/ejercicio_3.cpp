#include <iostream>
#include <cstring>

using namespace std;


bool Confirmar(){
    char entrada;
    
    do {
        cout << "¿Confirmar (S/N)? ";
        cin >> entrada;
        entrada = tolower(entrada);
    } while (entrada != 's' && entrada != 'n');
    
    return (entrada == 's');
}


int main(){
    cout << Confirmar() << endl;
    
    return 0;
}
