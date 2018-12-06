#include <iostream>

using namespace std;

class Fecha{
    private:
        int dia, mes, anio;
        
    public:
        Fecha();
        Fecha(int dia_, int mes_, int anio_);
        void SetValores(int dia_, int mes_, int anio_);
        bool ComprobarDatos(int dia_, int mes_, int anio_);
        void DiaSiguiente();
        void DiaAnterior();
        void Imprimir(const char nombre[]);
};

Fecha PedirFecha();

int main(){
    Fecha fecha = PedirFecha();
    fecha.Imprimir("introducida");
    fecha.DiaSiguiente();
    fecha.Imprimir("del día siguiente");
    fecha.DiaAnterior();
    fecha.DiaAnterior();
    fecha.Imprimir("del día anterior");
    
    return 0;
}


Fecha::Fecha(){
    dia = 1;
    mes = 1;
    anio = 1970;
}

Fecha::Fecha(int dia_, int mes_, int anio_){
    SetValores(dia, mes, anio);
}

void Fecha::SetValores(int dia_, int mes_, int anio_){
    if (ComprobarDatos(dia_, mes_, anio_)){
        dia = dia_;
        mes = mes_;
        anio = anio_;
    } else {
        cout << "La fecha introducida no es válida. Se establecerá a 1/1/1970." << endl;
        dia = 1;
        mes = 1;
        anio = 1970;
    }
}

bool Fecha::ComprobarDatos(int dia_, int mes_, int anio_){
    bool fecha_correcta = true;
    bool es_bisiesto = (anio_ % 4 == 0 && (anio_ % 100 != 0 || anio_ % 400 == 0));
    bool mes_de_31 = (mes_ == 1 || mes_ == 3 || mes_ == 5 || mes_ == 7 || mes_ == 8 || mes_ == 10 || mes_ == 12);
    bool mes_de_30 = (mes_ == 4 || mes_ == 6 || mes_ == 9 || mes_ == 11);
    
    if (dia_ < 1 || mes_ < 1 || anio_ < 0){
        fecha_correcta = false;
    }
    
    if (mes_de_31 && dia_ > 31){
        fecha_correcta = false;
    } else if (mes_de_30 && dia_ > 30){
        fecha_correcta = false;
    } else if ( mes_ == 2 && ( (es_bisiesto && dia_ > 29) || (!es_bisiesto && dia_ > 28) ) ){
        fecha_correcta = false;
    }
    /*
    if (mes_de_31){
        if (dia_ > 31){
            fecha_correcta = false;
        }
    } else if (mes_de_30){
        if (dia_ > 30){
            fecha_correcta = false;
        }
    } else {
        if ( (es_bisiesto && dia_ > 29) || (!es_bisiesto && dia_ > 28) ){
            fecha_correcta = false;
        }
    }*/
    
    return fecha_correcta;
}

void Fecha::DiaSiguiente(){
    bool es_bisiesto = (anio % 4 == 0 && (anio % 100 != 0 || anio % 400 == 0));
    bool mes_de_31 = (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12);
    bool mes_de_30 = (mes == 4 || mes == 6 || mes == 9 || mes == 11);
    
    if ( (mes_de_30 && dia == 30) || (mes_de_31 && dia == 31) || (mes == 2 && ( (dia == 28 && !es_bisiesto) || (dia == 29 && es_bisiesto) )) ){
        //Aumenta el mes
        dia = 1;
        if (mes == 12){
            //Aumenta el año
            mes = 1;
            anio += 1;
        } else {
            //No aumenta el año
            mes += 1;
        }
    } else {
        //No aumenta el mes
        dia += 1;
    }
}

void Fecha::DiaAnterior(){
    bool es_bisiesto = (anio % 4 == 0 && (anio % 100 != 0 || anio % 400 == 0));
    bool mes_de_31;
    bool mes_de_30;
    
    if (dia == 1){
        //Disminuye el mes
        if (mes == 1){
            //Disminuye el año
            mes = 12;
            anio -= 1;
        } else {
            //No disminuye el año
            mes -= 1;
        }
        
        //Según el nuevo mes, establezco un día
        mes_de_31 = (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12);
        mes_de_30 = (mes == 4 || mes == 6 || mes == 9 || mes == 11);
        if (mes_de_31){
            dia = 31;
        } else if (mes_de_30){
            dia = 30;
        } else {
            if (es_bisiesto){
                dia = 29;
            } else {
                dia = 28;
            }
        }
        
    } else {
        //No disminuye el mes
        dia -= 1;
    }
}

void Fecha::Imprimir(const char nombre[]){
    cout << "La fecha " << nombre << " es: " << dia << "/" << mes << "/" << anio << "." << endl;
}

Fecha PedirFecha(){
    Fecha resultado;
    
    int dia, mes, anio;
    cout << "Introduce un día: ";
    cin >> dia;
    cout << "Introduce un mes: ";
    cin >> mes;
    cout << "Introduce un anio: ";
    cin >> anio;
    
    resultado.SetValores(dia, mes, anio);
    return resultado;
}
