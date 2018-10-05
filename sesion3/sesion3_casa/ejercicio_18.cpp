#include <iostream>

using namespace std;

int main(){
    cout << boolalpha;

    //APARTADO A
    bool A_resultado = 2 + 3 < 5 + 8;
    cout << "El resultado del apartado A es: " << A_resultado << endl;
    cout << "Es un bool, ya que en la expresión se evalúan primero ambos lados de la igualdad, y después la propia igualdad, resultando en 5 < 13 = true. Aún así, es recomendable poner paréntesis para evitar ambigüedades: (2 + 3) < (5 + 8)." << endl << endl;

    //APARTADO B
    bool B_resultado = 2 < 3 < 4;
    cout << "El resultado del apartado B es: " << B_resultado << endl;
    cout << "Es un bool, ya que en la expresión se evalúa de izquierda a derecha: 2 < 3 < 4 --> false < 4 --> true, ya que false es interpretado como un 0." << endl << endl;

    //APARTADO C
    double C_resultado = 7/3 + 4.0;
    cout << "El resultado del apartado C es: " << C_resultado << endl;
    cout << "Es un double pero no tiene decimales, ya que 7/3 es una división entera que tiene de resultado 2. El tipo es un double ya que cuando se mezclan dos tipos, se transforma al tipo de mayor capacidad de almacenamiento (en este caso double)." << endl << endl;

    //APARTADO D
    int D_x, D_y, D_z = 4;
    //bool D_resultado_original = (x == 4&&y == 3||z! = 2 == 1! = 2);
    bool D_resultado = (D_x == 4&&D_y == 3||D_z != 2 == 1 != 2);
    cout << "La expresión del apartado D está mal formada, debido a las exclamaciones, que deben ir pegadas al signo igual para formar '!=' ." << endl;
    cout << "Si arreglamos este fallo, el resultado es " << D_resultado <<" , ya que se evalúan primero las igualdades, después los AND y por último los OR, como muestro a continuacion:" << endl;
    cout << "(x == 4&&y == 3||z != 2 == 1 != 2) --> (true&&false||true) --> (false||true) --> (true)" << endl << endl;

    //APARTADO E
    int E_x = 2;
    bool E_resultado = (E_x <= 4||E_x >= 4);
    cout << "La expresión del apartado E siempre va a dar " << E_resultado << ", ya que un entero siempre es mayor, igual o menor a otro entero." << endl << endl;

    //APARTADO F
    int F_x = 2;
    bool F_resultado = (F_x < 4&&F_x > 4);
    cout << "La expresión del apartado F siempre va a dar " << F_resultado << ", ya que un entero no puede ser a la vez menor y mayor que otro." << endl << endl;

    //APARTADO G
    int G_z = 2;
    char G_a = 'd';
    //bool G_resultado_original = (G_z > 6||G_a <' z'&&G_a > ' a'||G_z < 6);
    bool G_resultado = (G_z > 6||G_a <'z'&&G_a > 'a'||G_z < 6);
    cout << "El apartado g es erróneo, ya que introduce varios caracteres dentro de un solo char (' z', ' a')." << endl;
    cout << "Si arreglamos esos fallos, el resultado para z=2 y a='d' es " << G_resultado << ", ya que:" << endl;
    cout << "(z > 6||a < 'z'&&a > 'a'||z<6) --> (2 > 6||'d' < 'z'&&'d' > 'a'||2<6) --> (false|false&&true|true) --> (false|false|true) --> (true)" << endl << endl;  

    return 0;
}
