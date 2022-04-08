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
	virtual void SaveFile(ofstream& file);
	virtual void ReadFile(ifstream& file);
	friend ostream& operator<<(ostream& os, const Pessoa& p);
	friend istream& operator>>(istream& is, Pessoa& p);
	bool operator==(Pessoa p);
	bool operator!=(Pessoa p);
};

