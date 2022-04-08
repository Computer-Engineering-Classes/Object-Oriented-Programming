#pragma once
#include <string>
#include "Data.h"

using namespace std;

class Pessoa
{
private:
	string nome;
	Data datan;
	string morada;
public:
	Pessoa();
	Pessoa(string nome, Data datan, string morada);
	void SetNome(string nome) { this->nome = nome; };
	void SetDatan(Data datan) { this->datan = datan; };
	void SetMorada(string morada) { this->morada = morada; };
	string GetNome() const { return nome; };
	Data GetDatan() const { return datan; };
	string GetMorada() const { return morada; };
	void Show();
	void ReadK();
	void MaisNovo(Pessoa p);
	void SaveFile(fstream& file);
	void ReadFile(fstream& file);
	friend ostream& operator<<(ostream& os, const Pessoa& p);
	friend istream& operator>>(istream& is, Pessoa& p);
	bool operator==(Pessoa p);
	bool operator!=(Pessoa p);
};

