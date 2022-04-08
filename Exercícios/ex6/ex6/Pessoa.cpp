#include "Pessoa.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

Pessoa::Pessoa()
	:nome(""), datan(Data()), morada("")
{
}

Pessoa::Pessoa(string nome, Data datan, string morada)
{
	this->nome = nome;
	this->datan = datan;
	this->morada = morada;
}

void Pessoa::Show()
{
	cout << "Nome: " << nome << endl;
	cout << "Data de nascimento: " << datan << endl;
	cout << "Morada: " << morada << endl;
}

void Pessoa::ReadK()
{
	cout << endl << "Nome: ";
	cin.ignore();
	getline(cin, nome, '\n');
	cout << endl << "Data de nascimento: " << endl;
	datan.Ask2Set();
	cout << endl << "Morada: ";
	cin.ignore();
	getline(cin, morada);
}

void Pessoa::MaisNovo(Pessoa p)
{
	int i = 1; // 0 - p1 > p, 1 - p1 < p //
	if (datan.GetAno() > p.GetDatan().GetAno())
		i = 0;
	else if (datan.GetAno() == p.GetDatan().GetAno() && datan.GetMes() > p.GetDatan().GetMes())
		i = 0;
	else if (datan.GetAno() == p.GetDatan().GetAno() && datan.GetMes() == p.GetDatan().GetMes() && datan.GetDia() > p.GetDatan().GetDia())
		i = 0;
	switch (i)
	{
	case 0:
		cout << "O " << nome << " é mais novo(a)." << endl;
		Show();
		break;
	case 1:
		cout << "O " << p.GetNome() << " é mais novo(a)." << endl;
		p.Show();
		break;
	default:
		cout << "As pessoas têm a mesma idade." << endl;
	}
}

void Pessoa::SaveFile(ofstream& file)
{
	file << nome << ';';
	datan.SaveFile(file);
	file << morada << ';';
}

void Pessoa::ReadFile(ifstream& file)
{
	char c;
	getline(file, nome, ';');
	datan.ReadFile(file);
	file >> c;
	getline(file, morada, ';');
}

bool Pessoa::operator==(Pessoa p)
{
	return (nome == p.GetNome()) ? (datan == p.GetDatan()) ? 1 : 0 : 0;
}

bool Pessoa::operator!=(Pessoa p)
{
	return (nome == p.GetNome()) ? (datan == p.GetDatan()) ? 0 : 1 : 1;
}

ostream& operator<<(ostream& os, const Pessoa& p)
{
	os << "Nome: " << p.nome << endl << "Data de nascimento: " << p.datan << endl << "Morada: " << p.morada << endl;
	return os;
}

istream& operator>>(istream& is, Pessoa& p)
{
	cout << "Nome: ";
	getline(is, p.nome);
	cout << "Data de nascimento: ";
	is >> p.datan;
	cout << "Morada: ";
	is.ignore();
	getline(is, p.morada);
	return is;
}
