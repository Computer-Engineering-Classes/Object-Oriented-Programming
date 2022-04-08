#include "Forma.h"

int Forma::flag = 0;

Forma::Forma()
	:Cor_interior(0), Cor_contorno(0)
{
	flag++;
}

Forma::Forma(int cor_int, int cor_cont)
	:Cor_interior(cor_int), Cor_contorno(cor_cont)
{
	flag++;
}

int Forma::Get_flag()
{
	return flag;
}

Forma::~Forma()
{
}

void testa_forma(Forma& ref)
{
	cout << "\n Area: " << ref.area();
	cout << "\nPerimetro: " << ref.perimetro();
}