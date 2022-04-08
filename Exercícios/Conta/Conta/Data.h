#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class Data
{
private:
	int dia;
	int mes;
	int ano;
public:
	Data();
	Data(int dia, int mes, int ano);
	void SetDia(int dia) { this->dia = dia; }
	void SetMes(int mes) { this->mes = mes; }
	void SetAno(int ano) { this->ano = ano; }
	int GetDia() { return dia; }
	int GetMes() { return mes; }
	int GetAno() { return ano; }
	void Show();
	void Update(int dia, int mes, int ano);
	void Seguinte();
	bool Igual(Data d);
	bool operator==(Data d);
	bool operator!=(Data d);
	void operator=(Data d);
	friend ostream& operator<<(ostream& os, const Data& d);
	friend istream& operator>>(istream& is, Data& d);
	friend ifstream& operator>>(ifstream& ifs, Data& d);
	void ReadFile();
	void SaveFile();
};

