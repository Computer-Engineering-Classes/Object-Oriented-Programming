#pragma once
#include <iostream>
#include "Data.h"

using namespace std;

class Conta
{
private:
	string nome;
	string morada;
	long numero;
	float saldo;
	Data ultimo_mov;
public:
	Conta();
	Conta(string novo_nome, long num);
	virtual ~Conta();
	const string Get_nome(void) const;
	void Set_nome(string novo_nome);
	float Levanta(float quantia);
};

