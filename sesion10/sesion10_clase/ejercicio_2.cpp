#include <iostream>

using namespace std;

class DepositoSimulacion{
    private:
        double capital;
        double interes;
        
    public:
        DepositoSimulacion(double c, double i){
            capital = c;
            interes = i;
        }
    
        bool SetCapital(double c){
            if (c >= 0){
                capital = c;
                return true;
            } else {
                return false;
            }
        }
        
        double GetCapital(){
            return capital;
        }
        
        bool SetInteres(double i){
            if (i >= 0){
                interes = i;
                return true;
            } else {
                return false;
            }
        }
        
        double GetInteres(){
            return interes;
        }
        
        double CapitalTalAnios(int anios){
            double result = capital;
            for (int i = 0; i < anios; i++){
                result = result * (100+interes) / 100;
            }
            return result;
        }
        
        int AniosParaCantidad(double cantidad){
            double c = capital;
            int result = 0;
            while (c < cantidad){
                c = c * (100+interes) / 100;
                result += 1;
            }
            return result;
        }
        
};

int main(){
    double cantidad, interes;
    int anios_entrada, anios_salida;
    double cantidad_entrada, cantidad_salida;
    
    cout << "Introduzca una cantidad de dinero: ";
    cin >> cantidad;
    cout << "Introduzca el interés: ";
    cin >> interes;
    cout << "Introduzca un número de años: ";
    cin >> anios_entrada;
    cout << "Introduzca una cantidad mayor a la anterior: ";
    cin >> cantidad_entrada;
    
    DepositoSimulacion dep(cantidad, interes);
    cantidad_salida = dep.CapitalTalAnios(anios_entrada);
    anios_salida = dep.AniosParaCantidad(cantidad_entrada);
    
    cout << "Se ha introducido un depósito de " << dep.GetCapital() << " con un interés del " << dep.GetInteres() << "%." << endl;
    cout << "Tras " << anios_entrada << " años, el capital total sería de " << cantidad_salida << " euros." << endl;
    cout << "Para obtener un capital de " << cantidad_entrada << " serían necesarios un total de " << anios_salida << " años." << endl;
    
    return 0;
}
