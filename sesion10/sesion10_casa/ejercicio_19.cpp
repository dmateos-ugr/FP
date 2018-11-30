#include <iostream>
#include <string>

using namespace std;

const int TAMANO_MAX = 1000;

class Especie{
	private:
		string nombre;
		string ADN;
		
		bool EsSuADN_aux(int i, string posible_ADN){
			//Comprueba si posible_ADN desde la posición i hasta la posición i - 1 es igual a ADN.
            
			bool resultado = true;
			int pos_final = i;
            
			for (int j = 0; j < ADN.size() && resultado; j++){
				if (ADN[j] != posible_ADN[i]){
					resultado = false;
				}

				//Aumento el indice de posible_ADN
				if (i == posible_ADN.size() - 1){
					i = 0;
				} else {
					i++;
				}
			}
			
			//Ultima comprobacion necesaira: para que posible_ADN no tenga más caracteres aparte
            //de los de ADN. Ejemplo: ADN = holamellamopepe, posible_ADN = epeasdholamellamop
            //devolvería true si no fuera por esta comprobación.
			if (i != pos_final){
				resultado = false;
			}

			return resultado;
		}
		
	public:
		Especie(string nombre_especie, string ADN_especie){
            //Construtor de Especie con argumentos
			nombre = nombre_especie;
			ADN = ADN_especie;
		}
        
        Especie(){
            //Construtor de Especie sin argumentos (por defecto)
            //Es necesario ya que BaseDeDatos al definirse como BaseDeDatos(Especie vector_especies[], int tamano_vector)
            //está creando un vector de Especies sin argumentos.
            nombre = "";
            ADN = "";
        }
        
        string Nombre(){
            //Devuelve el nombre de la Especie.
            return nombre;
        }
		
		
		bool EsSuADN(string posible_ADN){
            //Determina si posible_ADN está contenido en ADN a partir de alguna posición.
            //Busco la primera ocurrencia del primero elemento de ADN en posible_ADN. Si a partir
            //de esa ocurrencia no es igual a ADN, busco la siguiente ocurrencia, hasta que ya no
            //haya ninguna más.
            
			bool resultado = false;
			int i = posible_ADN.find(ADN[0]);
			while (i != -1 && !resultado){
				resultado = EsSuADN_aux(i, posible_ADN);
                i = posible_ADN.find(ADN[0], i+1);
			}
			return resultado;
		}
};


class BaseDeDatos{
    private:
        Especie especies[TAMANO_MAX];
        int tamano;
        
    public:
        BaseDeDatos(Especie vector_especies[], int tamano_vector){
            //Constructor de BaseDeDatos.
            tamano = tamano_vector;
            for (int i = 0; i < tamano; i++){
                especies[i] = vector_especies[i];
            }
        }
        
        string BuscarEspecie(string ADN){
            //Busca entre sus especies si alguna tiene el ADN dado. En ese caso, devuelve
            //su nombre. En otro caso, devuelve una string vacía.
            string resultado = "";
            for (int i = 0; i < tamano && resultado == ""; i++){
                if (especies[i].EsSuADN(ADN)){
                    resultado = especies[i].Nombre();
                }
            }
            return resultado;
        }
    
};

int main(){
    const int numero_especies = 3;
	Especie datos[numero_especies] = {Especie("La mosca del Vinagre", "ATAATGGACAAT"), Especie("La lombriz de tierra", "GGATACT"), Especie("La ameba verde", "AGAGAT")};
	BaseDeDatos b = BaseDeDatos(datos, numero_especies);
    string ADN;
    string especie;
    
    cout << "Introduce una cadena de ADN: ";
    cin >> ADN;
    
    especie = b.BuscarEspecie(ADN);
    
    if (especie != ""){
        cout << "Ese ADN pertenece a la especie: " << especie << endl;
    } else {
        cout << "No hay ninguna especie con ese ADN en la base de datos." << endl;
    }
    
	return 0;
}

