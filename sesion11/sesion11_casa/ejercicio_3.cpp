#include <iostream>
#include <cmath>

using namespace std;

const double CONVERSION_A_GRADOS = 180 / M_PI;

class NumeroComplejo{
    private:
        double parte_real;
        double parte_imaginaria;
        double modulo;
        double angulo;
        
        //Calcula y devuelve el módulo del número.
        double CalcularModulo();
        
        //Calcula y devuelve el ángulo del número.
        double CalcularAngulo();
    
    public:
        //Crea el número complejo con parte real e imaginaria 0.
        NumeroComplejo();

        //Crea el número complejo con la parte real e imaginaria dada.
        NumeroComplejo(double real, double imaginaria);
        
        //Establece los valores de parte real e imaginaria dados.
        void SetValores(double real, double imaginaria);
        
        //Establece los valores de módulo y ángulo dados.
        //Nota: este método igual sería mejor privado, pero consideré que un usuario podría querer usarlo.
        void SetValores2(double modulo, double angulo);
        
        //Devuelve la parte real del número.
        double GetReal();
        
        //Devuelve la parte imaginaria del número.
        double GetImaginaria();
        
        //Devuelve el ángulo del número.
        double GetAngulo();
        
        //Devuelve el módulo del número.
        double GetModulo();
        
        //Suma el número complejo dado al propio.
        void Sumar(NumeroComplejo c);
        
        //Resta el número complejo dado al propio.
        void Restar(NumeroComplejo c);
        
        //Multiplica el propio número complejo por el dado.
        void Multiplicar(NumeroComplejo c);
        
        //Divide el propio número complejo entre el dado.
        void Dividir(NumeroComplejo c);
        
        //Imprime el número complejo con el nombre dado.
        void Imprimir(const char nombre[]);
};

//Pide unos valores de parte real e imaginaria y devuelve un número complejo a partir de ellos. 
NumeroComplejo Pedir(const char nombre[]);

//Pregunta qué operación se desea hacer y la lleva a cabo sobre los dos complejos dados.
void Operacion(NumeroComplejo & n1, NumeroComplejo & n2);

int main(){
    NumeroComplejo n1 = Pedir("1");
    NumeroComplejo n2 = Pedir("2");
    
    cout << endl;
    n1.Imprimir("1");
    n2.Imprimir("2");
    Operacion(n1, n2);
    
    cout << endl;
    n1.Imprimir("resultado de la operación");
    
    cout << "Todas las medidas angulares están expresadas en grados sexagesimales, excepto la de la forma exponencial que es en radianes." << endl;
    
    return 0;
}

double NumeroComplejo::CalcularModulo(){
    return sqrt( parte_real*parte_real + parte_imaginaria*parte_imaginaria );
}

double NumeroComplejo::CalcularAngulo(){
    double resultado;
    if (parte_real < 0 && parte_imaginaria == 0){
        resultado = M_PI;
    } else {
        resultado = 2 * atan( parte_imaginaria / (modulo + parte_real) );
    }
    return resultado;
}

NumeroComplejo::NumeroComplejo(){
    SetValores(0, 0);
}

NumeroComplejo::NumeroComplejo(double real, double imaginaria){
    SetValores(real, imaginaria);
}

void NumeroComplejo::SetValores(double real, double imaginaria){
    parte_real = real;
    parte_imaginaria = imaginaria;
    modulo = CalcularModulo();
    angulo = CalcularAngulo();
}

void NumeroComplejo::SetValores2(double modulo, double angulo){
    double nueva_parte_real = modulo * cos(angulo);
    double nueva_parte_imaginaria = modulo * sin(angulo);
    
    SetValores(nueva_parte_real, nueva_parte_imaginaria);
}

double NumeroComplejo::GetReal(){
    return parte_real;
}

double NumeroComplejo::GetImaginaria(){
    return parte_imaginaria;
}

double NumeroComplejo::GetAngulo(){
    return angulo;
}

double NumeroComplejo::GetModulo(){
    return modulo;
}

void NumeroComplejo::Sumar(NumeroComplejo c){
    double nueva_parte_real = parte_real + c.GetReal();
    double nueva_parte_imaginaria = parte_imaginaria + c.GetImaginaria();
    
    SetValores(nueva_parte_real, nueva_parte_imaginaria);
}

void NumeroComplejo::Restar(NumeroComplejo c){
    double nueva_parte_real = parte_real - c.GetReal();
    double nueva_parte_imaginaria = parte_imaginaria - c.GetImaginaria();
    
    SetValores(nueva_parte_real, nueva_parte_imaginaria);
}

void NumeroComplejo::Multiplicar(NumeroComplejo c){
    double nuevo_modulo = modulo * c.GetModulo();
    double nuevo_angulo = angulo + c.GetAngulo();
    
    SetValores2(nuevo_modulo, nuevo_angulo);
}

void NumeroComplejo::Dividir(NumeroComplejo c){
    double nuevo_modulo = modulo / c.GetModulo();
    double nuevo_angulo = angulo - c.GetAngulo();
    
    SetValores2(nuevo_modulo, nuevo_angulo);
}

void NumeroComplejo::Imprimir(const char nombre[]){
    double angulo_grados = angulo*CONVERSION_A_GRADOS;
    cout << "El número complejo " << nombre << " expresado en sus diferentes formas es: " << endl;
    if (parte_imaginaria < 0)
        cout << "\t- Forma binómica: " << parte_real << " " << parte_imaginaria << "i." << endl;
    else
        cout << "\t- Forma binómica: " << parte_real << " + " << parte_imaginaria << "i." << endl;
    cout << "\t- Forma polar: " << modulo << " " << angulo_grados << "º." << endl;
    cout << "\t- Forma exponencial: " << modulo << "e^(" << angulo << "i)." << endl;
    cout << "\t- Forma trigonométrica: " << modulo << "(cos(" << angulo_grados << ") + sen(" << angulo_grados << "i))." << endl << endl;
}

NumeroComplejo Pedir(const char nombre[]){
    double real, imaginaria;
    
    cout << "Introduzca la parte real del número complejo " << nombre << ": ";
    cin >> real;
    cout << "Introduzca la parte imaginaria del número complejo " << nombre << ": ";
    cin >> imaginaria;
    
    NumeroComplejo result(real, imaginaria);
    return result;
}


void Operacion(NumeroComplejo & n1, NumeroComplejo & n2){
    int respuesta;
    do{
        cout << "¿Qué operación quiere realizar con los dos números complejos introducidos? (1: suma. 2: resta. 3: multiplicación. 4: división) : ";
        cin >> respuesta;
    } while (respuesta < 1 || respuesta > 4);
    
    switch (respuesta){
        case 1: 
            n1.Sumar(n2);
            cout << "Se ha realizado la suma de los dos números introducidos." << endl;
            break;
        case 2: 
            n1.Restar(n2);
            cout << "Se ha realizado la resta de los dos números introducidos." << endl;
            break;
        case 3:
            n1.Multiplicar(n2);
            cout << "Se ha realizado la multiplicación de los dos números introducidos." << endl;
            break;
        case 4:
            n1.Dividir(n2);
            cout << "Se ha realizado la división de los dos números introducidos." << endl;
            break;
    }
}
