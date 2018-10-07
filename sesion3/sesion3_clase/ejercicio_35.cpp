#include <iostream>

using namespace std;

struct fecha{
    int dia;
    int mes;
    int ano;
};

int main(){
    fecha fecha_introducida, fecha_siguiente, fecha_anterior;
    bool es_bisiesto = false;
//    int meses_30_dias[] = {4, 6, 9, 11};
//    int meses_31_dias[] = {1, 3, 5, 7, 8, 10, 12};
    
    cout << "Introduce una fecha (dia/mes/año): ";
    cin >> fecha_introducida.dia >> fecha_introducida.mes >> fecha_introducida.ano;


    //BISIESTO
    //es bisiesto cuando es divisible entre 4 y no es secular, o cuando es divisible entre 4, secular y divisible entre 400
    if (fecha_introducida.ano % 4 == 0){
        //es divisible entre 4
        if (fecha_introducida.ano % 100 == 0){
            //es año secular
            if (fecha_introducida.ano % 400 == 0){
                //es divisible entre 400
                es_bisiesto = true;
            }
        } else {
            //no es año secular
             es_bisiesto = true;
        }
    }

    //SIGUIENTE DIA
    if ((fecha_introducida.dia == 30 && (fecha_introducida.mes == 4 || fecha_introducida.mes == 6 ||
         fecha_introducida.mes == 9 || fecha_introducida.mes == 11)) || //meses de 30 dias
            (fecha_introducida.dia == 31 && (fecha_introducida.mes == 1 || fecha_introducida.mes == 3 ||
                fecha_introducida.mes == 5 || fecha_introducida.mes == 7 || fecha_introducida.mes == 8 || 
                    fecha_introducida.mes == 10 || fecha_introducida.mes == 12)) || //meses de 31 dias
                        (fecha_introducida.mes == 2 && ((fecha_introducida.dia == 28 && !es_bisiesto) ||
                            (fecha_introducida.dia == 29 && es_bisiesto)))) {//febrero es especial 
        //aumenta el mes
        fecha_siguiente.dia = 1;
        if (fecha_introducida.mes == 12){
            //aumenta el año
            fecha_siguiente.mes = 1;
            fecha_siguiente.ano = fecha_introducida.ano + 1;
        } else {
            //no aumenta el año
            fecha_siguiente.mes = fecha_introducida.mes + 1;
            fecha_siguiente.ano = fecha_introducida.ano;
        }
    } else {
        //aumenta el dia, no aumenta el mes, no aumenta el año
        fecha_siguiente.dia = fecha_introducida.dia + 1;
        fecha_siguiente.mes = fecha_introducida.mes;
        fecha_siguiente.ano = fecha_introducida.ano;
    }
    
    
//    int meses_30_dias[] = {4, 6, 9, 11};
//    int meses_31_dias[] = {1, 3, 5, 7, 8, 10, 12};
    //DIA ANTERIOR
    if (fecha_introducida.dia == 1){
        //disminuye el mes
        if (fecha_introducida.mes == 1){
            fecha_anterior.mes = 12;
            fecha_anterior.año = fecha_introducida.año - 1;
        } else {
            fecha_anterior.mes = fecha_introducida.mes - 1;
        }
        
        //pongo dia ultimo dia del mes anterior (el mes ya ha sido establecido)
        if (fecha_anterior.mes == 4 || fecha_anterior.mes == 6 || fecha_anterior. 
    } else {
        //disminuye el dia, no disminuye mes, no disminuye año

    }

    cout << "La fecha siguiente es " << fecha_siguiente.dia << "/" << fecha_siguiente.mes << "/" << fecha_siguiente.ano << endl;
    return 0;
}
