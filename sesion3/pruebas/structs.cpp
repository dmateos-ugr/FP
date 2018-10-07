#include <iostream>
#include <string>

using namespace std;

struct Persona{
    string nombre;
    int edad;
};

int main(){
    Persona p1 = {"Pepe", 19};
    Persona p2 = {"Maria", 25};
    Persona p3;
    p3.nombre = "asd";
    
    cout << p3.nombre << endl;
    cout << p3.edad << endl;
    return 0;
}
