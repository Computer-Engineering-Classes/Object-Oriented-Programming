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
	string GetNome() { return nome; };
	Data GetDatan() { return datan; };
	string GetMorada() { return morada; };
	void Show();
	void ReadK();
	void MaisNovo(Pessoa p);
	void SaveFile();
	void ReadFile();
	vector<Pessoa> ReadVectorFile();
	friend ostream& operator<<(ostream& os, const Pessoa& p);
	friend istream& operator>>(istream& is, Pessoa& p);
	bool operator==(Pessoa p);
	bool operator!=(Pessoa p);

};

