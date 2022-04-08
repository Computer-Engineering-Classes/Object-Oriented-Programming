#include "Funcionario.h"

Funcionario::Funcionario()
	:num_func(0), setor(""), ord_base(0), h_extra(0), p_h_extra(0)
{
}

Funcionario::Funcionario(string nome, Data datan, string morada, int num_func, string setor, float ord_base, int h_extra)
{
	this->num_func = num_func;
	this->setor = setor;
	this->ord_base = ord_base;
	this->h_extra = h_extra;
}

Funcionario::~Funcionario()
{
}

void Funcionario::ShowFunc(void)
{
	Show();
	cout << "Número do funcionário: " << num_func << endl;
	cout << "Setor da fábrica: " << setor << endl;
	cout << "Ordenado base: " << ord_base << endl;
	cout << "N.º de horas extras: " << h_extra << endl;
}

void Funcionario::Ask2Set(void)
{
	ReadK();
	cout << "Número do funcionário: ";
	cin >> num_func;
	cout << "Setor da fábrica: ";
	cin >> setor;
	cout << "Ordenado base: ";
	cin >> ord_base;
	cout << "N.º de horas extras: ";
	cin >> h_extra;
}

bool Funcionario::CompareDates(Funcionario& f)
{
	if (GetDatan().GetAno() > f.GetDatan().GetAno())
		return 0;
	else if (GetDatan().GetAno() == f.GetDatan().GetAno() 
		&& GetDatan().GetMes() > f.GetDatan().GetMes())
		return 0;
	else if (GetDatan().GetAno() == f.GetDatan().GetAno()
		&& GetDatan().GetMes() == f.GetDatan().GetMes() 
		&& GetDatan().GetDia() > f.GetDatan().GetDia())
		return 0;
	else
		return 1;
}

void Switch(Funcionario* f1, Funcionario* f2)
{
	Funcionario *aux;
	aux = f1;
	f1 = f2;
	f2 = aux;
}

istream& operator>>(istream& is, Funcionario& p)
{
	p.ReadK();
	cout << "Número do funcionário: ";
	is >> p.num_func;
	cout << "Setor: ";
	is >> p.setor;
	return is;
}

void Funcionario::ReadFile(ifstream& file)
{
	char c;
	Pessoa::ReadFile(file);
	file >> num_func >> c;
	getline(file, setor, ';');
	file >> ord_base >> c >> h_extra;
}

void Funcionario::SaveFile(ofstream& file)
{
	Pessoa::SaveFile(file);
	file << num_func << ';';
	file << setor << ';';
	file << ord_base << ';';
	file << h_extra << ';';
}