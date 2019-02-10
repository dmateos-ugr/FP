#include <iostream>

using namespace std;

const int TAM_MAX = 100;

//Clase para representar un laberinto. Los elementos que componen la matriz son
//0 para los huecos, 1 para los muros, 2 para el inicio, 4 para la salida y 8 para el camino recorrido.
class Laberinto{
    private:
        int filas;
        int columnas;
        int matriz[TAM_MAX][TAM_MAX];
        
        //Establece en v la posición de inicio del laberinto.
        void GetPosicionInicio(int v[2]);
        
        //Establece el valor dado en la posicion del laberinto dada.
        void SetValorEnPosicion(int fil, int col, int valor);
        
        //Busca e imprime las posibles salidas del laberinto siguiendo el camino dado por un avance desde una posición de inicio.
        bool BuscarSalidaAPosibleCamino(int pos_inicio[2], int avance_x, int avance_y);
        
    public:
        //Constructor base del laberinto.
        Laberinto();
        
        //Constructor del laberinto dado el número de filas y de columnas y la matriz de elementos.
        Laberinto(int fil, int col, const int matr[TAM_MAX][TAM_MAX]);
        
        //Establece los datos del laberinto según los dados.
        void SetLaberinto(int fil, int col, const int matr[TAM_MAX][TAM_MAX]);
        
        //Busca e imprime todas las posibles salidas del laberinto.
        bool EncontrarSalida();
        
        //Imprime el laberinto.
        void ImprimirLaberinto(const char nombre[]);
    
};

//Pide y devuelve un laberinto por stdin.
Laberinto PedirLaberinto();

int main(){
    Laberinto laberinto = PedirLaberinto();
    bool hay_salida = laberinto.EncontrarSalida();
    if (!hay_salida){
        cout << "\nNo se ha podido encontrar una salida para el laberinto dado." << endl;
    }
    return 0;
}

Laberinto PedirLaberinto(){
    //Crea y devuelve un laberinto, pidiendo el número de filas y columnas y los elementos, en ese orden.
    
    int f, c, m[TAM_MAX][TAM_MAX];
    cin >> f >> c;
    for (int i = 0; i < f; i++){
        for (int j = 0; j < c; j++){
            cin >> m[i][j];
        }
    }

    Laberinto result(f, c, m);
    result.ImprimirLaberinto("introducido");
    return result;
}

void Laberinto::GetPosicionInicio(int v[2]){
    //Busca entre todos los elementos del laberinto aquel que sea un 2, asignando su posición al vector dado.
    bool encontrado = false;
    for (int i = 0; i < filas && !encontrado; i++){
        for (int j = 0; j < columnas && !encontrado; j++){
            if (matriz[i][j] == 2){
                encontrado = true;
                v[0] = i;
                v[1] = j;
            }
        }
    }
    
    if (!encontrado){
        cout << "ERROR: No se ha encontrado el inicio del laberinto." << endl;
        v[0] = -1;
        v[1] = -1;
    }
}

void Laberinto::SetValorEnPosicion(int fil, int col, int valor){
    matriz[fil][col] = valor;
}

Laberinto::Laberinto(){
    SetLaberinto(0, 0, {});
}

Laberinto::Laberinto(int fil, int col, const int matr[TAM_MAX][TAM_MAX]){
    SetLaberinto(fil, col, matr);
}

void Laberinto::SetLaberinto(int fil, int col, const int matr[TAM_MAX][TAM_MAX]){
    filas = fil;
    columnas = col;
    for (int i = 0; i < fil; i++){
        for (int j = 0; j < col; j++){
            matriz[i][j] = matr[i][j];
        }
    }
}


bool Laberinto::EncontrarSalida(){
    //Para encontrar la salida a un laberinto, hay que recorrer todos los posibles caminos.
    //Dada la posición de inicio, los posibles caminos son ir hacia abajo, arriba, derecha o izquierda,
    //representando estos avances con sus respectivas coordenadas en x e y.
    //Cuando uno de estos posibles caminos llega a la salida, encontrado se establece a true.
    //Una cosa interesante de este método es que podemos decidir cómo movernos para encontrar el camino.
    //En este caso he puesto sólo los movimientos horizontales y verticales, pero podría haber puesto
    //también los diagonales, o incluso especificar que se mueve sólo como un caballo de ajedrez.
    
    bool encontrado = false;
    int pos_inicio[2];
    GetPosicionInicio(pos_inicio);
    
    encontrado += BuscarSalidaAPosibleCamino(pos_inicio, 1, 0);
    encontrado += BuscarSalidaAPosibleCamino(pos_inicio, -1, 0);
    encontrado += BuscarSalidaAPosibleCamino(pos_inicio, 0, 1);
    encontrado += BuscarSalidaAPosibleCamino(pos_inicio, 0, -1);

    
    return encontrado;
}

bool Laberinto::BuscarSalidaAPosibleCamino(int pos_inicio[2], int avance_x, int avance_y){
    //Para ver si se puede salir del laberinto por una dirección, primero hay que comprobar que la posición
    //a la que estamos avanzando está dentro de los límites del laberinto. Si en esta nueva posición hay un 4
    //es que hemos encontrado la salida, imprimimos el laberinto y establecemos que este camino era correcto.
    //Si en la nueva posición hay un 0, es un posible camino a seguir. En este caso hacemos una copia del laberinto,
    //cambiando la posición inicial por un 8 (camino recorrido) y la nueva posición a la que hemos llegado por un 2
    //(punto de inicio), y buscamos las posibles salidas de este nuevo laberinto.
    
    bool camino_correcto = false;
    bool filas_no_excedidas = (pos_inicio[0] + avance_x < filas && pos_inicio[0] + avance_x >= 0);
    bool columnas_no_excedidas = (pos_inicio[1] + avance_y < columnas && pos_inicio[1] + avance_y >= 0);
    int valor_avance;
    if (filas_no_excedidas && columnas_no_excedidas){
        valor_avance = matriz[pos_inicio[0] + avance_x][pos_inicio[1] + avance_y];
        if (valor_avance == 4){
            SetValorEnPosicion(pos_inicio[0], pos_inicio[1], 8);
            ImprimirLaberinto("con un posible camino a seguir");
            camino_correcto = true;
        } else if (valor_avance == 0){
            Laberinto posible_camino(filas, columnas, matriz);
            posible_camino.SetValorEnPosicion(pos_inicio[0], pos_inicio[1], 8);
            posible_camino.SetValorEnPosicion(pos_inicio[0] + avance_x, pos_inicio[1] + avance_y, 2);
            camino_correcto = posible_camino.EncontrarSalida();
        }
    }
    return camino_correcto;
}

void Laberinto::ImprimirLaberinto(const char nombre[]){
    cout << "\nEl laberinto " << nombre << " es:" << endl;
    for (int i = 0; i < filas; i++){
        for (int j = 0; j < columnas; j++){
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}
