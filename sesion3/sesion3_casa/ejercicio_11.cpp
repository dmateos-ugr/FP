#include <iostream>
using namespace std;

int main(){
    cout.precision(12);
    cout << "Ejercicio realizado con g++ (los resultados pueden variar dependiendo del compilador). He realizado los cálculos aparte para determinar si había algún error en las operaciones." << endl;
    //APARTADO A
    int A_chico, A_chico1, A_chico2; A_chico1 = 123456789;
    A_chico2 = 123456780;

    A_chico = A_chico1 * A_chico2;

    cout << "La operación del apartado A da un resultado de: " << A_chico << endl;
    cout << "El resultado debería estar en torno a 1.5e16, por lo que podemos deducir que ha ocurrido un desbordamiento de memoria." << endl << endl;

    //APARTADO B
    long B_grande;
    int B_chico1, B_chico2; B_chico1 = 123456789;
    B_chico2 = 123456780;

    B_grande = B_chico1 * B_chico2;

    cout << "La operación del apartado B da un resultado de: " << B_grande << endl;
    cout << "El resultado es el mismo que en el apartado A, lo cual es sorprendente, ya que lo normal sería que la capacidad de un long fuera mayor." << endl << endl;

    //APARTADO C
    double C_resultado, C_real1, C_real2; C_real1 = 123.1;
    C_real2 = 124.2;

    C_resultado = C_real1 * C_real2;

    cout << "La operación del apartado C da un resultado de: " << C_resultado << endl;
    cout << "Podemos observar que el resultado es correcto, no hay ningún problema." << endl << endl;

    //APARTADO D
    double D_resultado, D_real1, D_real2; D_real1 = 123456789.1;
    D_real2 = 123456789.2;

    D_resultado = D_real1 * D_real2;

    cout << "La operación del apartado D da un resultado de: " << D_resultado << endl;
    cout << "Esta vez el resultado también es correcto." << endl << endl;

    //APARTADO E
    double E_real, E_otro_real; E_real = 2e34;
    E_otro_real = E_real + 1; E_otro_real = E_otro_real - E_real;

    cout << "La operación del apartado E da un resultado de: " << E_otro_real << endl;
    cout << "Aquí hay un problema de imprecisión debido a la alta cantidad amacenada en un double." << endl << endl;

    //APARTADO F
    double F_real, F_otro_real; F_real = 1e+300; F_otro_real = 1e+200;
    F_otro_real = F_otro_real * F_real;

    cout << "La operación del apartado F da un resultado de: " << F_otro_real << endl;
    cout << "En este caso ha vuelto a ocurrir un desbordamiento de memoria, pero en este caso el resultado ha tomado el valor de 'inf'." << endl << endl;

    //APARTADO G
    float G_chico; double G_grande;
    G_grande = 2e+150; G_chico = G_grande;

    cout << "La operación del apartado G da un resultado de: " << G_chico << endl;
    cout << "Ha ocurrido un desbordamiento de memoria al asignar un valor a un double que superaba su tamaño máximo." << endl << endl;
    return 0;
}
