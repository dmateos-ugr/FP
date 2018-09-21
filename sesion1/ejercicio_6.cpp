#include <iostream>
using namespace std;

int main(){
    int edad_Pedro;
    int edad_Juan;
    int aux;
    
    cout << "Introduzca la edad de Pedro en años: ";
    cin >> edad_Pedro;
    cout << "Introduzca la edad de Juan en años: ";
    cin >> edad_Juan;
    
    aux = edad_Juan;
    edad_Juan = edad_Pedro;
    edad_Pedro = aux;
    
    cout << "Las variables han sido intercambiadas." << endl;
    cout << "Pedro tiene " << edad_Pedro << " años y Juan tiene " << edad_Juan << " años." << endl;
    
    return 0;
}

