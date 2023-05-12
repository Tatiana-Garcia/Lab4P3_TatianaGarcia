#include <iostream>
#include <cstdlib>
#include <ctime>
#include<cstring>
using namespace std;
int Factorial(int x) {
	if (x == 0)
		return 1;
	else
		return x * Factorial(x - 1);
}
int num_repeticiones(char c, string cadena) {
	int cont = 0;
	for (int i = 0; i < cadena.size(); i++)
	{
		if (c == cadena[i]) { 
			cont++; 
		}
	}
	return cont;
}
void Permutaciones_con_Repeticion() {
	string cadena = " ";
	string cadena_temp = cadena;
	int acumulador =1;
	//string cadena_temp = " ";
	do {
		cout << "Ingrese palabra para calcular permutaciones: ";
		cin >> cadena;
	} while (cadena.size() < 6);
	cadena_temp = cadena;
	cout << "Letras que se repiten:" << endl;
	for (int i = 0; i < cadena.size(); i++)
	{
		char caracter = cadena[i];
		int num = num_repeticiones(caracter, cadena);
		if (num>1)
		{
			acumulador *= Factorial(num); 
			if (caracter!=' ') cout << caracter << ": " << num << " veces" << endl;
			for (int j = 0; j < cadena.size(); j++)
			{
				if (cadena[j]==caracter) cadena[j] = ' ';
				
			}
		}
	}
	
	int factorial = Factorial(cadena_temp.size()) / acumulador; 
	cout<<factorial<<" -> "
	cout << "Número de permutaciones de la palabra " << cadena_temp << ": " << factorial;

}
void ADN() {

}
void Menu() {//Menu de Ejercicios
	srand(time(NULL));
	int opcion = 1;
	setlocale(LC_ALL, "spanish");
	do {
		cout << "\n---- MENU ----" << endl;
		cout << "0 --> Salida del Programa" << endl;
		cout << "1 --> Permutaciones con Repetición" << endl;
		cout << "2 --> Análisis de ADN" << endl;
		cout << "Ingresar una opción del menu: "; cin >> opcion;
		cout << endl;
		if (opcion == 1)
		{
			Permutaciones_con_Repeticion(); 
		}
		if (opcion == 2)
		{
			ADN(); 
		}
	} while (opcion);
}
int main()
{
	Menu();
}