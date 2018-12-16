//Ejercicio cortesía de carlos
//ni lo he mirado, seguro que es un mojon

#include <iostream>

using namespace std;

const int MAX = 1000;

class Bicicleta{
	private:
		int estrella;
		int pinon;
	
	public:
		Bicicleta();
		
		int GetEstrella();
		
		int GetPinon();
		
		void CambiarMarcha(char ordenes[]);
		
		void CambiarMarchaSinRiesgo(char ordenes[]);
};

int main(){
	Bicicleta bici;
	char ordenes[MAX];
	int num_ord = -1;
	
	do{
		num_ord++;
		cin >> ordenes[num_ord];
	}while (ordenes[num_ord] != '#');
	
	bici.CambiarMarcha(ordenes);
	
	cout << "La posicion de la estrella sera " << bici.GetEstrella() << " y la del pinon sera " << bici.GetPinon();
	
	bici.CambiarMarchaSinRiesgo(ordenes);
	
	cout << "\nLa posicion de la estrella sera " << bici.GetEstrella() << " y la del pinon sera " << bici.GetPinon() << ", sin ningun riesgo de rotura de cadena";
	
	return 0;
}


Bicicleta::Bicicleta(){
	estrella = 1;
	pinon = 1;
}

int Bicicleta::GetEstrella(){
	return estrella;
}

int Bicicleta::GetPinon(){
	return pinon;
}

void Bicicleta::CambiarMarcha(char ordenes[]){
	int i = 0;
	
	estrella = 1;
	pinon = 1;
	
	while (ordenes[i] != '#'){
		if (ordenes[i] == 'E'){
			i++;
			if (ordenes[i] == 'S'){
				if (estrella < 3)
					estrella++;
			}
			if (ordenes[i] == 'B'){
				if (estrella > 1)
					estrella--;
			}
		}
		if (ordenes[i] == 'P'){
			i++;
			if (ordenes[i] == 'S'){
				if (pinon < 7)
					pinon++;
			}
			if (ordenes[i] == 'B'){
				if (pinon > 1)
					pinon--;
			}
			if (ordenes[i] == 'T'){
				if (pinon < 6)
					pinon += 2;
			}
			if (ordenes[i] == 'C'){
				if (pinon > 2)
					pinon -= 2;
			}
		}
		i++;
	}
}

void Bicicleta::CambiarMarchaSinRiesgo(char ordenes[]){
	int i = 0;
	
	estrella = 1;
	pinon = 1;
	
	while (ordenes[i] != '#'){
		if (ordenes[i] == 'E'){
			i++;
			if (ordenes[i] == 'S'){
				if (estrella < 3){
					estrella++;
					if ((estrella == 1 && pinon >= 5))
						estrella--;
					if ((estrella == 2 && (pinon == 1 || pinon == 7)))
						estrella--;
					if (estrella == 3 && pinon <= 3)
						estrella--;
				}
			}
			if (ordenes[i] == 'B'){
				if (estrella > 1){
					estrella--;
					if ((estrella == 1 && pinon >= 5))
						estrella++;
					if ((estrella == 2 && (pinon == 1 || pinon == 7)))
						estrella++;
					if (estrella == 3 && pinon <= 3)
						estrella++;
				}
			}
		}
		if (ordenes[i] == 'P'){
			i++;
			if (ordenes[i] == 'S'){
				if (pinon < 7){
					pinon++;
					if ((estrella == 1 && pinon >= 5))
						pinon--;
					if ((estrella == 2 && (pinon == 1 || pinon == 7)))
						pinon--;
					if (estrella == 3 && pinon <= 3)
						pinon--;
				}
			}
			if (ordenes[i] == 'B'){
				if (pinon > 1){
					pinon--;
					if ((estrella == 1 && pinon >= 5))
						pinon++;
					if ((estrella == 2 && (pinon == 1 || pinon == 7)))
						pinon++;
					if (estrella == 3 && pinon <= 3)
						pinon++;
				}
			}
			if (ordenes[i] == 'T'){
				if (pinon < 6){
					pinon += 2;
					if ((estrella == 1 && pinon >= 5))
						pinon -= 2;
					if ((estrella == 2 && (pinon == 1 || pinon == 7)))
						pinon -= 2;
					if (estrella == 3 && pinon <= 3)
						pinon -= 2;
				}
			}
			if (ordenes[i] == 'C'){
				if (pinon > 2){
					pinon -= 2;
					if ((estrella == 1 && pinon >= 5))
						pinon += 2;
					if ((estrella == 2 && (pinon == 1 || pinon == 7)))
						pinon += 2;
					if (estrella == 3 && pinon <= 3)
						pinon += 2;
				}
			}
		}
		i++;
	}
}
