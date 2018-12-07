#include <iostream>

using namespace std;

const int TAMANO_MAX = 1000;

class EnteroLargo{
    private:
        int n_digitos;
        int digitos[TAMANO_MAX];
        bool negativo;
    
    public:
        //Crea el entero y lo establece a 0.
        EnteroLargo();
        
        //Crea el entero y lo establece a n.
        EnteroLargo(int n);
        
        //Creo el entero a partir de un vector de dígitos.
        EnteroLargo(const int v[], int tam, bool negativ);
        
        //Devuelve el número de dígitos del entero.
        int GetTamano();
        
        //Escribe los dígitos del entero en v.
        void GetDigitos(int v[]);
        
        //Devuelve si es negativo o no.
        bool GetNegativo();
        
        //Establece si es negativo o no.
        void SetNegativo(bool n);
        
        //Imprime el entero.
        void Imprimir();
        
        //Añade ceros a la izquierda del entero hasta que llegue al número de dígitos deseado.
        void AniadirCeros(int tam_a_llegar);
        
        //La explicación es trivial.
        EnteroLargo operator=(int n);
        bool operator<(EnteroLargo n);
        bool operator>(EnteroLargo n);
        bool operator==(EnteroLargo n);
        bool operator!=(EnteroLargo n);
        bool operator<=(EnteroLargo n);
        bool operator>=(EnteroLargo n);
        EnteroLargo operator+(EnteroLargo n);
        EnteroLargo operator-(EnteroLargo n);
};


int main(){
    int n1, n2;
    
    cout << "Introduce un entero: ";
    cin >> n1;
    cout << "Introduce otro entero: ";
    cin >> n2;
    
    EnteroLargo a = n1;
    EnteroLargo b = n2;
    
    bool menor = a < b;
    bool mayor = a > b;
    bool iguales = a == b;
    bool dif = a != b;
    bool menor_igual = a <= b;
    bool mayor_igual = a >= b;
    EnteroLargo suma = a + b;
    EnteroLargo resta = a - b;
    
    cout << "El primer número " << (menor ? "sí" : "no") << " es menor al segundo." << endl;
    cout << "El primer número " << (mayor ? "sí" : "no") << " es mayor al segundo." << endl;
    cout << "El primer número " << (iguales ? "sí" : "no") << " es igual al segundo." << endl;
    cout << "El primer número " << (dif ? "sí" : "no") << " es diferente al segundo." << endl;
    cout << "El primer número " << (menor_igual ? "sí" : "no") << " es menor o igual al segundo." << endl;
    cout << "El primer número " << (mayor_igual ? "sí" : "no") << " es mayor o igual al segundo." << endl;
    cout << "La suma de ambos números es ";
    suma.Imprimir();
    cout << "La resta del primero menos el segundo es ";
    resta.Imprimir();
    
    return 0;
}

EnteroLargo::EnteroLargo(){
    //Inicializa a 0 poniendo que tiene un dígito y que no es negativo.
    n_digitos = 1;
    digitos[0] = 0;
    negativo = false;
}

EnteroLargo::EnteroLargo(int n){
    //Inicializa a un número cualquiera haciendo el número positivo en caso de que sea negativo y calculando sus dígitos.
    int i = 0;
    
    if (n < 0){
        n = -n;
        negativo = true;
    } else {
        negativo = false;
    }
    
    do{
        digitos[i] = n%10;
        n = n/10;
        i++;
    } while(n);
    
    n_digitos = i;
}

EnteroLargo::EnteroLargo(const int v[], int tam, bool negativ){
    //Asigna los argumentos dados a sus correspondientes datos miembros.
    n_digitos = tam;
    for (int i = 0; i < n_digitos; i++){
        digitos[i] = v[i];
    }
    negativo = negativ;
}

int EnteroLargo::GetTamano(){
    return n_digitos;
}

void EnteroLargo::GetDigitos(int v[]){
    for (int i = 0; i < n_digitos; i++){
        v[i] = digitos[i];
    }
}

bool EnteroLargo::GetNegativo(){
    return negativo;
}

void EnteroLargo::SetNegativo(bool n){
    negativo = n;
}

void EnteroLargo::Imprimir(){
    //Imprime el signo - en caso de que sea necesario, y a continuación todos los dígitos.
    if (negativo){
        cout << "-";
    }
    for (int i = n_digitos - 1; i >= 0; i--){
        cout << digitos[i];
    }
    cout << "." << endl;
}

void EnteroLargo::AniadirCeros(int tam_a_llegar){
    //Añade ceros a la izquierda de los dígitos hasta que se llega al tamaño deseado.
    //Nota: al no cambiar el número de dígitos del entero, estos ceros realmente no forman parte
    //de él. Añado estos ceros para poder hacer sumas y restas y asegurarme de que no hay basura.
    for (int i = n_digitos; i < tam_a_llegar; i++){
        digitos[i] = 0;
    }
}

EnteroLargo EnteroLargo::operator=(int n){
    //Operador de asignación a un entero. Llama al constructor dado ese entero.
    EnteroLargo result(n);
    return result;
}


bool EnteroLargo::operator<(EnteroLargo n){
    //Realizo una serie de comprobaciones iniciales determinantes, como por ejemplo comprobar
    //los signos o el número de dígitos de cada entero. En el caso de que sean ambos enteros negativos,
    //se invierte el resultado final (2 < 3 --> -2 > -3) excepto en el caso de la igualdad, que siempre será false.
    //El procedimiento consiste en ir comprobando cifra a cifra en cada número hasta que se encuentre una mayor
    //o menor que la otra. En el caso de que todas las cifras sean iguales, devuelve false.
     
    bool result = true;
    bool terminado = false;
    bool invertir = false;
    int n_digitos2 = n.GetTamano();
    int digitos2[TAMANO_MAX];
    n.GetDigitos(digitos2);
    bool negativo2 = n.GetNegativo();
    int cuenta_digitos_iguales = 0;
    
    
    //Comprobaciones iniciales
    if (negativo && !negativo2){
        terminado = true;
        result = true;
    } else if (!negativo && negativo2){
        terminado = true;
        result = false;
    } else if (negativo && negativo){
        invertir = true;
    }
    
    if (n_digitos > n_digitos2){
        terminado = true;
        result = false;
    } else if (n_digitos < n_digitos2){
        terminado = true;
        result = true;
    }
    
    //Procedimiento
    for (int i = n_digitos - 1; i >= 0 && !terminado; i--){
        if (digitos[i] > digitos2[i]){
            result = false;
            terminado = true;
        } else if (digitos[i] < digitos2[i]){
            result = true;
            terminado = true;
        } else {
            cuenta_digitos_iguales++;
            //cout << digitos[i] << " y " << digitos2[i] << " son iguales." << endl;
        }
    }
    
    if (invertir){
        result = !result;
    }
    
    if (cuenta_digitos_iguales == n_digitos){
        result = false;
    }
    
    
    
    return result;
}

bool EnteroLargo::operator>(EnteroLargo n){
    //Se basa en el anteriormente definido operador <. Invierte el resultado que devuelve este
    //operador, y comprueba la excepción de la igualdad, en cuyo caso se devuelve false.
    bool result;
    result = !(*this < n);
    
    bool iguales = *this == n;
    
    if (iguales){
        result = false;
    }
    
    return result;
}

bool EnteroLargo::operator==(EnteroLargo n){
    //Va comprobando los dígitos de ambos enteros hasta que uno sea diferente al otro y se
    //establezca iguales a false. En caso de que tengan diferente número de dígitos se 
    //establece directamente a false.
    int n_digitos2 = n.GetTamano();
    int digitos2[TAMANO_MAX];
    n.GetDigitos(digitos2);
    bool iguales = true;
    
    if (n_digitos == n_digitos2){
        for (int i = n_digitos - 1; i >= 0 && iguales; i--){
            if (digitos[i] != digitos2[i]){
                iguales = false;
            }
        }
    } else {
        iguales = false;
    }
    
    return iguales;
}

bool EnteroLargo::operator!=(EnteroLargo n){
    return !(*this == n);
}

bool EnteroLargo::operator<=(EnteroLargo n){
    return (*this < n || *this == n);
}

bool EnteroLargo::operator>=(EnteroLargo n){
    return (*this > n || *this == n);
}

EnteroLargo EnteroLargo::operator+(EnteroLargo n){
    //Comienza analizando los casos que son excepciones, es decir cuando alguno de los dos enteros
    //son negativos. El procedimiento empieza añadiendo ceros a la izquierda de los enteros para
    //igualar longitud. Luego va sumando dígito a dígito y calculando el acarreo para el siguiente dígito.
    //En caso de terminar el proceso con acarreo, se pone en un nuevo dígito y se aumenta el tamaño.
    int v_result[TAMANO_MAX];
    int tamano_final;
    int n_digitos2 = n.GetTamano();
    int digitos2[TAMANO_MAX];
    n.GetDigitos(digitos2);
    int acarreo = 0;
    
    bool negativo2 = n.GetNegativo();
    if (negativo && !negativo2){
        EnteroLargo positivo(digitos, n_digitos, false);
        return n - positivo;
    } else if (!negativo && negativo2){
        EnteroLargo positivo(digitos2, n_digitos2, false);
        return (*this - positivo);
    } else if (negativo && negativo2){
        EnteroLargo positivo1(digitos, n_digitos, false);
        EnteroLargo positivo2(digitos2, n_digitos2, false);
        EnteroLargo result = positivo1 + positivo2;
        result.SetNegativo(true);
        return result;
    }
    
    if (n_digitos > n_digitos2){
        n.AniadirCeros(n_digitos);
        tamano_final = n_digitos;
    } else {
        AniadirCeros(n_digitos2);
        tamano_final = n_digitos2;
    }
    
    for (int i = 0; i < tamano_final; i++){
        v_result[i] = (digitos[i] + digitos2[i] + acarreo) % 10;
        acarreo = (digitos[i] + digitos2[i] + acarreo) / 10;
    }
    if (acarreo){
        v_result[tamano_final] = acarreo;
        tamano_final++;
    }
    
    EnteroLargo resultado(v_result, tamano_final, false);
    return resultado;
}

EnteroLargo EnteroLargo::operator-(EnteroLargo n){
    //Comienza analizando los casos que son excepciones, es decir cuando alguno de los dos enteros
    //son negativos o cuando el primer entero es mayor que el segundo.
    //Después de añadir ceros a la izquierda para igualar longitudes, comienza a restar los dos
    //enteros dígito a dígito.En caso de que el dígito del segundo entero sea mayor que el delprimero,
    //se le suma 10 y se resta 1 de su siguiente dígito (igual que se haría en papel).
    //Al final elimina los posibles ceros a la izquierda que puedan haber quedado.
    int v_result[TAMANO_MAX];
    int tamano_final;
    int n_digitos2 = n.GetTamano();
    int digitos2[TAMANO_MAX];
    n.GetDigitos(digitos2);
    
    bool negativo2 = n.GetNegativo();
    
    if (negativo && !negativo2){
        EnteroLargo positivo(digitos, n_digitos, false);
        EnteroLargo result = (positivo + n);
        result.SetNegativo(true);
        return result;
    } else if (!negativo && negativo2){
        EnteroLargo positivo(digitos2, n_digitos2, false);
        return *this + positivo;
    } else if (negativo && negativo2){
        EnteroLargo positivo1(digitos, n_digitos, false);
        EnteroLargo positivo2(digitos2, n_digitos2, false);
        return (positivo2 - positivo1);
    }
    
    
    if (*this < n){
        EnteroLargo result = n - *this;
        result.SetNegativo(true);
        return result;
    }
    
    if (n_digitos > n_digitos2){
        n.AniadirCeros(n_digitos);
        tamano_final = n_digitos;
    } else {
        AniadirCeros(n_digitos2);
        tamano_final = n_digitos2;
    }
    
    for (int i = 0; i < tamano_final; i++){
        if (digitos[i] < digitos2[i]){
            digitos[i] += 10;
            digitos[i+1] -= 1;
        }
        v_result[i] = digitos[i] - digitos2[i];
    }
    
    while (v_result[tamano_final - 1] == 0 && tamano_final > 1){
        tamano_final--;
    }
    
    EnteroLargo resultado(v_result, tamano_final, false);
    return resultado;
}


