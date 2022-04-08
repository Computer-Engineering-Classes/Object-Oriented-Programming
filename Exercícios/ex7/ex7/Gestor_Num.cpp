#include "Gestor_Num.h"

Gestor_Num::Gestor_Num()
{
}

Gestor_Num::~Gestor_Num()
{
	num_list.clear();
}

void Gestor_Num::Adicionar_Num(void)
{
	int num;
	cout << endl << "Número que quer adicionar: ";
	cin >> num;
	num_list.push_back(num);
}

void Gestor_Num::Remover_Num(void)
{
	int num;
	cout << endl << "Número que quer remover: ";
	cin >> num;
	list<int>::iterator iter = num_list.begin();
	iter = find(num_list.begin(), num_list.end(), num);
	if (iter != num_list.end())
		num_list.erase(iter);
}

void Gestor_Num::Mostrar_Lista(void)
{
	list<int>::iterator p;
	if (!num_list.empty())
	{
		p = num_list.begin();
		while (p != num_list.end())
		{
			cout << endl << *p << endl;
			p++;
		}
	}
}

int Gestor_Num::Obter_Posicao(void)
{
	int num, k = 0;
	cout << endl << "Número que quer procurar: ";
	cin >> num;
	list<int>::iterator p;
	if (!num_list.empty())
	{
		p = num_list.begin();
		while (p != num_list.end())
		{
			if (*p == num)
				return k;
			k++;
			p++;
		}
	}
	return(-1);
}

void Gestor_Num::Ordenar_Lista(void)
{
	num_list.sort();
}
