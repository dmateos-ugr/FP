#include <iostream>

using namespace std;

const int TAM_MAX = 100;

class Examen{
    private:
        string nombre;
        string enunciados[TAM_MAX];
        char respuestas[TAM_MAX];
        int n_preguntas;
        
    public:
        Examen(string name);
        void NuevaPregunta(string enunciado, char respuesta);
        int NumPreguntas();
        string GetEnunciado(int n);
        char GetRespuesta(int n);
        void EvaluarAlumnos(int n);
};

Examen PedirExamen();

int main(){
    int n;
    
    cout << "Se procederá a crear el examen." << endl;
    Examen examen = PedirExamen();
    
    cout << "Se ha finalizado la creación del examen.\nA continuación se procederá a la evaluación de los alumnos. Introduzca el número de alumnos: ";
    cin >> n;
    
    examen.EvaluarAlumnos(n);
    
    cout << "Se ha finalizado la evaluación de alumnos." << endl;
    
    return 0;
}

Examen::Examen(string name){
    nombre = name;
    n_preguntas = 0;
}

void Examen::NuevaPregunta(string enunciado, char respuesta){
    enunciados[n_preguntas] = enunciado;
    respuestas[n_preguntas] = respuesta;
    n_preguntas++;
}

int Examen::NumPreguntas(){
    return n_preguntas;
}

string Examen::GetEnunciado(int n){
    return enunciados[n];
}

char Examen::GetRespuesta(int n){
    return respuestas[n];
}

void Examen::EvaluarAlumnos(int n){
    int nota;
    char respuesta;

    for (int i = 0; i < n; i++){
        nota = 0;
        cout << "Examen del alumno " << i+1 << "." << endl;
        for (int j = 0; j < n_preguntas; j++){
            cout << "Pregunta " << j+1 << ": " << enunciados[j] << endl;
            cout << "Introduzca su respuesta (un solo caracter, '@' será interpretado como respuesta nula): ";
            cin >> respuesta;
            if (respuesta != '@'){
                if (respuesta == respuestas[j]){
                    nota++;
                } else if (nota > 0){
                    nota--;
                }
            }
        }
        
        cout << "Su nota es un " << nota << "." << endl;
    }
}

Examen PedirExamen(){
    string nombre;
    string pregunta;
    char respuesta;
    
    cout << "Introduzca el nombre de la asignatura: ";
    cin >> nombre;
    Examen ex(nombre);
    for (int i = 0; i < 10; i++){
        cout << "Introduzca el enunciado de la pregunta " << i+1 << ": ";
        cin >> pregunta;
        cout << "Introduzca la respuesta de la pregunta " << i+1 << " (debe ser un caracter): ";
        cin >> respuesta;
        ex.NuevaPregunta(pregunta, respuesta);
    }
    
    return ex;
}
