#include <iostream>
#include <cmath>

using namespace std;

struct Punto{
    double x;
    double y;
};

struct Poligono{
    Punto puntos[100];
    int num_puntos;
};

double LongitudLado(Punto punto1, Punto punto2){
    //Calcula la longitud de un segmento dados dos puntos mediante pitágoras.
    double v1 = punto2.x - punto1.x;
    double v2 = punto2.y - punto1.y;
    double longitud = sqrt( (v1*v1) + (v2*v2) );
    return longitud;
}

double AreaTriangulo(Punto punto1, Punto punto2, Punto punto3){
    //Calcula el área de un triángulo dados sus tres puntos.
    double S1 = LongitudLado(punto1, punto2);
    double S2 = LongitudLado(punto2, punto3);
    double S3 = LongitudLado(punto3, punto1);
    double F = (S1 + S2 + S3)/2;
    double area = sqrt( F * (F - S1) * (F - S2) * (F - S3));
    return area;
}

double AreaPoligono(Poligono poligono){
    //Calcula el área de un polígono convexo de forma recursiva.
    //Divido el polígono dado en un triángulo T1 y otro polígono B. El area total
    //es el área de ambos. 
    double resultado;
    
    if (poligono.num_puntos == 3){
        resultado = AreaTriangulo(poligono.puntos[0], poligono.puntos[1], poligono.puntos[2]);
    } else {
        Poligono T1 = {{poligono.puntos[0], poligono.puntos[1], poligono.puntos[2]}, 3};
        Poligono B;
        int j = 0;
        for (int i = 0; i < poligono.num_puntos; i++){
            if (i != 1){
                B.puntos[j] = poligono.puntos[i];
                j++;
            }
        }
        B.num_puntos = j;
        
        resultado = AreaPoligono(T1) + AreaPoligono(B);
    }
    
    return resultado;
}
/*
double AreaPoligono(Poligono poligono){
    //Calcula el área de un polígono convexo sin recursividad.
    //Copio en B el polígono dado. Voy sumando al resultado el area del triangulo formado por
    //los tres primeros puntos de B, y voy quitandole a B ese triángulo hasta que él mismo
    //se queda en un triángulo.
    double resultado = 0;
    
    if (poligono.num_puntos == 3){
        resultado = AreaTriangulo(poligono.puntos[0], poligono.puntos[1], poligono.puntos[2]);
    } else {
        Poligono B;
        for (int i = 0; i < poligono.num_puntos; i++){
            B.puntos[i] = poligono.puntos[i];
        }
        B.num_puntos = poligono.num_puntos;
        
        do {
            resultado += AreaTriangulo(B.puntos[0], B.puntos[1], B.puntos[2]);
            int j = 0;
            for (int i = 0; i < B.num_puntos; i++){
                if (i != 1){
                    B.puntos[j] = B.puntos[i];
                    j++;
                }
            }
            B.num_puntos--; // = j
            
            
        } while (B.num_puntos != 3);
        
        resultado += AreaTriangulo(B.puntos[0], B.puntos[1], B.puntos[2]);
    }
    
    return resultado;
}
*/

int main(){
    //cuadrado {{0,0}, {0,2}, {2,2}, {2,0}}
    //puntos: 0 0 0 2 2 2 2 0
    //area: 4
    //hexagono {{0,0}, {4,0}, {6,2}, {4,4}, {0,4}, {-2,2}}
    //puntos 0 0 4 0 6 2 4 4 0 4 -2 2
    //area 24
    
    Poligono pol;
    Punto p;
    double area;
    
    cout << "Introduce el número de puntos del polígono: ";
    cin >> pol.num_puntos;
    cout << "Introduce los puntos dando sus coordenadas separadas por espacios: ";
    for (int i = 0; i < pol.num_puntos; i++){
        cin >> p.x >> p.y;
        pol.puntos[i] = p;
    }
    
    area = AreaPoligono(pol);
    
    cout << "El área del polígono dado es: " << area << endl;
    return 0;
}
