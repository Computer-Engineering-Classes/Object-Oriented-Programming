#include "Conta.h"

Conta::Conta()
{
}

Conta::Conta(string nome, string morada, int numero_CC, float saldo, int dia, int mes, int ano)
	:titular(nome, morada, numero_CC), saldo(saldo), d_abertura(dia, mes, ano)
{
}

void Conta::Deposito(float valor)
{
	if (valor > 0)
	{
		saldo += valor;
	}
}

float Conta::Levantamento(float valor)
{
	float aux;
	if (valor > 0)
	{
		aux = saldo - valor;
		if (aux >= 0)
		{
			saldo = aux;
			return valor;
		}
		else
		{
			valor = saldo;
			saldo = 0;
			return valor;
		}
	}
	else
		return(0.0f);
}

void Conta::SaveFile(float valor)
{
	ofstream file;
	file.open("movimentosConta.txt");
	if (!file)
		cout << "Erro ao abrir o ficheiro." << endl;
	else
	{
		d_abertura.SaveFile(file);
		file << ';' << titular.Get_numero_CC() << ';' << valor << ";\n";
	}
	file.close();
}
Conta Conta::operator+(Conta C)
{
	Conta aux;
	if (*this == C)
	{
		if (d_abertura > C.d_abertura)
			aux.d_abertura = C.d_abertura;
		else
			aux.d_abertura = d_abertura;
		aux.titular = C.titular;
		aux.saldo = saldo + C.saldo;
		return aux;
	}
	else
		return (*this);
}

ostream& operator<<(ostream& os, Conta& conta)
{
	conta.titular.Show();
	os << "Cliente desde de: ";
	conta.d_abertura.Show();
	os << endl << "Saldo atual: " << conta.saldo << endl;
	return os;
}

bool Conta::operator==(Conta C)
{
	return (titular == C.titular /*&& d_abertura == C.d_abertura && saldo == C.saldo*/);
}