//Diagrama de flujo:
//https://goo.gl/U9vVMW

#include <iostream>

using namespace std;

int main(){
    int ventas_sucursal1, ventas_sucursal2, ventas_sucursal3;
    ventas_sucursal1 = ventas_sucursal2 = ventas_sucursal3 = 0;
    int id_sucursal, codigo_producto, n_unidades;
    int n_venta = 1;
    bool es_1_el_mayor, es_2_mayor_que_3;
    
    //cout << "1: " << ventas_sucursal1 << " 2: " << ventas_sucursal2 << " 3: " << ventas_sucursal3 << endl;
    //Entrada anticipada
    cout << "A continuación se introducirán los datos de las ventas de las diferentes sucursales (1, 2 o 3). Para finalizar, introduzca un -1 como identificador de la sucursal." << endl;
    do {
        cout << "[Venta " << n_venta << "] Introduzca el identificador de la sucursal: ";
        cin >> id_sucursal;
    } while (id_sucursal != -1 && (id_sucursal > 3 || id_sucursal < 1));
    while (id_sucursal != -1){
        //Entrada
        cout << "[Venta " << n_venta << "] Introduzca el código del producto: ";
        cin >> codigo_producto;
        cout << "[Venta " << n_venta << "] Introduzca el número de unidades vendidas: ";
        cin >> n_unidades;
        
        //Se suman las ventas introducidas
        if (id_sucursal == 1){
            ventas_sucursal1 += n_unidades;
        } else if (id_sucursal == 2){
            ventas_sucursal2 += n_unidades;
        } else {
            ventas_sucursal3 += n_unidades;
        }

        n_venta++; 
        
        //Entrada
        do {
        cout << "[Venta " << n_venta << "] Introduzca el identificador de la sucursal: ";
        cin >> id_sucursal;
        } while (id_sucursal != -1 && (id_sucursal > 3 || id_sucursal < 1));
    }

    //Cálculos: ver cual es la sucursal con mayor ventas
    es_1_el_mayor = ventas_sucursal1 >= ventas_sucursal2 && ventas_sucursal1 >= ventas_sucursal3;
    es_2_mayor_que_3 = ventas_sucursal2 >= ventas_sucursal3;
    
    //Salidas
    if (es_1_el_mayor){
        cout << "SUCURSAL: 1\nVENTAS: " << ventas_sucursal1 << endl;
    } else if (es_2_mayor_que_3) {
        cout << "SUCURSAL: 2\nVENTAS: " << ventas_sucursal2 << endl;
    } else {
        cout << "SUCURSAL: 3\nVENTAS: " << ventas_sucursal3 << endl;
    }
    
    
    
    return 0;
}
