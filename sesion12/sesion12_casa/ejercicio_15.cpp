#include <iostream>
#include <vector>

using namespace std;

const int MAX_TAM = 100;
/*
class Liga{
	private:
		int num_equipos;
		char partidos[MAX_TAM][MAX_TAM];
	public:
		Liga();
		Liga(int n_equipos);
        void NuevoResultado(int equipo1, int equipo2, char resultado);
        vector<int> CalcularPuntuaciones();
        int GetNumEquipos();
        void SetNumEquipos(int n);
};
*/

class Liga{
    private:
        vector< vector<char> > partidos;
    public:
        Liga();
        Liga(int n_equipos);
        void NuevoResultado(int equipo1, int equipo2, char resultado);
        vector<int> CalcularPuntuaciones();
};

class GeneradorLiga{
    public:
        Liga Lee();
};

void ImprimeResultados(vector<int> v);

int main(){
	GeneradorLiga g;
    Liga liga = g.Lee();
    
    vector<int> puntuaciones = liga.CalcularPuntuaciones();
    ImprimeResultados(puntuaciones);
    
	return 0;
}

// --- MÉTODOS LIGA CON ARRAYS ---
/*
Liga::Liga(){
	num_equipos = 0;
}

Liga::Liga(int n_equipos){
	num_equipos = n_equipos;
}

void Liga::NuevoResultado(int equipo1, int equipo2, char resultado){
    if (equipo1 < num_equipos && equipo2 < num_equipos){
        partidos[equipo1][equipo2] = resultado;
    }
}

vector<int> Liga::CalcularPuntuaciones(){
    vector<int> v(num_equipos, 0);
    
    for (int i = 0; i < num_equipos; i++){
        for (int j = 0; j < num_equipos; j++){
            if (i != j){
                if (partidos[i][j] == '1'){
                    v[i] += 3;
                } else if (partidos[i][j] == '2'){
                    v[j] += 3;
                } else {
                    v[i] += 1;
                    v[j] += 1;
                }
            }
        }
    }
    
    return v;
}

int Liga::GetNumEquipos(){
    return num_equipos;
}

void Liga::SetNumEquipos(int n){
    num_equipos = n;
}
*/

// --- MÉTODOS LIGA CON VECTORES ---
Liga::Liga(){}

Liga::Liga(int n_equipos){
    partidos.resize(n_equipos);
    for (int i = 0; i < partidos.size(); i++){
        partidos[i].resize(n_equipos);
    }
    
}
void Liga::NuevoResultado(int equipo1, int equipo2, char resultado){
    if (equipo1 < partidos.size() && equipo2 < partidos.size()){
        partidos[equipo1][equipo2] = resultado;
    }
}

vector<int> Liga::CalcularPuntuaciones(){
    vector<int> v(partidos.size(), 0);
    
    for (int i = 0; i < partidos.size(); i++){
        for (int j = 0; j < partidos[i].size(); j++){ // es lo mismo que partidos.size() ya que es matriz cuadrada
            if (i != j){
                if (partidos[i][j] == '1'){
                    v[i] += 3;
                } else if (partidos[i][j] == '2'){
                    v[j] += 3;
                } else {
                    v[i] += 1;
                    v[j] += 1;
                }
            }
        }
    }
    
    return v;
}


// --- MÉTODOS GENERALES ---

Liga GeneradorLiga::Lee(){
    int n_equipos, equipo1, equipo2;
    char result;
    cin >> n_equipos;
    Liga liga(n_equipos);
    
    int iteraciones = n_equipos * (n_equipos - 1);
    
    for (int i = 0; i < iteraciones; i++){
        cin >> equipo1;
        cin >> equipo2;
        cin >> result;
        liga.NuevoResultado(equipo1, equipo2, result);
    }
    
    return liga;
}

void ImprimeResultados(vector<int> v){
    for (int i = 0; i < v.size(); i++){
        cout << "El equipo número " << i+1 << " tiene: " << v[i] << " puntos." << endl;
    }
}
