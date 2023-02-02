/*
* O presente código calcula uma integral de uma função através da Soma de Riemann. Todavia, não é possível verificar o erro 
* sem ter o valor da integral de antemão

* This code calculate the integral of a function by Riemann Sum. However, it isn't possible to check the error without the 
* right value of the integral
*/

#include <iostream>
#include <cmath>
using namespace std;

double func(double);						//f(x). Here, you can change for the integral do you want to calculate
double calcIntegral(double, double, double);//function that returns the integral value
void calcError(double, double);				//Print the absolute, relative and percentual error

int main()
{
	/*
		Para a função f(x) = e^(x+1), eu usei os seguintes valores:
		a = 1
		b = 3
		n_parts = 100000000

		O valor exato da integral dessa função é e^(4) - e^(2)
		
		// -----------------------------------------------------------------

		For the function f(x) = e^(x+1), i used the following values:
		a = 1
		b = 3
		n_parts = 100000000

		The exact value for the integral of this function is e^(4) - e^(2)
	*/

	double a, b, n_parts;

	std::cout << "Limite inferior: ";
	std::cin >> a;

	std::cout << "Limite superior: ";
	std::cin >> b;

	std::cout << "Numero de particoes: ";
	std::cin >> n_parts;

	double appr_value = calcIntegral(a, b, n_parts);

	std::cout << "Resultado: " << appr_value;


	double value = exp(4) - exp(2); 

	calcError(appr_value, value);
}

double func(double x)
{
	return exp(x + 1); // Defina a função que você deseja calcular / Define the function you want to calc
}

double calcIntegral(double a, double b, double n_parts)
{
	/*
		"a" é o limite inferior
		"b" é o limite superior
		"n_parts" é o número de partições 

		// ---------------------------------------
		
		"a" is the lower limit
		 "b" is the upper limit
		"n_parts" is the number of partitions
	*/

	double result = 0;
	double part = (b - a) / n_parts;	//comprimento da partição / partition's width

	for (int i = 0; i < n_parts; i++)
	{
		double x = a + (part * i);
		result += func(x) * part;
	}

	return result;
}

void calcError(double approximate_value, double value)
{
	double abs_error = (value - approximate_value);	// Absolute error
	double rel_error = abs_error / value;			// Relative error
	double perc_error = rel_error * 100;			// Percentual error

	std::cout << "\n\n//-----------------//\n//Tela de erros    //\n//-----------------//\n\n";

	std::cout << "Erro Absoluto: " << fixed << abs_error << std::endl;
	std::cout << "Erro Relativo: " << fixed << rel_error << std::endl;
	std::cout << "Erro Percentual: " << fixed << perc_error << "%" << std::endl;
}