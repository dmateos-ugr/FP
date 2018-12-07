#include <iostream>
#include <string>

using namespace std;

class Libro{
    private:
        string autor;
        string titulo;
        string editorial;
        int anio;
    
    public:
        Libro();
        Libro(string autor_, string titulo_, string editorial_, int anio_);
        void AsignarValores(string autor_, string titulo_, string editorial_, int anio_);
        void Show();
        void ShowAutor();
        void ShowTitulo();
        void ShowEditorial();
        void ShowAnio();
        string GetAutor();
        string GetTitulo();
        string GetEditorial();
        int GetAnio();
        bool Comparar(Libro l);
};

Libro PedirLibro();

int main(){
    Libro libro1 = PedirLibro();
    cout << endl;
    libro1.Show();
    cout << endl;
    
    Libro libro2 = PedirLibro();
    cout << endl;
    libro2.Show();
    cout << endl;
    
    bool compare = libro1.Comparar(libro2);
    cout << "Los libros que has introducido " << (compare ? "sí" : "no") << " son iguales." << endl;
    return 0;
}


Libro::Libro(){
    AsignarValores("", "", "", 0);
}

Libro::Libro(string autor_, string titulo_, string editorial_, int anio_){
    AsignarValores(autor_, titulo_, editorial_, anio_);
}

void Libro::AsignarValores(string autor_, string titulo_, string editorial_, int anio_){
    autor = autor_;
    titulo = titulo_;
    editorial = editorial_;
    anio = anio_;
}

void Libro::Show(){
    ShowTitulo();
    ShowAutor();
    ShowEditorial();
    ShowAnio();
}

void Libro::ShowAutor(){
    cout << "Autor del libro: " << autor << "." << endl;
}

void Libro::ShowTitulo(){
    cout << "Título del libro: " << titulo << "." << endl;
}

void Libro::ShowEditorial(){
    cout << "Editorial del libro: " << editorial << "." << endl;
}

void Libro::ShowAnio(){
    cout << "Año del libro: " << anio << "." << endl;
}

string Libro::GetAutor(){
    return autor;
}

string Libro::GetTitulo(){
    return titulo;
}

string Libro::GetEditorial(){
    return editorial;
}

int Libro::GetAnio(){
    return anio;
}

bool Libro::Comparar(Libro l){
    bool result = (autor == l.GetAutor() && titulo == l.GetTitulo() && editorial == l.GetEditorial() && anio == l.GetAnio());
    return result;
}

Libro PedirLibro(){
    string titulo, autor, editorial;
    int anio;
    cout << "Introduce el título: ";
    cin >> titulo;
    cout << "Introduce el autor: ";
    cin >> autor;
    cout << "Introduce la editorial: ";
    cin >> editorial;
    cout << "Introduce los años: ";
    cin >> anio;
    
    Libro result(autor, titulo, editorial, anio);
    return result;
}
