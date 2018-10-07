#include <iostream>

using namespace std;

struct fecha{
    int dia;
    int mes;
    int ano;
};

int main(){
    //Declaración de variables
    fecha fecha_introducida, fecha_siguiente, fecha_anterior, fecha_copia;
    bool es_bisiesto = false;

    //Entrada
    cout << "Introduce una fecha (dia/mes/año): ";
    cin >> fecha_introducida.dia >> fecha_introducida.mes >> fecha_introducida.ano;


    //CALCULAR SI EL AÑO ES BISIESTO
    //es bisiesto cuando es divisible entre 4 y no es secular, o cuando es divisible entre 4, secular y divisible entre 400
    es_bisiesto = (fecha_introducida.ano % 4 == 0 && (fecha_introducida.ano % 100 != 0 || fecha_introducida.ano % 400 == 0));

    //FECHA SIGUIENTE
    //Comprobaciones para aumentar el mes (es decir, cuando sea el ultimo dia del mes):
    if ((fecha_introducida.dia == 30 && (fecha_introducida.mes == 4 || fecha_introducida.mes == 6 ||
         fecha_introducida.mes == 9 || fecha_introducida.mes == 11)) || //meses de 30 dias
            (fecha_introducida.dia == 31 && (fecha_introducida.mes == 1 || fecha_introducida.mes == 3 ||
                fecha_introducida.mes == 5 || fecha_introducida.mes == 7 || fecha_introducida.mes == 8 || 
                    fecha_introducida.mes == 10 || fecha_introducida.mes == 12)) || //meses de 31 dias
                        (fecha_introducida.mes == 2 && ((fecha_introducida.dia == 28 && !es_bisiesto) ||
                            (fecha_introducida.dia == 29 && es_bisiesto)))) {//febrero es especial 
        //Es el último dia del mes: aumenta el mes, y se establece día 1.
        fecha_siguiente.dia = 1;
        if (fecha_introducida.mes == 12){ //Comprobación para aumentar el año
            //Es el último mes del año: aumenta el año
            fecha_siguiente.mes = 1;
            fecha_siguiente.ano = fecha_introducida.ano + 1;
        } else {
            //no aumenta el año
            fecha_siguiente.mes = fecha_introducida.mes + 1;
            fecha_siguiente.ano = fecha_introducida.ano;
        }
    } else {
        //Es un día normal: aumenta el dia, no aumenta el mes, no aumenta el año
        fecha_siguiente.dia = fecha_introducida.dia + 1;
        fecha_siguiente.mes = fecha_introducida.mes;
        fecha_siguiente.ano = fecha_introducida.ano;
    }
    
    
    //FECHA ANTERIOR
    if (fecha_introducida.dia == 1){ //Comprobación para disminuir el mes
        //Es el primer día del mes: disminuye el mes, y se establece el última día del mes anterior.
        if (fecha_introducida.mes == 1){ //Comprobación para disminuir el año.
            //disminuye el año
            fecha_anterior.mes = 12;
            fecha_anterior.ano = fecha_introducida.ano - 1;
        } else {
            //no disminuye el año
            fecha_anterior.mes = fecha_introducida.mes - 1;
            fecha_anterior.ano = fecha_introducida.ano;
        }
        
        //Establezco el último día del mes anterior (fecha_anterior.mes ya tiene el mes anterior a fecha_introducida.mes)
        if (fecha_anterior.mes == 4 || fecha_anterior.mes == 6 || fecha_anterior.mes == 9 || fecha_anterior.mes == 11){
            //Meses de 30 dias
            fecha_anterior.dia = 30;
        } else if (fecha_anterior.mes == 2){
            //Febrero es especial
            if (es_bisiesto){
                fecha_anterior.dia = 29;
            } else {
                fecha_anterior.dia = 28;
            }
        } else {
            //Meses de 31 dias
            fecha_anterior.dia = 31;
        }
    } else {
        //Es un día normal: disminuye el dia, no disminuye mes, no disminuye año
        fecha_anterior.dia = fecha_introducida.dia - 1;
        fecha_anterior.mes = fecha_introducida.mes;
        fecha_anterior.ano = fecha_introducida.ano;
    }

    //Copia de fecha
    fecha_copia = fecha_introducida;

    //Salida de datos
    cout << "El año introducido es bisiesto: " << (es_bisiesto ? "sí" : "no") << endl;
    cout << "La fecha siguiente es " << fecha_siguiente.dia << "/" << fecha_siguiente.mes << "/" << fecha_siguiente.ano << endl;
    cout << "La fecha anterior es " << fecha_anterior.dia << "/" << fecha_anterior.mes << "/" << fecha_anterior.ano << endl;
    cout << "Una copia de la fecha introducida es " << fecha_copia.dia << "/" << fecha_copia.mes << "/" << fecha_copia.ano << endl;
    return 0;
}
