#include <iostream>
using namespace std;

int main(){
    int horas, minutos, segundos = 0;
    int dias = 0;
    int aux = 0;

    cout << "Introduce los valores de las horas, los minutos y los segundos respectivamente: ";
    cin >> horas >> minutos >> segundos;
    
    aux = segundos / 60;
    segundos = segundos % 60;
    minutos += aux;
    
    aux = minutos / 60;
    minutos = minutos % 60;
    horas += aux;
    
    aux = horas / 24;
    horas = horas % 24;
    dias = aux;
    
    cout << "La cantidad introducida es " << dias << " dias, " << horas << " horas, " << minutos << " minutos y " << segundos << " segundos." << endl;
    return 0;
}
