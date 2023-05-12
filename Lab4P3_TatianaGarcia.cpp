#include <iostream>
#include <cstdlib>
#include <ctime>
#include<cstring>
using namespace std;
int factorial(int x) {
	if (x == 0)
		return 1;
	else
		return x * factorial(x - 1);
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
	//Validacion
	do {
		cout << "Ingrese palabra para calcular permutaciones: ";
		cin >> cadena;
	} while (cadena.size() < 6);
	cadena_temp = cadena;
	cout << "Letras que se repiten:" << endl;
	//recorre cadena
	for (int i = 0; i < cadena.size(); i++)
	{
		char caracter = cadena[i];
		int num = num_repeticiones(caracter, cadena);
		if (num>1)
		{
			if (caracter != ' ') { 
				acumulador = acumulador * (factorial(num));
				cout << caracter << ": " << num << " veces" << endl; 
			}
			//For para no contar otra vez las letras ya ingresadas
			for (int j = 0; j < cadena.size(); j++)
			{
				if (cadena[j]==caracter) cadena[j] = ' ';
				
			}
		}
	}
	
	int Factorial = factorial(cadena_temp.size()) / acumulador; 
	cout << "N�mero de permutaciones de la palabra " << cadena_temp << ": " << Factorial;

}
string secuencia(string cadena) {
	string secuencia =" ";
	int max_A = 0, max_C = 0, max_G = 0, max_T = 0;
	for (int i = 0; i < cadena.size(); i++)
	{
		for (int j = 0; j < cadena.size()-1; j++)
		{
			switch (cadena[i])
			{
			case 'A': {
				break;
			}
			case 'C': {
				break;
			}
			case 'G': {
				break;
			}
			case 'T': {
				break;
			}
			default:
				break;
			}
		}
	}
	return secuencia; 
}
void ADN() {
	string cadena = " ";
	bool valid = false;
	
	//int acumulador = 1;
	//string cadena_temp = " ";

	///Validacion de A G C T
	do {
		cout << "Ingrese una cadena de ADN: ";
		cin >> cadena;
		for (int i = 0; i < cadena.size(); i++)
		{
			char c = cadena[i];
			if (c != 'A' && c != 'C' && c != 'G' && c != 'T') {
				valid = false;
				break;
			}
			else {
				valid = true;
			}
		}
	} while (!valid);

	int cont_A =0, cont_C =0, cont_G=0, cont_T=0;
	int porcentaje;
	cout << "An�lisis de la cadena de ADN:\n- N�mero total de nucle�tidos: \n- N�mero de ocurrencias de cada nucle�tido:\n";
	for (int i = 0; i < cadena.size(); i++)
	{
		switch (cadena[i])
		{
		case 'A': {
			cont_A++;
			break;
		}
		case 'C': {
			cont_C++;
			break;
		}
		case 'G': {
			cont_G++;
			break;
		}
		case 'T': {
			cont_T++;
			break;
		}
		default:
			break;
		}
	}

	double porcentaje_A = ((double)cont_A / cadena.size()) * 100;
	double porcentaje_C = ((double)cont_C / cadena.size()) * 100; 
	double porcentaje_G = ((double)cont_G / cadena.size()) * 100;
	double porcentaje_T = ((double)cont_T / cadena.size()) * 100;
	cout << "A: " << cont_A << endl << "C: " << cont_C << endl << "G: " << cont_G << endl << "T: " << cont_T << endl;
	cout << "- Porcentaje de cada nucle�tido: " << endl; 
	cout << "A: " << porcentaje_A<<"%" << endl << "C: " << porcentaje_C<< "%" << endl << "G: " <<porcentaje_G<< "%" << endl << "T: " << porcentaje_T << "%" << endl;
	cout << "Secuencia m�s larga de nucle�tidos consecutivos que se repiten: "<<secuencia(cadena);

}
void Menu() {//Menu de Ejercicios
	srand(time(NULL));
	int opcion = 1;
	setlocale(LC_ALL, "spanish");
	do {
		cout << "\n---- MENU ----" << endl;
		cout << "0 --> Salida del Programa" << endl;
		cout << "1 --> Permutaciones con Repetici�n" << endl;
		cout << "2 --> An�lisis de ADN" << endl;
		cout << "Ingresar una opci�n del menu: "; cin >> opcion;
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