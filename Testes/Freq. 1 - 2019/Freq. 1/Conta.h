#pragma once
#include "Titular.h"
#include "Data.h"
#include <fstream>

class Conta
{
private:
	Titular titular; // composicao
	float saldo;
	Data d_abertura; // composicao
public:
	Conta();
	Conta(string nome, string morada, int numero_CC, float saldo, int dia, int mes, int ano);
	void Deposito(float valor);
	float Levantamento(float valor);
	void SaveFile(float valor);
	bool operator==(Conta C);
	Conta operator+(Conta C);
	friend ostream& operator<<(ostream& os, Conta& conta);
};

