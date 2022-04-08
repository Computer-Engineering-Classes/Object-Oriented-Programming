#include "Administrativo.h"

Administrativo::Administrativo()
{
	SetP_H_Extra(10);
}

Administrativo::Administrativo(string nome, Data datan, string morada, int num_func, string setor, float ord_base, int h_extra)
	:Funcionario(nome, datan, morada, num_func, setor, ord_base, h_extra)
{
	SetP_H_Extra(10);
}

Administrativo::~Administrativo()
{
}

float Administrativo::Calcula_ordenado(void)
{
	float ord;
	ord = GetOrd_Base() + GetH_Extra() * GetP_H_Extra();
	return ord;
}

void Administrativo::Ask2Set(void)
{
	Funcionario::Ask2Set();
}

void Administrativo::ReadFile(ifstream& file)
{
	char c;
	Funcionario::ReadFile(file);
	file >> c;
}

void Administrativo::SaveFile(ofstream& file)
{
	Funcionario::SaveFile(file);
}
