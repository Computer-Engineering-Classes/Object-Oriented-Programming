#include "Conta.h"

int main()
{
	setlocale(LC_ALL, "");
	Conta c1("André Sousa", "Vila Real, PT", 12324328, 600, 26, 5, 2020);
	Conta c2("Vítor Filipe", "Vila Real, PT", 145544545, 0, 26, 5, 2020);
	Conta c3("André Sousa", "Vila Real, PT", 12324328, 20, 20, 11, 2001);
	cout << c1 << c2;
	c2.Deposito(c1.Levantamento(174));
	cout << c1 << c2;
	c3 = c3 + c1;
	cout << c3;
}