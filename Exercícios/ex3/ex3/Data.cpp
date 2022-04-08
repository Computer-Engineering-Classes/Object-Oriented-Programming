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

void Data::ReadFile(ifstream& f_r)
{
	f_r.open("save.txt");
	if (!f_r)
		cout << "Erro." << endl;
	else
		f_r >> dia >> mes >> ano;
	f_r.close();
}

void Data::SaveFile(ofstream& f_s)
{
	f_s.open("save.txt");
	f_s << dia << ' ' << mes << ' ' << ano;
	f_s.close();
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
