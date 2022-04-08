#include "Funcionario.h"

Funcionario::Funcionario()
	:num_func(0), setor("")
{
}

Funcionario::Funcionario(string nome, Data datan, string morada, int num_func, string setor)
	:Pessoa(nome, datan, morada)
{
	this->num_func = num_func;
	this->setor = setor;
}

Funcionario::~Funcionario()
{
}

void Funcionario::SetNum_Func(int n)
{
	num_func = n;
}

void Funcionario::SetSetor(string s)
{
	setor = s;
}

void Funcionario::ShowFunc(void)
{
	Show();
	cout << "Número do funcionário: " << GetNum_Func() << endl;
	cout << "Setor da fábrica: " << GetSetor() << endl;
}

bool Funcionario::CompareDates(Funcionario f)
{
	if (GetDatan().GetAno() > f.GetDatan().GetAno())
		return 0;
	else if (GetDatan().GetAno() == f.GetDatan().GetAno() && GetDatan().GetMes() > f.GetDatan().GetMes())
		return 0;
	else if (GetDatan().GetAno() == f.GetDatan().GetAno() && GetDatan().GetMes() == f.GetDatan().GetMes() && GetDatan().GetDia() > f.GetDatan().GetDia())
		return 0;
	else
		return 1;
}

void Funcionario::SaveFile(fstream& file)
{
	Pessoa::SaveFile(file);
	file << GetNum_Func() << ';';
	file << GetSetor() << ';' << endl;
}

void Funcionario::ReadFile(fstream& file)
{
	int num;
	char c;
	string s;
	Pessoa::ReadFile(file);
	file >> num >> c;
	getline(file, s, ';');
	SetNum_Func(num);
	SetSetor(s);
}

void Switch(Funcionario& f1, Funcionario& f2)
{
	Funcionario aux;
	aux = f1;
	f1 = f2;
	f2 = aux;
}

istream& operator>>(istream& is, Funcionario& p)
{
	is >> (Pessoa&) p;
	cout << "Número do funcionário: ";
	is >> p.num_func;
	cout << "Setor: ";
	is >> p.setor;
	return is;
}
