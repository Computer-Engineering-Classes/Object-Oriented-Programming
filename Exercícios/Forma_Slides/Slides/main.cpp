#include "Circulo.h"
#include "Retangulo.h"
#include "Quadrado.h"
#include <ctime>

#define N 20

Forma* Constroi_forma(int k)
{
	Forma* aux = nullptr;
	switch (k)
	{
	case 0:
		aux = new Circulo(-3, 7, 5, AMARELO);
		break;
	case 1:
		aux = new Retangulo(-2, 6, 5, -8, VERMELHO);
		break;
	case 2:
		aux = new Quadrado(6, 9, 3, VERDE);
		break;
	}
	return aux;
}

int main()
{
	Forma* lista[N];
	int k;
	srand((unsigned)time(nullptr));
	for (int i = 0; i < N; i++)
	{
		k = rand() % 3;
		lista[i] = Constroi_forma(k);
	}
	cout << Forma::Get_flag() << endl;
	for (int i = 0; i < N; i++)
	{
		testa_forma(*lista[i]);
		delete lista[i];
	}
	return(0);
}