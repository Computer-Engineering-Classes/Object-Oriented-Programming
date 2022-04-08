
#include <iostream>
#include "Funcionario.h"

#define N 3

using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	Funcionario f1("Joca Gaio", Data(20, 9, 1987), "Rua da direita n 2", 25023, "Pintura");
	Funcionario f2("Ana Rola", Data(4, 2, 1990), "Rua da esquerda n 3", 25024, "Comercial");
	/*f1.ShowFunc();
	f2.ShowFunc();
	f1.SetMorada("Rua do meio n 4");
	f1.SetSetor("Ferragem");
	f2.GetDatan().SetDia(23);*/
	Funcionario f3, f4;
	cin >> f3;
	//cin >> f4;
	string str;
	cout << "Insira o nome do ficheiro: ";
	cin >> str;
	str += ".txt";
	fstream file;
	file.open(str);
	f1.SaveFile(file);
	f2.SaveFile(file);
	f3.SaveFile(file);
	file.clear();
	file.seekg(0, file.beg);
	Funcionario lista[N];
	for (int i = 0; i < N; i++)
	{
		lista[i].ReadFile(file);
		lista[i].ShowFunc();
	}
	file.close();
	for (int i = 0; i < N-1; i++)
	{
		for (int j = i+1 ; j < N; j++)
		{
			if (lista[i].CompareDates(lista[j]) != 1)
				Switch(lista[i], lista[j]);
		}
	}
	for (int i = 0; i < N; i++)
	{
		lista[i].ShowFunc();
	}
}