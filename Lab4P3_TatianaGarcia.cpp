#include <iostream>
#include <cstdlib>
#include <ctime>
#include<cstring>
#include <iomanip>
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
	cout << "Número de permutaciones de la palabra " << cadena_temp << ": " << Factorial;

}
string secuencia(string cadena) {
	string secuencia ="";
	int max_A = 0, max_C = 0, max_G = 0, max_T = 0;//contadores de nucleotidos
	int tot_A =0, tot_C = 0, tot_G = 0, tot_T = 0;//total de nucleotidos el cual tiene el maximo de nucleotidos en secuencia
	for (int i = 0; i < cadena.size(); i++)//Analiza cual es el nucleotido con la mayor secuencia 
	{
		for (int j = 0; j < cadena.size()-1; j++)
		{
			switch (cadena[i])
			{
			case 'A': {
				if (cadena[j]=='A')
				{
					max_A++;
				}
				else {
					if (tot_A<max_A)
					{
						tot_A = max_A;
					}
					max_A = 0;
				}
				break;
			}
			case 'C': {
				if (cadena[j] == 'C')
				{
					max_C++;
				}
				else {
					if (tot_C < max_C)
					{
						tot_C = max_C;
					}
					max_C = 0;
				}
				break;
			}
			case 'G': {
				if (cadena[j] == 'G')
				{
					max_G++;
				}
				else {
					if (tot_G < max_G)
					{
						tot_G = max_G;
					}
					max_G = 0;
				}
				break;
			}
			case 'T': {
				if (cadena[j] == 'T')
				{
					max_T++;
				}
				else {
					if (tot_T < max_T)
					{
						tot_T = max_T;
					}
					max_T = 0;
				}
				break;
			}
			default:
				break;
			}
		}
	}
	//Imprime el total del nucleotido mayor
	if (tot_G >= tot_C && tot_G >= tot_T && tot_G >= tot_A)
	{
		for (int i = 0; i < tot_G; i++)
		{
			secuencia += 'G';
		}
	}else if (tot_C >= tot_A && tot_C >= tot_T && tot_C >= tot_G)
	{
		for (int i = 0; i < tot_C; i++)
		{
			secuencia += 'C';
		}
	}else if (tot_A >= tot_C && tot_A >= tot_T && tot_A >= tot_G)
	{
		for (int i = 0; i < tot_A; i++)
		{
			secuencia += 'A';
		}
	}else {
		for (int i = 0; i < tot_T; i++)
		{
			secuencia += 'T';
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
	cout << "Análisis de la cadena de ADN:\n- Número total de nucleótidos: \n- Número de ocurrencias de cada nucleótido:\n";
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
	cout << "- Porcentaje de cada nucleótido: " << endl; 
	cout<<fixed<<setprecision(2) << "A: " << porcentaje_A << "%" << endl << "C: " << porcentaje_C << "%" << endl << "G: " << porcentaje_G << "%" << endl << "T: " << porcentaje_T << "%" << endl;
	cout << "- Secuencia más larga de nucleótidos consecutivos que se repiten: "<<secuencia(cadena);
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