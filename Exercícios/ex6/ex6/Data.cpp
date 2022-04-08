#include "Data.h"
#include <iostream>
#include <fstream>

using namespace std;

Data::Data()
{
	dia = 0;
	mes = 0;
	ano = 0;
}

Data::Data(int dia, int mes, int ano)
{
	this->dia = dia;
	this->mes = mes;
	this->ano = ano;
}

void Data::Show()
{
	cout << dia << '/' << mes << '/' << ano << endl;
}

void Data::Update(int dia, int mes, int ano)
{
	this->dia = dia;
	this->mes = mes;
	this->ano = ano;
}

bool Data::Igual(Data d)
{
	return (dia == d.GetDia()) ? (mes == d.GetMes()) ? (ano == d.GetAno()) ? 1 : 0 : 0 : 0;
}

void Data::Ask2Set(void)
{
	cout << "Dia: ";
	cin >> dia;
	cout << "Mês: ";
	cin >> mes;
	cout << "Ano: ";
	cin >> ano;
}

bool Data::operator==(Data d)
{
	return (dia == d.GetDia()) ? (mes == d.GetMes()) ? (ano == d.GetAno()) ? 1 : 0 : 0 : 0;
}

bool Data::operator!=(Data d)
{
	return (dia == d.GetDia()) ? (mes == d.GetMes()) ? (ano == d.GetAno()) ? 0 : 1 : 1 : 1;

}

void Data::operator=(Data d)
{
	dia = d.GetDia();
	mes = d.GetMes();
	ano = d.GetAno();
}

void Data::ReadFile(ifstream& file)
{
	char c;
	file >> dia >> c >> mes >> c >> ano;
}

void Data::SaveFile(ofstream& file)
{
	file << dia << '/' << mes << '/' << ano << ';';
}

ostream& operator<<(ostream& os, const Data& d)
{
	os << d.dia << '/' << d.mes << '/' << d.ano;
	return os;
}

istream& operator>>(istream& is, Data& d)
{
	char c;
	is >> d.dia >> c >> d.mes >> c >> d.ano;
	return is;
}
