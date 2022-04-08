#include "Conta.h"

Conta::Conta()
{
}

Conta::Conta(string novo_nome, long num)
	: nome(novo_nome), numero(num)
{
}

Conta::~Conta()
{
}

const string Conta::Get_nome(void) const
{
	return nome;
}

void Conta::Set_nome(string novo_nome)
{
	if (!novo_nome.empty())
		nome = novo_nome;
}

float Conta::Levanta(float quantia)
{
	
}
